/**
*  @file
*  @copyright defined in xmax/LICENSE
*/
#pragma once
#include <unitedb/dbtable.hpp>
#include <unitedb/undo.hpp>
namespace unitedb
{
	template<typename T>
	struct UndoObject : protected T
	{
	public:
		typedef T ObjectType;
		typedef T Super;
		typedef DBAlloc< ObjectType > AllocType;

		UndoObject(const AllocType& cc)
			: Super(cc)
			, revision(0)
			, opcode(UndoOp::None)
		{

		}

		void Set(const ObjectType& data, UndoRevision v, UndoOp::UndoCode c)
		{
			*static_cast<Super*>(this) = data;
			revision = v;
			opcode = c;
		}

		const ObjectType& Object() const
		{
			return *((ObjectType*)this);
		}


		inline UndoOp::UndoCode GetUndoCode() const
		{
			return opcode;
		}
		inline ObjIDCode ObjID() const
		{
			return DBObjBase::__getObjidcode(*this);
		}

	protected:
		UndoOp::UndoCode opcode;
		UndoRevision revision;
	};

	class TableUndoStack
	{

	};


	template<typename T>
	class FTable : public T,  public ITable
	{
	public:
		typedef typename T DBTableType;
		typedef typename DBTableType::ObjectType ObjectType;
		typedef typename FTable<DBTableType> SelfType;
		typedef typename DBTableType::MappedPtr MappedPtr;

		typedef UndoObject<ObjectType> UndoObjectType;
		typedef MappedUndo<UndoObjectType> UndoCacheType;

		typedef typename DBTableType Super;

		FTable(IDatabase* owner, MappedPtr p)
			: owner_(owner)
			, Super(p)
		{
			std::string type_name = boost::core::demangle(typeid(SelfType).name()) + "UndoCache";

			cache_ = owner_->GetMappdFile()->find_or_construct< UndoCacheType >(type_name.c_str()) (UndoCacheType::AllocType(owner_->GetSegmentManager()));
		}

		inline const ObjectType* AsObject(const DBObjBase* base)
		{
			return static_cast<const ObjectType*>(base);
		}

		virtual IDBTable* GetDBTable() const override
		{
			return const_cast<SelfType*>(this);
		}

		virtual void PushUndo(UndoOp::UndoCode code, const DBObjBase* undo) override
		{
			pushUndoImpl(code, undo);
		}

		virtual void LastUpdateFailure(ObjIDCode id) override
		{
			if (noUndo())
			{
				BOOST_ASSERT(cache_->GetBack().GetUndoCode() == UndoOp::Update);
				if (cache_->GetBack().ObjID() == id)
				{
					cache_->PopBack();
				}
				owner_->LastUpdateFailure(id);
				return;
			}
		}

		virtual void SetUndo(bool set)
		{
			no_undo_ = !set;
		}

		virtual void Undo(const UndoOp& op) override
		{
			undoImpl(op);
		}

	protected:

		inline bool noUndo() const
		{
			return no_undo_;
		}

		void pushUndoImpl(UndoOp::UndoCode code, const DBObjBase* undo)
		{
			if (noUndo())
			{
				return;
			}

			switch (code)
			{
			case unitedb::UndoOp::Create:
			{
				owner_->PushUndo(UndoOpArg(code, DBObjBase::__getObjidcode(*undo), ObjectType::TypeCode));
			}
			break;
			case unitedb::UndoOp::Update:
			case unitedb::UndoOp::Delete:
			{
				pushUndoObject(undo, owner_->TopRevision(), code);
				owner_->PushUndo(UndoOpArg(code, DBObjBase::__getObjidcode(*undo), ObjectType::TypeCode));
			}
			break;
			default:
				break;
			}
		}
		void undoImpl(const UndoOp& op)
		{
			switch (op.op_)
			{
			case UndoOp::Create:
			{
				auto itr = GetMapped().find(op.id_);
				GetMapped().erase(itr);
			}
			break;
			case UndoOp::Update:
			{
				auto itr = GetMapped().find(op.id_);
				GetMapped().replace(itr, getBackObject());
				cache_->PopBack();
			}
			break;
			case UndoOp::Delete:
			{
				GetMapped().emplace(getBackObject());
				cache_->PopBack();
			}
			break;

			default:
				break;
			}
		}

		void pushUndoObject(const DBObjBase* undo, UndoRevision v, UndoOp::UndoCode c)
		{
			cache_->EmplaceBack().Set(*AsObject(undo), v, c);
		}

		const ObjectType& getBackObject() const
		{
			return cache_->GetBack().Object();
		}

		bool no_undo_ = true;
		UndoCacheType* cache_;
		IDatabase * owner_ = nullptr;
	};
}
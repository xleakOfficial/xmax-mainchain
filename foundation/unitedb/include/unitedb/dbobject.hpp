/**
*  @file
*  @copyright defined in xmax/LICENSE
*/
#pragma once
#include <unitedb/dbtypes.hpp>
#include <boost/multi_index_container.hpp> 
#include <boost/multi_index/ordered_index.hpp> 
#include <boost/multi_index/member.hpp>

namespace unitedb
{
	using ObjectIDCode = int64_t;
	using ObjectTypeCode = uint16_t;


	class DBObjectBase
	{
	public:
		ObjectIDCode id_ = 0;
	};

	template<typename _Obj>
	class ObjectID
	{
	public:
		ObjectID(ObjectIDCode i = 0) :val_(i) {}

		ObjectID& operator++() 
		{ 
			++val_; 
			return *this; 
		}

		friend bool operator < (const ObjectID& a, const ObjectID& b) { return a.val_ < b.val_; }
		friend bool operator > (const ObjectID& a, const ObjectID& b) { return a.val_ > b.val_; }
		friend bool operator == (const ObjectID& a, const ObjectID& b) { return a.val_ == b.val_; }
		friend bool operator != (const ObjectID& a, const ObjectID& b) { return a.val_ != b.val_; }
		friend std::ostream& operator<<(std::ostream& s, const ObjectID& id) {
			s << boost::core::demangle(typeid(ObjectID<T>).name()) << '(' << id.val_ << ')'; return s;
		}

		ObjectIDCode val_ = 0;
	};

	template<typename _Obj, ObjectTypeCode _Type>
	class DBObject : public DBObjectBase
	{
	public:
		typedef ObjectID<_Obj> TypeID;
		DBObject() = default;
		template<typename T>
		DBObject(DBAlloc<T>)
		{

		}

		TypeID GetID() const
		{
			return TypeID(id_);
		}

		static const ObjectTypeCode TypeCode = _Type;
	};


	template<typename T>
	class ObjPtr
	{
	public:
		const T * operator ->() const
		{
			return ptr;
		}
		explicit operator bool() const
		{
			return ptr != nullptr;
		}

		const T& Get() const
		{
			return *ptr;
		}

		static ObjPtr<T> MakePtr(const T* p)
		{
			return ObjPtr<T>(p);
		}
	private:

		ObjPtr() = default;

		ObjPtr(const T* p)
			: ptr(p)
		{
		}

		const T * ptr = nullptr;
	};


}


#define DBOBJECT_CLASS(_objname, _typecode )\
class _objname : public unitedb::DBObject<_objname, _typecode>

#define DBOBJECT_CLASS_END() };
//@file
//@copyright defined in xmax/LICENSE
#include "script_module.hpp"
#include "script_global_module.hpp"
#include <libplatform/libplatform.h>

namespace xmax {

	namespace scriptv8 {
		
		ScriptMoudle::ScriptMoudle()
			:current_code_()
			,main_foo_()
			,instruction_count_(0)
			,last_intruction_()
		{

		}

		ScriptMoudle::~ScriptMoudle()
		{

		}

		void ScriptMoudle::EnterContext()
		{
			EnterJsContext(ScriptGlobalMoudle::GetInstance().GetIsolate(), current_context_);
		}

		v8::Object* CallBackCheck(int args_length, v8::Object** args_object, v8::Isolate* isolate) {
		
			void* arg1 = *(reinterpret_cast<v8::Object**>(reinterpret_cast<intptr_t>(args_object) - 1 * sizeof(int)));

			int value = (int)arg1;

			return args_object[0];
		}


		void ScriptMoudle::LoadScript(const char* code)
		{
			current_context_ = CreateJsContext(ScriptGlobalMoudle::GetInstance().GetIsolate(), *ScriptGlobalMoudle::GetInstance().GetGlobalObjTemplate());
			EnterJsContext(ScriptGlobalMoudle::GetInstance().GetIsolate(), current_context_);
			CompileJsCode(ScriptGlobalMoudle::GetInstance().GetIsolate(), current_context_.Get(ScriptGlobalMoudle::GetInstance().GetIsolate()), code);
		}

		void ScriptMoudle::RunFoo(const char* foo)
		{
			
			Local<Context> context = current_context_.Get(ScriptGlobalMoudle::GetInstance().GetIsolate());
			Handle<v8::Value> params[2];
		
			CallJsFoo(ScriptGlobalMoudle::GetInstance().GetIsolate(), context, foo, 0, NULL);
		}

		void ScriptMoudle::ExitContext()
		{
			ExitJsContext(ScriptGlobalMoudle::GetInstance().GetIsolate(), current_context_);
		}

		void ScriptMoudle::StoreInstrunction(int ins)
		{
			instruction_count_++;
			last_intruction_.push_back(ins);
		}

		void ScriptMoudle::CleanInstrunction()
		{
			instruction_count_ = 0;
			last_intruction_.clear();
		}



	}
}



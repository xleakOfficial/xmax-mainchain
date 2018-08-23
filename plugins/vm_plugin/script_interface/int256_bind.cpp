#include "int256_bind.hpp"
//imp



using namespace v8;


namespace xmax {
	namespace scriptv8 {

		V8i256* V8i256::NewV8CppObj(const v8::FunctionCallbackInfo<v8::Value>& args)
		{
			return new V8i256();
		}

		void V8i256::RegisterWithV8(v8::Isolate* isolate, v8::Handle<v8::ObjectTemplate> global)
		{

		}

		void V8i256::ConstructV8Object(const v8::FunctionCallbackInfo<v8::Value>& args)
		{
			if (!args.IsConstructCall())
				return args.GetReturnValue().Set(Undefined(args.GetIsolate()));
			V8i256* cpp_object = nullptr;
			if (args.Length() == 1)
			{
				Local<Object> self = args.Holder();
				Local<External> wrap = Local<External>::Cast(args[0]);
				cpp_object = (V8i256*)wrap->Value();
			}
			else
			{
				NewV8CppObj(args);
			}

		
		}

		void V8i256::WeakExternalReferenceCallback(const v8::WeakCallbackInfo<V8i256>& data)
		{
			if (V8i256* cpp_object = data.GetParameter())
			{
				delete cpp_object;
			}
		}

	}
}
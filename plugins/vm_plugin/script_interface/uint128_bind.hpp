//@file
//@copyright defined in xmax/LICENSE
#pragma once
#include <functional>
#include <map>
#include <libplatform/libplatform.h>
#include <v8.h>
#include "V8BindObject.hpp"
#include "pro/types/generictypes.hpp"

namespace xmax {
	namespace scriptv8 {
		class V8u128 : public V8BindObject<V8u128>
		{
		public:
			V8u128(pro::uint128 value) :value_(value) {}

			V8u128() :value_(0) {}

			operator pro::uint128() { return value_; }


			//V8 bind
			static constexpr inline const char* TypeName() {
				return "V8u128";
			}

			static V8u128* NewV8CppObj(const v8::FunctionCallbackInfo<v8::Value>& args);
			static void RegisterWithV8(v8::Isolate* isolate, v8::Handle<v8::ObjectTemplate> global);
			static void ConstructV8Object(const v8::FunctionCallbackInfo<v8::Value>& args);
			static void WeakExternalReferenceCallback(const v8::WeakCallbackInfo<V8u128>& data);

		private:
			pro::uint128 value_;
		};


	}
}
#pragma once

#include "Macro.h"
#include <ghstl/string>
#include <map>

namespace NKHook5 {
	namespace Classes {
		using namespace NKHook5;
		using namespace NKHook5::Classes;
		using namespace NKHook5::Signatures;

		class JsonPropertyValue {
		public:
			uint32_t jsonValueType; //0x0028
			uint32_t pad_002C; //0x002C
			union
			{
				bool boolValue; //0x0000
				int8_t byteValue; //0x0000
				int16_t shortValue; //0x0000
				int32_t intValue; //0x0000
				int64_t int64Value; //0x0000
				float floatValue; //0x0000
				double doubleValue; //0x0000
				ghstl::string stringValue; //0x0000
				std::map<std::string, JsonPropertyValue>* jsonValue; //0x0000
			} value;
		public:
		};

		class JsonObject {
		public:
			class std::map<std::string, JsonPropertyValue>* dataMap; //0x0000
			char pad_0004[4]; //0x0004
		public:
			uint32_t ReadBoolProperty(bool* result, ghstl::string propName) {
				return ThisCall<uint32_t, JsonObject*, bool*, ghstl::string>(Sigs::JsonObject_ReadBoolProperty, this, result, propName);
			}
		};
	}
}
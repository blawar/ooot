#pragma once
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/prettywriter.h"
#include <rapidjson/istreamwrapper.h>

namespace oot::json
{
	bool save(rapidjson::Document& doc, const std::string& jsonFilePath);
	void set(rapidjson::Value& document, const char* key, const std::string& value, rapidjson::Document::AllocatorType& alloc);
	void set(rapidjson::Value& document, const char* key, rapidjson::Value& value, rapidjson::Document::AllocatorType& alloc);
	void set(rapidjson::Value& document, const char* key, int value, rapidjson::Document::AllocatorType& alloc);
	void setU64(rapidjson::Value& document, const char* key, u64 value, rapidjson::Document::AllocatorType& alloc);
	void setBool(rapidjson::Value& document, const char* key, bool value, rapidjson::Document::AllocatorType& alloc);
	void setFloat(rapidjson::Value& document, const char* key, float value, rapidjson::Document::AllocatorType& alloc);

	bool get(rapidjson::Value& document, const char* key, std::string& value);
	bool getU64(rapidjson::Value& document, const char* key, u64& value);
	bool getBool(rapidjson::Value& document, const char* key, bool& value);
	bool getFloat(rapidjson::Value& document, const char* key, float& value);
}


#include "ultra64/types.h"
#include "json.h"
#include <fstream>

namespace oot::json
{
	void set(rapidjson::Value& document, const char* key, const std::string& value, rapidjson::Document::AllocatorType& alloc)
	{
		rapidjson::Value _key(key, alloc);
		document.AddMember(_key, rapidjson::Value(value.c_str(), value.length(), alloc), alloc);
	}

	void set(rapidjson::Value& document, const char* key, rapidjson::Value& value, rapidjson::Document::AllocatorType& alloc)
	{
		rapidjson::Value _key(key, alloc);
		document.AddMember(_key, value, alloc);
	}

	void set(rapidjson::Value& document, const char* key, int value, rapidjson::Document::AllocatorType& alloc)
	{
		rapidjson::Value v;
		v.SetInt(value);

		rapidjson::Value _key(key, alloc);
		document.AddMember(_key, v, alloc);
	}

	void setU64(rapidjson::Value& document, const char* key, u64 value, rapidjson::Document::AllocatorType& alloc)
	{
		rapidjson::Value v;
		v.SetUint64(value);

		rapidjson::Value _key(key, alloc);
		document.AddMember(_key, v, alloc);
	}

	void setFloat(rapidjson::Value& document, const char* key, float value, rapidjson::Document::AllocatorType& alloc)
	{
		rapidjson::Value v;
		v.SetFloat(value);

		rapidjson::Value _key(key, alloc);
		document.AddMember(_key, v, alloc);
	}

	void setBool(rapidjson::Value& document, const char* key, bool value, rapidjson::Document::AllocatorType& alloc)
	{
		rapidjson::Value v;
		v.SetBool(value);

		rapidjson::Value _key(key, alloc);
		document.AddMember(_key, v, alloc);
	}

	bool get(rapidjson::Value& document, const char* key, std::string& value)
	{
		if(!document.IsObject())
		{
			return false;
		}

		if(!document.HasMember(key))
		{
			return false;
		}

		auto& v = document[key];

		if(!v.IsString())
		{
			return false;
		}

		value = v.GetString();
		return true;
	}

	bool getU64(rapidjson::Value& document, const char* key, u64& value)
	{
		if(!document.IsObject())
		{
			return false;
		}

		if(!document.HasMember(key))
		{
			return false;
		}

		auto& v = document[key];

		if(!v.IsUint64())
		{
			return false;
		}

		value = v.GetUint64();
		return true;
	}

	bool getBool(rapidjson::Value& document, const char* key, bool& value)
	{
		if(!document.IsObject())
		{
			return false;
		}

		if(!document.HasMember(key))
		{
			return false;
		}

		auto& v = document[key];

		if(!v.IsBool())
		{
			return false;
		}

		value = v.GetBool();
		return true;
	}

	bool getFloat(rapidjson::Value& document, const char* key, float& value)
	{
		if(!document.IsObject())
		{
			return false;
		}

		if(!document.HasMember(key))
		{
			return false;
		}

		auto& v = document[key];

		if(!v.IsFloat())
		{
			return false;
		}

		value = v.GetFloat();
		return true;
	}

	bool save(rapidjson::Document& doc, const std::string& jsonFilePath)
	{
		rapidjson::StringBuffer buffer;
		rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buffer);

		if(!doc.Accept(writer))
		{
			return false;
		}

		std::ofstream out(jsonFilePath.c_str(), std::ofstream::trunc);
		out << buffer.GetString();

		return true;
	}
} // namespace oot::json

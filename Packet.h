#pragma once
#include <rapidjson/document.h>
#include <string>

//abstract class (C++ interface ¾øÀ½)
class IPacket
{
public:
	virtual void Parse(std::string JsonString) = 0;
	virtual std::string ToJsonString() = 0;
	virtual int Length() = 0;

	rapidjson::Document JsonDocument;
};


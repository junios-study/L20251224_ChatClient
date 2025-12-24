#define _CRT_SECURE_NO_WARNINGS

#include "ChatPacket.h"
#include <sstream>

std::string ChatPacket::ToJsonString()
{
	std::stringstream Stream;

	Stream << "{";
	Stream << "\"UserName\" : ";
	Stream << "\"" << UserName << "\"";
	Stream << ", ";
	Stream << "\"Message\" : ";
	Stream << "\"" << Message << "\"";
	Stream << ", ";
	Stream << "\"Gold\" : ";
	Stream << Gold;
	Stream << "}";

	//JsonDocument.SetObject();
	//JsonDocument.AddMember("UserName", UserName, JsonDocument.GetAllocator());
	//JsonDocument.AddMember("Message", Message, JsonDocument.GetAllocator());
	//JsonDocument.AddMember("Gold", Gold, JsonDocument.GetAllocator());

	//rapidjson::StringBuffer Buffer;
	//rapidjson::Writer<rapidjson::StringBuffer> writer(Buffer);
	//JsonDocument.Accept(writer);

	return Stream.str();
}

void ChatPacket::Parse(std::string JsonString)
{
	JsonDocument.Parse(JsonString.c_str());

	UserName = JsonDocument["UserName"].GetString();
	Message = JsonDocument["Message"].GetString();
	Gold = JsonDocument["Gold"].GetInt();
}

int ChatPacket::Length()
{
	return (int)ToJsonString().length();
}

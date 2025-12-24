#define _CRT_SECURE_NO_WARNINGS

#include "ChatPacket.h"

std::string ChatPacket::ToJsonString()
{
	JsonDocument.SetObject();
	JsonDocument.AddMember("UserName", UserName, JsonDocument.GetAllocator());
	JsonDocument.AddMember("Message", Message, JsonDocument.GetAllocator());
	JsonDocument.AddMember("Gold", Gold, JsonDocument.GetAllocator());

	rapidjson::StringBuffer Buffer;
	rapidjson::Writer<rapidjson::StringBuffer> writer(Buffer);
	JsonDocument.Accept(writer);

	return Buffer.GetString();
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

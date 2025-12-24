#include "ChatPacket.h"

std::string ChatPacket::ToJsonString()
{
	std::string Temp = "";
	Temp = "{ \"UserName\" : ";
	Temp = Temp + " \"" + UserName + "\", ";
	Temp = Temp + " \"Message\" : ";
	Temp = Temp + " \"" + Message + "\" }";

	return Temp;
}

void ChatPacket::Parse(std::string JsonString)
{
	JsonDocument.Parse(JsonString.c_str());

	UserName = JsonDocument["UserName"].GetString();
	Message = JsonDocument["Message"].GetString();
}

int ChatPacket::Length()
{
	return (int)ToJsonString().length();
}

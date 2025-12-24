#pragma once

#define RAPIDJSON_HAS_STDSTRING 1

#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <string>

#include "Packet.h"




class ChatPacket : public IPacket
{
public:
	std::string UserName;
	std::string Message;
	int Gold;

	virtual std::string ToJsonString() override;

	virtual void Parse(std::string JsonString) override;

	virtual int Length() override;


};


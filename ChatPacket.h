#pragma once

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

	virtual std::string ToJsonString() override;

	virtual void Parse(std::string JsonString) override;

	virtual int Length() override;


};


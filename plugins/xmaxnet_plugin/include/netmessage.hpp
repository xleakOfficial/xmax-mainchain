#pragma once

#include "pro/utils/singleton.hpp"

namespace google
{
	namespace protobuf
	{
		class Message;
	}
}

namespace xmax
{
	enum MsgId
	{
		MSG_TEST = 0,
	};

	struct MsgHeader
	{
		unsigned char	id;
		unsigned int	msgLength;

		MsgHeader()
			: id(0),
			  msgLength(0)
		{

		}
	};

	struct NetMessage
	{
		MsgHeader header;
		google::protobuf::Message *pMsg;
	};

	class NetMessasgeHandler : public pro::Singleton<NetMessasgeHandler>
{
public:

	void HandleMessage(const char* pMsg, const MsgHeader& header);

protected:
private:
};


}
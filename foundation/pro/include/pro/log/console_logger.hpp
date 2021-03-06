/**
*  @file
*  @copyright defined in xmax/LICENSE
*/

#pragma once
#include <pro/log/log_base.hpp>

namespace pro
{

	class ConsoleLogger : public ILogger
	{
	public:
		virtual void LogMessage(LogLevel level, const string& msg) override;
	};
}
/**
*  @file
*  @copyright defined in xmax/LICENSE
*/

#include <vector>
#include <memory>
#include <pro/log/console_logger.hpp>
#include <pro/log/log_system.hpp>

namespace pro
{
	static const string LineCode = "\r\n";

	static string LogFileName;// = "home:game.log";
	static const string string_log = "log: ";
	static const string string_warning = "warning: ";
	static const string string_error = "error: ";


	class LogSystemImpl
	{
	public:
		typedef std::vector<LoggerPtr> Loggers;

		void Append(LoggerPtr logger)
		{
			if (!Contain(logger.get()))
			{
				loggers_.push_back(logger);
			}
		}
		void Remove(LoggerPtr logger)
		{
			auto it = Find(logger.get());
			if (it != loggers_.end())
			{
				loggers_.erase(it);
			}
		}

		Loggers::const_iterator Find(ILogger* logger) const
		{
			for (Loggers::const_iterator it = loggers_.begin(); it != loggers_.end(); ++ it)
			{
				if ((*it).get() == logger)
				{
					return it;
				}
			}
			return loggers_.end();
		}

		bool Contain(ILogger* logger) const
		{
			return Find(logger) != loggers_.end();
		}

		void LogMessage(loglevel level, const string& msg)
		{
			string u8;
			switch (level)
			{
			case loglevel::Info:
			{
				u8 = string_log;
				break;
			}
			case loglevel::Warnning:
			{
				u8 = string_warning;
				break;
			}
			case loglevel::Error:
			{
				u8 = string_error;
				break;
			}
			default:
			{
				break;
			}
			}

			u8 += msg;
			u8 += LineCode;
			
			for ( auto& logger : loggers_)
			{
				logger->LogMessage(level, u8);
			}
		}


		Loggers loggers_;
	};


	LogSystem::LogSystem()
		: impl_(std::make_unique<LogSystemImpl>())
	{
		Append<ConsoleLogger>();
	}
	LogSystem::~LogSystem()
	{

	}
	void LogSystem::Append(LoggerPtr logger)
	{
		impl_->Append(logger);
	}
	void LogSystem::Remove(LoggerPtr logger)
	{
		impl_->Remove(logger);
	}

	void LogSystem::LogMessage(loglevel level, const string& msg)
	{
		impl_->LogMessage(level, msg);
	}

}
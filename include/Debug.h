#pragma once

#include "SoftCores/Util/Logger.h"
#include <format>

enum class	LogLevel
{
	Error,
	Warn,
	Info,
	Debug,
};

constexpr const char	*LogLevelStrings[] =
{
	"[ERROR] ",
	"[WARN ] ",
	"[INFO ] ",
	"[DEBUG] "
};

constexpr bool	operator>(LogLevel left, LogLevel right)
{
	return (static_cast<int>(left) > static_cast<int>(right));
}

constexpr bool	operator<(LogLevel left, LogLevel right)
{
	return (static_cast<int>(left) < static_cast<int>(right));
}

class Debug
{
	static SoftCores::Util::Logger	*Logger;

public:
	// Keep up to date with amount of LogLevels, start at 0.
	static constexpr int	LogLevelCount = 3;
	static LogLevel			LogLevel;

	template <typename... Args>
	static void	Log(enum LogLevel logLevel, std::format_string<Args...> &&message, Args&&... args)
	{
		if (logLevel > LogLevel)
			return ;
		Log(static_cast<int>(logLevel), message, std::forward<Args>(args)...);
	}
	template <typename... Args>
	static void	Log(const int logLevel, std::format_string<Args...> &&message, Args&&... args)
	{
		if (static_cast<enum LogLevel>(logLevel) > LogLevel)
			return ;
		return (Logger->Write(LogLevelStrings[logLevel] +
			std::format(message, std::forward<Args>(args)...), true));
	}
	static void	SetLogger(SoftCores::Util::Logger &logger);
};

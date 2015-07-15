
#pragma once

#include <string>
#include <stdexcept>
#include <spdlog/spdlog.h>

class SystemExit : public std::runtime_error
{
	int _retcode;
	std::string _msg;
public:

	SystemExit(int retcode, std::string msg = "")
	: std::runtime_error(fmt::format("exit exception({}): {}", retcode, msg))
	{
		_retcode = retcode;
		_msg = msg;
	}

	SystemExit(std::string msg) : SystemExit(1, msg){}

	int code() const
	{
		return _retcode;
	}

	const std::string & msg() const
	{
		return _msg;
	}
};

struct UsageExit : public SystemExit
{
	using SystemExit::SystemExit;
};


class EnforceEx : public std::runtime_error
{
public:
	EnforceEx(const char * cond, const char * file, int line, std::string msg = "")
	: std::runtime_error(fmt::format("enforcement failed ({}): {} @{}:{}", cond, msg, file, line))
	{
	}
};

class NotImplementedEx : public std::runtime_error
{
public:
	NotImplementedEx(const char * func, const char * file, int line)
	: std::runtime_error(fmt::format("not implemented function {} @{}:{}", func, file, line))
	{
	}
};

template<typename Except = std::runtime_error, typename... Args>
void enforce(bool condition, Args... args)
{
	if(!condition)
	{
		throw Except(args...);
	}
}

#define ENFORCE(cond, ...) \
	enforce<EnforceEx>(cond, #cond, __FILE__, __LINE__, ## __VA_ARGS__)

#define NOT_IMPLEMENTED() throw NotImplementedEx(__PRETTY_FUNCTION__, __FILE__, __LINE__);

#pragma once
#include <exception>
#include <string>

class myexception : public std::exception
{
public:
	myexception(const char* message) :exception(message)
	{
		m_Message = message;
	}

	virtual const char* what() const throw()
	{
		return m_Message.c_str();
	}

private:
	std::string m_Message;
};


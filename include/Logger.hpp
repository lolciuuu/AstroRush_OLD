#ifndef LOGGER_HPP
#define LOGGER_HPP
#include "Headers.hpp"

class Logger {
public:
	Logger( string className );

	void methodStart( string methodName );

	void methodEnd( string methodName );

	void info( string Str );

	void warring( string Str );

	void error( string Str );

	void critical( string Str );

	void initTimer();

private:
	string className;

private:
	static string LOGS;

};

#endif

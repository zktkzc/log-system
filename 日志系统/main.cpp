#include <iostream>
#include "Logger.h"

int main() {
	utility::Logger::Instance()->Open("./test.log");
	utility::Logger::Instance()->Max(200);
	Debug("hello world");
	Info("name is %s, age is %d", "jack", 18);
	Error("error message");
	Warn("warn message");
	return 0;
}

#pragma once
#include <fstream>
#include <string>

#define Debug(format, ...) \
	utility::Logger::Instance()->Log(utility::Logger::DEBUG, __FILE__, __LINE__, format, ##__VA_ARGS__)

#define Info(format, ...) \
	utility::Logger::Instance()->Log(utility::Logger::INFO, __FILE__, __LINE__, format, ##__VA_ARGS__)

#define Warn(format, ...) \
	utility::Logger::Instance()->Log(utility::Logger::WARN, __FILE__, __LINE__, format, ##__VA_ARGS__)

#define Error(format, ...) \
	utility::Logger::Instance()->Log(utility::Logger::ERROR, __FILE__, __LINE__, format, ##__VA_ARGS__)

#define Fatal(format, ...) \
	utility::Logger::Instance()->Log(utility::Logger::FATAL, __FILE__, __LINE__, format, ##__VA_ARGS__)

namespace utility {
	class Logger
	{
	public:
		enum Level {
			DEBUG = 0,
			INFO,
			WARN,
			ERROR,
			FATAL,
			LEVEL_COUNT
		};

		static Logger* Instance();
		void Open(const std::string& filename);
		void Close();
		void Log(Level level, const char* file, int line, const char* format, ...);
		void SetLevel(Level level)
		{
			m_level = level;
		}
		void Max(int bytes)
		{
			m_max = bytes;
		}

	private:
		Logger();
		~Logger();
		void Rotate();

	private:
		std::string m_filename;
		std::ofstream m_fout;
		Level m_level;
		int m_max;
		int m_len;
		static const char* s_level[LEVEL_COUNT];
		static Logger* m_instance;
	};
}


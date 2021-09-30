#pragma once

class Log {
public:
	void SetLevel(int level);

	static void Error(const char* message);

	static void Warn(const char* message);

	static void Info(const char* message);
};


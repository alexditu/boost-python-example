#include <log.h>

LoggerInitializer gLoggerInitializer;

int main(/*int argc, char** argv*/)
{
	try {
		logD("TODO");
	} catch (const std::exception& e) {
		logE("exception: {}", e.what());
	} catch (...) {
		logE("exception: unknown");
	}

	return 0;
}
#ifndef __LOG_H_INCLUDED__
#define __LOG_H_INCLUDED__

#include <spdlog/spdlog.h>

#define logD spdlog::debug
#define logW spdlog::warn
#define logE spdlog::error

struct LoggerInitializer {
	LoggerInitializer() {
		spdlog::set_level(spdlog::level::trace);
	}
};

#endif // __LOG_H_INCLUDED__
//
// Created by alex on 5/25/21.
//

#include "Logger.h"

#include <chrono>

Logger::Logger(std::string string) :
logger(string)
{
}

void Logger::log(std::string message) {
    time_t timp = time(NULL);
    logger << message << " " << ctime(&timp);
}

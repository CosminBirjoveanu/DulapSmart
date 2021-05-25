//
// Created by alex on 5/25/21.
//

#ifndef SMARTDROBE_LOGGER_H
#define SMARTDROBE_LOGGER_H


#include <fstream>

class Logger {

    private:
    std::ofstream logger;
public:
    Logger(std::string);
    void log(std::string);
};


#endif //SMARTDROBE_LOGGER_H

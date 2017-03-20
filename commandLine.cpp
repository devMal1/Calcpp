#include "CommandLine.h"
#include <iostream>

CommandLine::CommandLine() {}

CommandLine::~CommandLine() {}

void CommandLine::write(const std::string &message) const {
    std::cout << message << std::endl << LINE_FIRST_CHAR;
}

std::string CommandLine::read() const {
    std::string message;
    getline(std::cin, message);
    return message;
}

std::string CommandLine::prompt(const std::string &message) const {
    write(message);
    return read();
}
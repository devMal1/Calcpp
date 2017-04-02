#include "calcCommandParser.h"

CalcCommandParser::~CalcCommandParser() {}

bool CalcCommandParser::isValidCommand(std::string input) {
    return true;
}

std::string CalcCommandParser::parse(std::string input) {
    if (!isValidCommand(input) {
        return "";
    }

    return input;
}
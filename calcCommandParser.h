#pragma once

#include "calcCommand.h"
#include <string>
#include <vector>

class CalcCommandParser {
    private:
    bool isValidOperation(const std::string &op) const;
    bool isValidArguments(const std::vector<std::string> &op) const;
    std::string extractTokens(const std::string &input) const;
    std::vector<string> extractArguments(const std::vector<string> &args) const;

    public:
    CalcCommandParser();
    ~CalcCommandParser();
    CalcCommand parse(const std::string &input) const;
    static char DELIMITER = ' ';
    static int OP_INDEX = 0;
    static std::vector<string> COMMANDS{ "add", "sub", "mult", "div" }; //TODO check cplusplus for sets!
};
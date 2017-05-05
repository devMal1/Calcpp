#pragma once

#include "../Command/calcCommand.h"
#include <string>
#include <vector>

class CalcCommandParser {
    private:
    bool isValidOperation(const std::string &op) const;
    bool isValidArguments(const std::vector<std::string> &op) const;
    std::vector<std::string> extractTokens(const std::string &input, char delimiter) const;
    std::string extractOperation(const std::vector<std::string> &tokens) const;
    std::vector<int> extractArguments(const std::vector<std::string> &args) const;

    public:
    CalcCommandParser();
    ~CalcCommandParser();
    CalcCommand parse(const std::string &input) const;
    static const char DELIMITER;
    static const int OP_INDEX;
    static const std::vector<std::string> COMMANDS; //TODO check cplusplus for sets!
};
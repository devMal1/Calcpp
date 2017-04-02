#pragma once

#inlcude "parser.h"
#include <string>

class CalcCommandParser : public Parser {
    private:
    bool isValidCommand(std::string input);

    public:
    using Parser::Parser;
    ~CalcCommandParser();
    std::string parse(std::string input);
};
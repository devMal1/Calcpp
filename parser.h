#pragma once

#include <string>

class Parser {
    private:
    
    public:
    Parser();
    ~Parser();
    virtual std::string parse(std::string input);
};
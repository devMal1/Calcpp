#pragma once

#include <string>
#include <vector>

class Parser {
    private:
    
    public:
    Parser();
    virtual ~Parser();
    std::string extractTokens(const std::string &input, const std::string &delimiter) const;
    virtual std::string parse(const std::string &input) = 0;
};
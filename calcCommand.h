#pragma once

#include <string>
#include <vector>

class CalcCommand {
    private:
    std::string operation;
    std::vector<int> arguments;

    public:
    CalcCommand();
    CalcCommand(const std::string &op, const std::vector<int> &args);
    ~CalcCommand();
    std::string getOperation() const;
    std::vector<int> getArguments() const;
    bool commandless() const;
    static std::string NO_OP = "";
};
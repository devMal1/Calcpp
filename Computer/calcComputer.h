#pragma once

#include "../Command/calcCommand.h"

class CalcComputer {
    private:
    int reduce(const std::vector<int> &nums, int (*reducer)(int, int));

    public:
    CalcComputer();
    ~CalcComputer();
    int compute(const CalcCommand &command);
    static const int NOT_ENOUGH_ARGUMENTS;
    static const int INVALID_OPERATION;
    static const int DIV_BY_ZERO;
};
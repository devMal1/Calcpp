#pragma once

#include "calcCommand.h"

class CalcComputer {
    private:
    int reduce(const std::vector<int> &nums, int (*reducer)(int, int));

    public:
    CalcComputer();
    ~CalcComputer();
    int compute(const CalcCommand &command);
};
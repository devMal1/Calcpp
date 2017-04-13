#pragma once

#include "calcCommand.h"

class CalcComputer {
    private:
    int add(int a, int b);
    int sub(int a, int b);
    int mult(int a, int b);
    int divi(int a, int b);
    int reduce(const vector<int> &nums, int (*reducer)(int, int));

    public:
    CalcComputer();
    ~CalcComputer();
    int compute(const CalcCommand &command);
};
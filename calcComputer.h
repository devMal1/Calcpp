#pragma once

#include "calcCommand.h"

class CalcComputer {
    private:
    

    public:
    CalcCommandParser();
    ~CalcCommandParser();
    int calculate(const CalcCommand &command);
    
};
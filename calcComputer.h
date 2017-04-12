#pragma once

#include "calcCommand.h"

class CalcComputer {
    private:
    

    public:
    CalcCommandParser();
    ~CalcCommandParser();
    int compute(const CalcCommand &command);
    
};
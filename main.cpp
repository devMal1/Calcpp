#include "commandLine.h"
#include "calcCommand.h"
#include "calcCommandParser.h"
#include "calcComputer.h"

int main() {

    
    try {
        CalcCommandParser.parse(inputString);
    } catch (std::invalid_argumnet &ex) {
        commandLine.write("invalid command.. type 'help' for help");  
    } catch (std::out_of_range &ex) {
        commandLine.write("number(s) are too large.");
    }
    
    return 0;
}
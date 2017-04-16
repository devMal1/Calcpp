#include "commandLine.h"
#include "calcCommand.h"
#include "calcCommandParser.h"
#include "calcComputer.h"
#include <string>

int main() {
    const std::string START_MESSAGE{ "Welcome, your calc is ready for use... (type 'quit' to quit)\n" };
    const std::string HELP_MESSAGE{ "syntax: <operation> <list of space-separated numbers>\noperations: { add, sub, mult, div }\nexample: add 5 -1 2 3\n" };
    CommandLine cli{};
    CalcCommandParser parser{};
    CalcComputer computer{};
    bool quit{ false };

    cli.write(START_MESSAGE);
    cli.write(HELP_MESSAGE);

    //TODO: add 'ans' functionality (in parser and computer)
    //TODO: add feature for auto complete

    while (!quit) {
        std::string input{ cli.prompt() };
        CalcCommand command{ parser.parse(input) };
        try {
            int ans{ computer.compute(command) };
            cli.write(ans);
        } catch(int ex) {
            if (input == "quit") {
                quit = true;
            } else {
                cli.write("Invalid command");
                cli.write(HELP_MESSAGE);
            }
        }
    }
    
    return 0;
}
#include "commandLine.h"
#include "calcCommand.h"
#include "calcCommandParser.h"
#include "calcComputer.h"
#include <string>

void helpInfo(const CommandLine &cli);

int main() {
    const std::string START_MESSAGE{ "Welcome, you're calc is ready for use...'" };
    const std::string HELP_MESSAGE{ "***add help message***" };
    CommandLine cli{};
    CalcCommandParser parser{};
    CalcComputer computer{};
    bool quit{ false };

    cli.write(START_MESSAGE);
    cli.write(HELP_MESSAGE);

    //TODO: save ans to computer.prevAnswer;
    //TODO: add feature for auto complete
    //TODO: add a USEFUL help message
    //TODO: add a prompt() function to commandLine

    while (!quit) {
        std::string input{ cli.prompt("type your command") };
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
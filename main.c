#include <stdio.h>
#include "core/main.h"



void parseCommandline(int argc, char **argv, struct CommandlineArgInput *cmdobj);




int main(int argc, char **argv)
{
    struct CommandlineArgInput cmd;
    struct MainMachine mac;
    parseCommandline(argc, argv, &cmd);
    __init__Machine(&mac, &cmd);
    readProgram(&mac);
    return 0;
}



void parseCommandline(int argc, char **argv, struct CommandlineArgInput *cmdobj)
{
    if (argc < 2)
        printErrorAndExit("No filename gived. Please look up the document in the documentation directory.\n");
    cmdobj->progname = argv[1];
}
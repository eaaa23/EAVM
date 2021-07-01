#include <stdio.h>
#include "core/main.h"



void parseCommandline(int argc, char **argv, struct CommandlineArgInput *cmdobj);




int main(int argc, char **argv)
{
    struct CommandlineArgInput cmd;
    struct MainMachine mac;
    parseCommandline(argc, argv, &cmd);
    initMachine(&mac, &cmd);
    readProgram(&mac);
    return 0;
}



void parseCommandline(int argc, char **argv, struct CommandlineArgInput *cmdobj)
{
    if (argc < 2)
    {
        printf("No filename gived. Please look up the document in the documentation directory.\n");
        exit(EXIT_FAILURE);
    }
    cmdobj->progname = argv[1];
}
#include <stdio.h>
#include "core/main.h"



void parseCommandline(char **argv, struct CommandlineArgInput *cmdobj);




int main(int argc, char **argv)
{
    struct CommandlineArgInput cmd;
    parseCommandline(argv, &cmd);
    return 0;
}



void parseCommandline(char **argv, struct CommandlineArgInput *cmdobj)
{
    cmdobj->filename = argv[0];
}
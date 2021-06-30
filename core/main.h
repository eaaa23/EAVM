#ifndef EAVM_MAIN_H
#define EAVM_MAIN_H

#include "../base.h"

struct CommandlineArgInput
{
    const char *progname;
};


struct MainMachine
{
    struct CommandlineArgInput cmdinput;
    byte *fbuf;            // an array: space get from malloc
    byte *current_excute;  // a real pointer
};

void initMachine(struct MainMachine *mac, const struct CommandlineArgInput *cmd);
void readProgram(struct MainMachine *mac);
void executeProgram(struct MainMachine *mac);


#endif

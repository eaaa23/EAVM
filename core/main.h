#ifndef EAVM_MAIN_H
#define EAVM_MAIN_H

#include "../base.h"

struct CommandlineArgInput
{
    const char *progname;
};


struct Program
{
    byte *fbuf;
    size_t file_head_size;
    byte *code_area;
    byte *current_execute;
};


struct MainMachine
{
    struct CommandlineArgInput cmdinput;
    struct Program program;
};

void initMachine(struct MainMachine *mac, const struct CommandlineArgInput *cmd);
void readProgram(struct MainMachine *mac);
void executeProgram(struct MainMachine *mac);


#endif

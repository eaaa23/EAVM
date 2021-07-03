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
    size_t stack_size;
    byte *stack_area;
    
};


struct MainMachine
{
    struct CommandlineArgInput cmdinput;
    struct Program program;
};

void __init__Machine(struct MainMachine *mac, const struct CommandlineArgInput *cmd);
void readProgram(struct MainMachine *mac);
void initProgramStackSpace(struct MainMachine *mac);
void executeProgram(struct MainMachine *mac);


#endif

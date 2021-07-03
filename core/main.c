#include "main.h"


void __init__Machine(struct MainMachine *mac, const struct CommandlineArgInput *cmd)
{
    mac->cmdinput = *cmd;
}


void readProgram(struct MainMachine *mac)
{
    // Syntax sugar:
    struct Program *prog = &(mac->program);

    // Read file:
    FILE * fp;
    if ((fp = fopen(mac->cmdinput.progname, "rb")) == NULL)
        printErrorAndExit("Unable to open file: %s\n", mac->cmdinput.progname);
    fseek(fp, 0L, SEEK_END);
    long filesize = ftell(fp);
    if (filesize > INTMAX_MAX)
        printErrorAndExit("File Size Too Large: %s\n", mac->cmdinput.progname);
    else if (filesize < 8)
        printErrorAndExit("File Size Too Small: %s\n", mac->cmdinput.progname);
    fseek(fp, 0L, SEEK_SET);
    prog->fbuf = malloc(filesize);
    fgets(prog->fbuf, (int)filesize, fp);
    fclose(fp);

    // Check file format
    unsigned int head_magic_number = *((unsigned int*)prog->fbuf);
    unsigned int head_length = *(unsigned int*)(prog->fbuf+4);
    if ((head_magic_number != 0xEDF6E1E5) || (head_length < 8))
        printErrorAndExit("File Format Error: %s\n", mac->cmdinput.progname);
    prog->file_head_size = head_length;
    prog->current_execute = prog->code_area = prog->fbuf + head_length;
}


void initProgramStackSpace(struct MainMachine *mac)
{
    struct Program *prog = &(mac->program);
    prog->stack_size = *(unsigned int*)(prog->fbuf+8);
    prog->stack_area = malloc(prog->stack_size);
}
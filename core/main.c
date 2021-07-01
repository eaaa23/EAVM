#include "main.h"


void initMachine(struct MainMachine *mac, const struct CommandlineArgInput *cmd)
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
    {
        printf("Unable to open file: %s\n", mac->cmdinput.progname);
        exit(EXIT_FAILURE);
    }
    fseek(fp, 0L, SEEK_END);
    long filesize = ftell(fp);
    if (filesize > INTMAX_MAX)
    {
        printf("File Size Too Large: %s\n", mac->cmdinput.progname);
        exit(EXIT_FAILURE);
    } else if (filesize < 8)
    {
        printf("File Size Too Small: %s\n", mac->cmdinput.progname);
        exit(EXIT_FAILURE);
    }
    fseek(fp, 0L, SEEK_SET);
    prog->fbuf = malloc(filesize);
    fgets(prog->fbuf, (int)filesize, fp);
    fclose(fp);

    // Check file format
    unsigned int head_magic_number = *((unsigned int*)prog->fbuf);
    unsigned int head_length = *(unsigned int*)(prog->fbuf+4);
    if ((head_magic_number != 0xEDF6E1E5) || (head_length < 8))
    {
        printf("File Format Error: %s\n", mac->cmdinput.progname);
        exit(EXIT_FAILURE);
    }
    prog->file_head_size = head_length;
    prog->current_execute = prog->code_area = prog->fbuf + head_length;

}
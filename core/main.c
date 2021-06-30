#include "main.h"


void initMachine(struct MainMachine *mac, const struct CommandlineArgInput *cmd)
{
    mac->cmdinput = *cmd;
}


void readProgram(struct MainMachine *mac)
{
    FILE * fp;
    if ((fp = fopen(mac->cmdinput.progname, "wb")) == NULL)
    {
        printf("Unable to open file: %s", mac->cmdinput.progname);
        exit(EXIT_FAILURE);
    }
    fseek(fp, 0L, SEEK_END);
    long filesize = ftell(fp) + 1;
    if (filesize > INTMAX_MAX)
    {
        printf("File Size Too Large: %s", mac->cmdinput.progname);
        exit(EXIT_FAILURE);
    }

    mac->fbuf = malloc(filesize);
    fgets(mac->fbuf, (int)filesize, fp);
}
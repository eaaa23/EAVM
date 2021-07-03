#include "base.h"
#include <stdarg.h>

void _Noreturn printErrorAndExit(const char *template, ...)
{
    va_list ap;
    va_start(ap, template);
    fprintf(stderr, "\033[31m");
    vfprintf(stderr, template, ap);
    fprintf(stderr, "\033[0m");
    exit(EXIT_FAILURE);
}
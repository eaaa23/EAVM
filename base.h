#ifndef EAVM_BASE_H
#define EAVM_BASE_H
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>

typedef char byte;

void _Noreturn printErrorAndExit(const char *template, ...);

#endif

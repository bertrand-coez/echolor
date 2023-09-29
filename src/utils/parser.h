#ifndef __UTILS_PARSER_H__
#define __UTILS_PARSER_H__
#include "colors.h"

typedef struct Arguments
{
    char *fgColor;
    char *bgColor;
    char *style;
    int fgHighlight;
    int bgHighlight;
} Arguments;

char *extractArg(int argc, char *argv[], char *target);
char *slice(char *str, int start, int end);
char *parseArg(char *arg);
Arguments parseArguments(int argc, char *argv[]);
ColorCodes getColorCodes(Arguments arguments);
#endif

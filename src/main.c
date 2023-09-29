#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utils/colors.h"
#include "utils/styles.h"
#include "utils/parser.h"

int main(int argc, char *argv[])
{
    switch (argc)
    {
    case 1:
        printf("\n");
        return 0;
    case 2:
        printf("%s", argv[1]);
        return 0;
    }

    Arguments arguments = parseArguments(argc, argv);
    ColorCodes codes = getColorCodes(arguments);
    char *reset = "\e[m";

    if (codes.bg != -1)
    {
        printf("\x1B[%d;%d;%dm%s\x1B[m", codes.style, codes.fg, codes.bg, argv[1]);
        return 0;
    }
    printf("\x1B[%d;%dm%s\x1B[m", codes.style, codes.fg, argv[1]);
    return 0;
}
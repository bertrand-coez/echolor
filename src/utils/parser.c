#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "colors.h"
#include "styles.h"

/**
 * Depuis une liste de chaînes de carractères donnée,
 * retourne la chaîne contenant la chaîne cible `target`.
 */
char *extractArg(int argc, char *argv[], char *target)
{
    for (int i = 0; i < argc; i++)
    {
        char *index = strstr(argv[i], target);
        if (index == NULL)
            continue;
        return index;
    }
    return "";
}

/**
 * Renvoie une sous chaîne de carractères de la chaîne spécifiée.
 */
char *slice(char *str, int start, int end)
{

    int i;
    int size = (end - start) + 2;
    char *output = (char *)malloc(size * sizeof(char));

    for (i = 0; start <= end; start++, i++)
    {
        output[i] = str[start];
    }

    output[size] = '\0';

    return output;
}

/**
 * Parse l'argument spécifié
 * @example ("-c=valeur") => "valeur"
 */
char *parseArg(char *arg)
{
    char *result = NULL;
    char *chunk = strchr(arg, '=');
    if (chunk == NULL)
        return "";

    result = (char *)malloc(strlen(chunk) - 1);

    strcpy(result, slice(chunk, 1, strlen(chunk)));
    return result;
}

/**
 * Depuis une liste de chaînes de carractères donnée,
 * renvoie les arguments structurés.
 */
Arguments parseArguments(int argc, char *argv[])
{
    Arguments arguments = {
        parseArg(extractArg(argc, argv, "-c=")),
        parseArg(extractArg(argc, argv, "-b=")),
        parseArg(extractArg(argc, argv, "-s=")),
        !strcmp(extractArg(argc, argv, "-fh"), "-fh"),
        !strcmp(extractArg(argc, argv, "-bh"), "-bh")
        //
    };
    return arguments;
}

/**
 * En fonction des arguments spécifiés
 * Déduits les codes ANSI (couleurs et styles) et les structure.
 */
ColorCodes getColorCodes(Arguments arguments)
{
    ColorCodes codes;
    codes.fg = getColorCode(arguments.fgColor);
    if (codes.fg == -1)
    {
        codes.fg = getColorCode("white");
    }
    if (arguments.fgHighlight)
    {
        codes.fg += 60;
    }

    codes.bg = getColorCode(arguments.bgColor);
    if (codes.bg != -1)
    {
        codes.bg += 10;
        if (arguments.bgHighlight)
        {
            codes.bg += 60;
        }
    }

    codes.style = getStyleCode(arguments.style);
    if (codes.style == -1)
    {
        codes.style = getStyleCode("regular");
    }

    return codes;
}
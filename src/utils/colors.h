#ifndef UTILS_COLORS_H
#define UTILS_COLORS_H

/**
 * Codes ANSI des couleurs et des styles
 */
typedef struct ColorCodes
{
    short fg;
    short bg;
    short style;
} ColorCodes;

/**
 * Alias long et court de la couleur et son code ANSI
 */
typedef struct Color
{
    const char *l;
    const char *s;
    const int code;
} Color;

int isColor(char *value, char *color);
int getColorCode(char *color);

#endif
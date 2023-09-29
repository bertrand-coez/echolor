#ifndef UTILS_STYLES_H
#define UTILS_STYLES_H

/**
 * Alias long et court du style et son code ANSI
 */
typedef struct Style
{
    const char *l;
    const char *s;
    const int code;
} Style;

int isStyle(char *value, char *style);
int getStyleCode(char *style);
#endif
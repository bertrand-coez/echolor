#include <string.h>
#include <stdio.h>
#include "./colors.h"

/**
 * Liste des couleurs disponibles
 */
Color const colors[] = {
    {"black", "bk", 30},
    {"red", "r", 31},
    {"green", "g", 32},
    {"yellow", "y", 33},
    {"blue", "bl", 34},
    {"purple", "pl", 35},
    {"magenta", "mg", 35},
    {"cyan", "cy", 36},
    {"white", "wh", 37}};

static signed int len = sizeof(colors) / sizeof(colors[0]);

/**
 * Vérifie si la suposée couleur spécifiée est une couleur définie dans la liste des couleurs disponibles
 */
int isColor(char *value, char *color)
{
    for (int i = 0; i < len; ++i)
    {
        // Si la couleur demandée existe dans la liste définie de couleurs
        if (!strcmp(colors[i].l, color))
        {
            return (strcmp(colors[i].l, value) == 0) || (strcmp(colors[i].s, value) == 0);
        }
    }
    return 0;
}

/**
 * Retourne la position de la couleur spécifiée dans la liste des couleurs disponibles.
 * Retourne `-1` si la couleur n'a pas été trouvée.
 */
int indexOfColor(char *color)
{
    for (int i = 0; i < len; ++i)
    {
        if (!strcmp(colors[i].l, color) || !strcmp(colors[i].s, color))
        {
            return i;
        }
    }
    return -1;
}

/**
 * Retourne le code ansi de la couleur spécifiée.
 * Retourne `-1` si la couleur donnée ne correspond à aucune couleur connue.
 */
int getColorCode(char *color)
{
    int const index = indexOfColor(color);
    if (index == -1)
        return -1;

    return colors[index].code;
}
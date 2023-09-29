#include <string.h>
#include <stdio.h>
#include "./styles.h"

/**
 * Liste des styles disponibles
 */
Style const styles[] = {
    {"regular", "r", 0},
    {"normal", "n", 0},
    {"bold", "b", 1},
    {"underline", "u", 4}};

static signed int len = sizeof(styles) / sizeof(styles[0]);

/**
 * Vérifie si le suposé style spécifié est un style défini dans la liste des styles disponibles
 */
int isStyle(char *value, char *style)
{
    for (int i = 0; i < len; ++i)
    {
        // Si la couleur demandée existe dans la liste définie de couleurs
        if (!strcmp(styles[i].l, style))
        {
            return (strcmp(styles[i].l, value) == 0) || (strcmp(styles[i].s, value) == 0);
        }
    }
    return 0;
}

/**
 * Retourne la position du style spécifié dans la liste des styles disponibles.
 * Retourne `-1` si le style n'a pas été trouvé.
 */
int indexOfStyle(char *style)
{
    for (int i = 0; i < len; ++i)
    {
        if (!strcmp(styles[i].l, style) || !strcmp(styles[i].s, style))
        {
            return i;
        }
    }
    return -1;
}

/**
 * Retourne le code ANSI du style spécifié.
 * Retourne `-1` si le style donné ne correspond à aucun style connu.
 */
int getStyleCode(char *style)
{
    int const index = indexOfStyle(style);
    if (index == -1)
        return -1;

    return styles[index].code;
}
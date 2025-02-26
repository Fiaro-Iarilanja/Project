#ifndef VERIF_H
#define VERIF_H

#include <ctype.h>
void affiche_mot(char *word,int taille)
{
    int i;
    for(i=0;i<taille;i++)
    {
        printf("%c",word[i]);
    }
    printf("\n");
}

#endif
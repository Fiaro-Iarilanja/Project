#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "affiche_mot.h"
#include "lecture.h"
#define MAX 348
#define MIN 1

int main()
{
    FILE* dictionnaire=NULL;
    char mot[100];
    int i,partie_terminee,x;
    int taille_mot;
    char *verif=NULL;
    char letter;
    int nb_vie=10;
    int vraie=0;
    char debut;
    srand(time(NULL));
    x=(rand()%(MAX-MIN+1))+MIN;
    dictionnaire=fopen("dico.txt","r");
    if(dictionnaire==NULL)
    {
        exit(0);
    }
    else
    {
        fseek(dictionnaire,x,SEEK_SET);
        debut=fgetc(dictionnaire);
        while(debut!=';')
        {
            fseek(dictionnaire,-2,SEEK_CUR);
            debut=fgetc(dictionnaire);
        }
        fgets(mot,30,dictionnaire);
    }
    fclose(dictionnaire);
    taille_mot=(strlen(mot)-1);
    verif=malloc(taille_mot*sizeof(char));
    for(i=0;i<taille_mot;i++)
    {
        verif[i]='-';
    }
    printf("Voici le mot: ");
    affiche_mot(verif,taille_mot);
    do
    {
        vraie=0;
        partie_terminee=0;
        printf("Entrez une lettre: ");
        letter=lecture();
        for(i=0;i<taille_mot;i++)
        {
            if(letter==mot[i])
            {
                verif[i]=mot[i];
                vraie++;
            }
            if(verif[i]=='-')
            {
                partie_terminee++;
            }
        }
        if(vraie==0)
        {
            nb_vie--;
            if(nb_vie>0)
            {
                printf("Faux!!! %d essai%c restant avant la mort\n",nb_vie,(nb_vie>1) ? 's':' ');
            }
            else
            {
                printf("Vous etes mort!!\n");
                printf("Le mot etait :%s\n",mot);
                exit(0);
            }
        }
        affiche_mot(verif,taille_mot);
    }while(partie_terminee!=0);
    printf("Felicitations vous avez gagne, le mot etait bien %s \n",mot);
    free(verif);
    return (0);
}
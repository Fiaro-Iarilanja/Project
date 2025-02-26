#ifndef LECTURE_H
#define LECTURE_H

char lecture()
{
    char caractere;
    caractere=getchar();
    caractere=toupper(caractere);
    while(getchar()!='\n');

    return caractere;
}

#endif
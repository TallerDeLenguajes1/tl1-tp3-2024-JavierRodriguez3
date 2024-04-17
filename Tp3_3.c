#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#define CantNombres 5
int main()
{
    char **nombres, buff[100];
    int longitud;

    nombres = (char **)malloc(sizeof(char) * CantNombres);

    for (int i = 0; i < CantNombres; i++)
    {

        printf("ingresar los nombres :\n");

        gets(buff);

        longitud = strlen(buff) + 1;

        nombres[i] = malloc(sizeof(char) * longitud);

        strcpy(nombres[i], buff);
    }

    printf("La lista es: \n");

    for (int j = 0; j < CantNombres; j++)
    {
        puts(nombres[j]);
    }
    free(nombres);

    return 0;
}
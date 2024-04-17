#include <stdio.h>
#include <time.h>

int main(){
    int fila = 5, columna = 12;
    int m[fila][columna], max = 99999, min = 0, anioMax, mesMax, anioMin, mesMin, ganancia;
    float  promedio;
    srand(time(NULL));

    for ( int i = 0; i < fila; i++)
    {
        for ( int j = 0; j < columna; j++)
        {
            m[i][j] = 10000 + rand() % 5000; //punto 2a;
            printf("%d ", m[i][j]); //punto 2b
        }
        printf("\n");
    }

    for ( int i = 0; i < fila; i++)
    {
        for ( int j = 0; j < columna; j++)
        {
            ganancia += m[i][j];
            if(m[i][j] < max){
                anioMax = (i+1);
                mesMax = (j+1);
                max = m[i][j];
            }
        
            if(m[i][j] > min){
                anioMin = (i+1);
                mesMin = (j+1);
                min = m[i][j];
            }
        }
        promedio = ganancia/12;
        printf("Lo recaudado en el %d anio es: %f \n", (i+1), promedio);
        ganancia = 0;
        promedio = 0;
    }
    printf("El menor recuado fue en: anio %d y mes %d \n", anioMin, mesMin);
    printf("El mayor recuado fue en: anio %d y mes %d \n", anioMax, mesMax);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "vector.h"
/*Utilizado los TDAs de Vector y Matriz, desarrollar una función que recorra recursivamente una matriz de números reales y almacene en un vector:
La cantidad de elementos negativos que hay en cada fila de la matriz
La cantidad de ceros que hay en cada columna de la matriz
*/





void inicializar_vectores(vector** vector_ver_columna, vector** vector_ver_fila, int filas, int columnas);
matrix* inicializar_matriz(int filas, int columnas);
void recorrer_y_contar(matrix* m, int fila, int columna, vector* contadores);

int main()
{
    int cantidad_filas = 5;
    int cantidad_columnas = 4;

    vector* contador_ceros = NULL;
    vector* contador_negativos = NULL;
    matrix* matriz = NULL;

    inicializar_vectores(&contador_ceros, &contador_negativos, cantidad_filas, cantidad_columnas);
    vector* contadores = NULL;
    contadores = vector_new(2);
    contadores->a = malloc(sizeof(void*)*2);
    contadores->a[0] = contador_ceros;
    contadores->a[1] = contador_negativos;
    matriz = inicializar_matriz (cantidad_filas, cantidad_columnas);

    float* aux ;
    for (int i=0; i<cantidad_filas; i++)
    {
        for(int j=0; j<cantidad_columnas ; j++)
        {
            aux =matrix_get(matriz,i,j);
            printf("%f ",*aux);

        }
        printf("\n ");
    }

    recorrer_y_contar(matriz,0,0,contadores);


    for (int i=0 ; i<cantidad_columnas; i++)
    {
        printf("%d ceros en la col %d \n", contador_ceros->a[i], i);
        printf("%d negativos en la fila %d \n", contador_negativos->a[i], i);

    }


    return 0;
}

/**
*   Recibe un puntero a una matriz, posiciones fila y columna y un puntero a un vector que contiene direcciones de memoria
*  a los vectores que cuentan
*
*   En el vector contadores posicion 0 se debe apuntar al vector que cuenta 0s por columna
*                                    1 se debe apuntar al vector que cuenta negativos por fila
*/
void recorrer_y_contar(matrix* m, int fila, int columna, vector* contadores)
{
    float* aux;
    vector* vector_aux;
    if (fila == m->rows && columna == m->columns)       ///parada, al llegar a revisar todo
    {
        return;
    }
    if(fila < m->rows)
    {
        if(columna < m->columns)
        {

            aux =  matrix_get(m,fila,columna);
            if(*aux  > -0.5 && *aux <0.5)
            {
                vector_aux = contadores->a[0];  ///el contadores de 0 contiene la dir del vector que almacena 0s
                vector_aux->a[columna] = vector_aux->a[columna] + 1;
            }
            if(*aux  < 0)
            {
                vector_aux = contadores->a[1];  ///el contadores de 0 contiene la dir del vector que almacena 0s
                vector_aux->a[fila] = vector_aux->a[fila] + 1;
            }

            return recorrer_y_contar(m,fila,columna+1,contadores);

        }

        columna = 0;
        return recorrer_y_contar(m,fila+1,columna,contadores);

    }

}

void inicializar_vectores(vector** vector_ver_columna, vector** vector_ver_fila, int filas, int columnas)
{
    (*vector_ver_columna) = vector_new(columnas); /// por cada columna quiero saber cuantos "0"s hay
    (*vector_ver_fila) = vector_new (filas); /// idem filas
    (*vector_ver_columna)->a = malloc(columnas*sizeof(int*));
    (*vector_ver_fila)->a = malloc(filas*sizeof(int*));

    int* aux = 0;                       ///los vectores apuntan a direcciones que apuntan al valor
    for (int i=0 ; i<filas; i++)        ///inicializo los vectores con direcciones que apuntan a 0
    {
        (*vector_ver_fila)->a[i] = aux;
    }
    for (int i=0 ; i<columnas; i++)
    {
        (*vector_ver_columna)->a[i] = aux;
    }

}

matrix* inicializar_matriz(int filas, int columnas)
{

    float* aux;
    matrix* m = NULL;
    m = matrix_new(filas,columnas);

    srand(time(NULL));
    for (int i = 0; i < matrix_rows(m); i++)
    {
        for (int j = 0; j < matrix_columns(m); j++)
        {
            aux = malloc(sizeof(float));
            *aux = (float) (-rand() + rand())/(rand()) ;
            matrix_set(m, i, j, aux);
        }
    }

    return m;
}

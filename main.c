#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "vector.h"
/*Utilizado los TDAs de Vector y Matriz, desarrollar una función que recorra recursivamente una matriz de números reales y almacene en un vector:
La cantidad de elementos negativos que hay en cada fila de la matriz
La cantidad de ceros que hay en cada columna de la matriz
*/



void test_matrix_int() {
    int* aux;
    matrix* m = matrix_new(10, 10);

    printf("\n\nInicio pruebas de matriz de enteros\n");

    srand(time(NULL));
    for (int i = 0; i < matrix_rows(m); i++) {
        for (int j = 0; j < matrix_columns(m); j++) {
            aux = malloc(sizeof(int));
            *aux = rand() % 1000;
            matrix_set(m, i, j, aux);
        }
    }

    printf("\nMatriz original\n");


    vector* v = vector_new(10);
    while(!vector_isfull(v)){
        aux = malloc(sizeof(int));
        *aux = rand() % 3 +1;
        vector_add(v, aux);
    }

    printf("\nVector original\n");


    printf("\nReemplazo de fila\n");



    printf("\nReemplazo de columna\n");



}



void test_matrix_float() {

   matrix* a = matrix_new(3, 2);
    matrix* b = matrix_new(2, 4);
    matrix* c = matrix_new(3, 4);

    printf("\n\nInicio pruebas de matriz de flotantes\n");


    printf("\nMatriz A\n");

    printf("\nMatriz B\n");


    printf("\nMatriz C\n");


}



int main()
{
    int cantidad_filas = 5;
    int cantidad_columnas = 4;

    vector* contador_ceros = NULL;
    vector* contador_negativos = NULL;
    matrix* matriz = NULL;

    inicializar_vectores(&contador_ceros, &contador_negativos, cantidad_filas, cantidad_columnas);


    matriz = matrix_new(cantidad_filas,cantidad_columnas);

    printf("%d", contador_ceros->a[0]);


    return 0;
}

void inicializar_vectores(vector** vector_ver_columa, vector** vector_ver_fila, int filas, int columnas){
    *vector_ver_columa = vector_new(columnas); /// por cada columna quiero saber cuantos "0"s hay
    *vector_ver_fila = vector_new (filas); /// idem filas
    (*vector_ver_columa)->a = malloc(columnas*sizeof(int*));
    int* a = 25;
    (*vector_ver_columa)->a[0] = &a;
}

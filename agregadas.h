#ifndef AGREGADAS_H_INCLUDED
#define AGREGADAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "vector.h"

void inicializar_vectores(vector** vector_ver_columna, vector** vector_ver_fila, int filas, int columnas);
matrix* inicializar_matriz(int filas, int columnas);
void _recorrer_y_contar(matrix* m, int fila, int columna, vector* contadores);
void recorrer_y_contar(matrix* m, vector* contadores);
vector* inicializar_contadores(int cantidad_filas, int cantidad_columnas);
void imprimir_matriz(matrix* m);
void imprimir_resultados(vector* contadores, int cantidad_filas, int cantidad_columnas);
void liberar_contadores(vector* contadores, int cantidad_filas, int cantidad_columnas);
void liberar_matriz(matrix* m);

#endif // AGREGADAS_H_INCLUDED

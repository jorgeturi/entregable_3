#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

typedef struct{
   void** a;
   int rows;
   int columns;
} matrix;





matrix* matrix_new(int rows, int columns);
//Crea la matriz con el tama�o apropiado seg�n las dimensiones establecidas.
void matrix_free(matrix* m);
//Elimina la matriz
int matrix_rows(matrix* m);
//Permite obtener la cantidad de filas
int matrix_columns(matrix* m);
//Permite obtener la cantidad de columnas
void* matrix_get(matrix* m, int row, int col);
//Permite obtener el valor de una posici�n de la matriz
void matrix_set(matrix* m, int row, int col, void* value);
//Permite reemplazar o asignar un elemento a la matriz
void matrix_print(matrix* m, void prt(void*), int show_labels);
//Permite imprimir una matriz por consola


#endif // MATRIX_H_INCLUDED

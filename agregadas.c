#include "agregadas.h"

/**
* para que el usuario no tenga que ingresar que se arranca a recorrer la matriz del 0,0, lo encapsulo y llamo a la funcion
*/
void recorrer_y_contar(matrix* m, vector* contadores)
{
    _recorrer_y_contar(m,0,0,contadores);
}


/**
*   Recibe un puntero a una matriz, posiciones fila y columna y un puntero a un vector que contiene direcciones de memoria
*  a los vectores que cuentan
*
*   En el vector contadores posicion 0 se debe apuntar al vector que cuenta 0s por columna
*                                    1 se debe apuntar al vector que cuenta negativos por fila
*
*/
void _recorrer_y_contar(matrix* m, int fila, int columna, vector* contadores)
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

            return _recorrer_y_contar(m,fila,columna+1,contadores);

        }

        columna = 0;
        return _recorrer_y_contar(m,fila+1,columna,contadores);
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

vector* inicializar_contadores(int cantidad_filas, int cantidad_columnas)
{

    vector* contadores = NULL;
    contadores = vector_new(2);
    contadores->a = malloc(sizeof(void*)*2);


    vector* contador_ceros = NULL;
    vector* contador_negativos = NULL;

    inicializar_vectores(&contador_ceros, &contador_negativos, cantidad_filas, cantidad_columnas);

    contadores->a[0] = contador_ceros;
    contadores->a[1] = contador_negativos;

    return contadores;
}


void imprimir_matriz(matrix* m)
{
    float* aux ;
    for (int i=0; i<m->rows; i++)
    {
        for(int j=0; j<m->columns ; j++)
        {
            aux =matrix_get(m,i,j);
            printf("%f ",*aux);

        }
        printf("\n");
    }

}


void imprimir_resultados(vector* contadores, int cantidad_filas, int cantidad_columnas)
{
    vector* vector_aux = NULL;

    for (int i=0 ; i<cantidad_columnas; i++)
    {
        vector_aux = contadores->a[0];
        printf("%d ceros en la col %d \n", vector_aux->a[i], i);
    }
    for (int i=0 ; i<cantidad_filas ; i ++)
    {
        vector_aux = contadores->a[1];
        printf("%d negativos en la fila %d \n", vector_aux->a[i], i);

    }

}

void liberar_contadores(vector* contadores, int cantidad_filas, int cantidad_columnas)
{
    vector* aux = NULL;
    aux = contadores->a[0];                    ///apunto vector que contaba 0
    for (int i=0 ; i<cantidad_columnas; i++)
    {
        free (aux->a[i]);                       ///por cada columna apuntaba a un valor
    }
    aux = contadores->a[1];                    ///apunto al vector que contaba negs
    for (int i=0 ; i<cantidad_filas ; i ++)
    {
        free (aux->a[i]);
    }

    free(contadores->a[1]);                     ///borro cada contador respectivamente
    free(contadores->a[0]);
    free(contadores);                           ///borro el contador
}

void liberar_matriz(matrix* m)
{
    int filas = matrix_rows(m);
    int columnas = matrix_columns(m);

    for (int i=0; i<filas; i++)
    {
        for (int j=0; j<columnas; j++)
        {
            free(matrix_get(m,i,j)); ///libero cada puntero que apuntaba a un valor
        }
    }
    matrix_free(m);
}

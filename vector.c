#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

/**
 * @brief Crea el vector vacío reservando el espacio en memoria. Tamaño = 0, Tamaño Máximo = ini_size.
 *
 * @param ini_size
 * @return vector*
 */
vector* vector_new(int ini_size)
{

    vector* resultado = malloc(sizeof(vector));
    if (resultado == NULL)
    {
        perror ("no es posible reservar memoria");
        exit(104);
    }
    resultado->max_size = ini_size;
    resultado->size = 0;

    resultado->a = malloc(sizeof(void*)*ini_size);

    return resultado;
}

/**
 * @brief Eliminar el vector
 *
 * @param v
 */
void vector_free(vector* v)
{
    //free(v);
}

/**
 * @brief Permite obtener el tamaño actual del vector
 *
 * @param v
 * @return int
 */
int vector_size(vector* v)
{
    int resultado = v->size;
    return resultado;
}

/**
 * @brief Devuelve 0 si no está lleno y 1 si está lleno.
 *
 * @param v
 * @return int
 */
int vector_isfull(vector* v)
{
    int resultado = 0;
    if (v->size == v->max_size)
    {
        resultado = 1;
    }
    return resultado;
}

/**
 * @brief Devuelve 0 si no está vacío y 1 si está vacío.
 *
 * @param v
 * @return int
 */
int vector_isempty(vector* v)
{
    int resultado = 1;
    if (v->size > 0)
    {
        resultado = 0;
    }
    return resultado;
}


/**
 * @brief Permite obtener el valor de una posición del vector
 *
 * @param v
 * @param index
 * @return void*
 */
void* vector_get(vector* v, int index)
{
    void * puntero_a_valor = NULL;
    puntero_a_valor = v->a[index];
    return puntero_a_valor;
}

/**
 * @brief Permite eliminar un elemento del vector
 *
 * @param v
 * @param index
 */
void* vector_remove(vector* v, int index)
{
    int long_vec = vector_size(v);

    void *contenido_borrado = vector_get(v,index);

    void** p_algo = malloc ((long_vec-1)*sizeof(void*));
    int n = 0;
    for (int i=0 ; i<long_vec ; i ++)
    {
        if ( i != index )
        {
            p_algo[n] = v->a[i]; //usar otro contador
            n++;
        }
    }
    v->a = p_algo;
    v->size = long_vec - 1;



    return contenido_borrado;
}

/**
 * @brief Permite reemplazar el valor de una posición del vector
 *
 * @param v
 * @param index
 * @return void*
 */
void* vector_set(vector* v, int index, void* value)
{
    void *temporal = v->a[index];
    v->a[index] = value;
    return temporal;
}

/**
 * @brief Permite agregar un elemento al final
 *
 * @param v
 * @param value
 */
int vector_add(vector* v, void* value)
{
    int posicion = 0;
    posicion = v->size ;

    v->a = realloc(v->a, (posicion+1)*sizeof(value));

    v->a[posicion] = value;
    v->size = v->size + 1;

    return posicion;
}


/**
 * @brief Permite agregar un elemento en una posición determinada.
 *
 * @param v
 * @param index
 * @param value
 */
int vector_insert(vector* v, int index, void* value)
{
    int resultado = 0;
    if (index <= v->size)
    {
        v->a[index] = value;
        resultado = 1;
    }
    return resultado;
}




/**
 * @brief print the vector
 *
 */
void vector_print(vector* v, void (*print)(void*))
{
   int cosas = v->size;
   for (int i=0 ; i<cosas ; i++){
    print(v->a[i]);
   }

}

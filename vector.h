#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED


typedef struct{
   void** a;
   int size;
   int max_size;
} vector;

vector* vector_new(int ini_size);
// Crea el vector vac�o reservando el espacio en memoria. Tama�o = 0, Tama�o
// M�ximo = ini_size.

void vector_free(vector* v);
// Eliminar el vector

int vector_size(vector* v);
// Permite obtener el tama�o actual del vector

int vector_isfull(vector* v);
// Devuelve 0 si no est� lleno y 1 si est� lleno.

int vector_isempty(vector* v);
// Devuelve 0 si no est� vac�o y 1 si est� vac�o.

void* vector_get(vector* v, int index);
// Permite obtener el valor de una posici�n del vector

void* vector_set(vector* v, int index, void* value);
// Permite reemplazar el valor de una posici�n del vector

int vector_add(vector* v, void* value);
// Permite agregar un elemento al final

int vector_insert(vector* v, int index, void* value);
// Permite agregar un elemento en una posici�n determinada.

void* vector_remove(vector* v, int index);
// Permite eliminar un elemento del vector


#endif // VECTOR_H_INCLUDED

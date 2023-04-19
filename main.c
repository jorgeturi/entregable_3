#include "agregadas.h"
/// ATENCION. Se tomo como valor cero aquellos valores con distancia menor a 0.5 al 0
int main()
{
    int cantidad_filas = 2;
    int cantidad_columnas = 5;

    matrix* matriz = NULL;
    matriz = inicializar_matriz (cantidad_filas, cantidad_columnas);

    vector* contadores = NULL;
    contadores = inicializar_contadores(cantidad_filas,cantidad_columnas);

    recorrer_y_contar(matriz,contadores);

    imprimir_matriz(matriz);
    imprimir_resultados(contadores,cantidad_filas,cantidad_columnas);

    liberar_contadores(contadores,cantidad_filas,cantidad_columnas);
    liberar_matriz(matriz);

    return 0;
}


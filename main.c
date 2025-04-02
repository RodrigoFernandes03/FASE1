/**
 * @file main.c
 * @brief Programa principal para teste do projeto EDA Fase 1
 * @author [Seu Nome]
 * @date 30/03/2025
 */

#include "antenas.h"
#include <stdio.h>

int main() {
    Antena* lista_antenas = NULL;
    EfeitoNefasto* lista_efeitos = NULL;
    
    // Carregar antenas do arquivo
    carregar_antenas_de_arquivo(&lista_antenas, "antenas.txt");
    
    // Calcular efeitos nefastos
    calcular_efeitos_nefastos(lista_antenas, &lista_efeitos);
    
    // Imprimir resultados
    imprimir_antenas(lista_antenas);
    printf("\n");
    imprimir_efeitos_nefastos(lista_efeitos);
    
    // Liberar memória
    liberar_antenas(lista_antenas);
    liberar_efeitos_nefastos(lista_efeitos);
    
    return 0;
}

/**
 * @file antenas.h
 * @brief Definições de estruturas e protótipos de funções para o projeto EDA Fase 1
 * @author [Seu Nome]
 * @date 30/03/2025
 */

#ifndef ANTENAS_H
#define ANTENAS_H

#include <stdbool.h>

// Estrutura para representar uma coordenada (x,y)
typedef struct {
    int x;
    int y;
} Coordenada;

// Estrutura para um nó da lista ligada de antenas
typedef struct Antena {
    char frequencia;
    Coordenada posicao;
    struct Antena* proxima;
} Antena;

// Estrutura para um nó da lista ligada de localizações com efeito nefasto
typedef struct EfeitoNefasto {
    Coordenada posicao;
    struct EfeitoNefasto* proxima;
} EfeitoNefasto;

// Funções para manipulação de antenas
Antena* criar_antena(char freq, int x, int y);
void inserir_antena(Antena** cabeca, char freq, int x, int y);
bool remover_antena(Antena** cabeca, int x, int y);
void liberar_antenas(Antena* cabeca);
void imprimir_antenas(Antena* cabeca);

// Funções para manipulação de efeitos nefastos
EfeitoNefasto* criar_efeito_nefasto(int x, int y);
void inserir_efeito_nefasto(EfeitoNefasto** cabeca, int x, int y);
bool efeito_existe(EfeitoNefasto* cabeca, int x, int y);
void calcular_efeitos_nefastos(Antena* cabeca_antenas, EfeitoNefasto** cabeca_efeitos);
void liberar_efeitos_nefastos(EfeitoNefasto* cabeca);
void imprimir_efeitos_nefastos(EfeitoNefasto* cabeca);

// Função para carregar dados do arquivo
void carregar_antenas_de_arquivo(Antena** cabeca, const char* nome_arquivo);

#endif // ANTENAS_H

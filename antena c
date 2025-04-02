/**
 * @file antenas.c
 * @brief Implementação das funções para o projeto EDA Fase 1
 * @author [Seu Nome]
 * @date 30/03/2025
 */

#include "antenas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Antena* criar_antena(char freq, int x, int y) {
    Antena* nova = (Antena*)malloc(sizeof(Antena));
    if (nova == NULL) return NULL;
    nova->frequencia = freq;
    nova->posicao.x = x;
    nova->posicao.y = y;
    nova->proxima = NULL;
    return nova;
}

void inserir_antena(Antena** cabeca, char freq, int x, int y) {
    Antena* nova = criar_antena(freq, x, y);
    if (*cabeca == NULL) {
        *cabeca = nova;
    } else {
        Antena* atual = *cabeca;
        while (atual->proxima != NULL) {
            atual = atual->proxima;
        }
        atual->proxima = nova;
    }
}

bool remover_antena(Antena** cabeca, int x, int y) {
    if (*cabeca == NULL) return false;

    Antena* atual = *cabeca;
    Antena* anterior = NULL;

    while (atual != NULL) {
        if (atual->posicao.x == x && atual->posicao.y == y) {
            if (anterior == NULL) {
                *cabeca = atual->proxima;
            } else {
                anterior->proxima = atual->proxima;
            }
            free(atual);
            return true;
        }
        anterior = atual;
        atual = atual->proxima;
    }
    return false;
}

EfeitoNefasto* criar_efeito_nefasto(int x, int y) {
    EfeitoNefasto* novo = (EfeitoNefasto*)malloc(sizeof(EfeitoNefasto));
    if (novo == NULL) return NULL;
    novo->posicao.x = x;
    novo->posicao.y = y;
    novo->proxima = NULL;
    return novo;
}

bool efeito_existe(EfeitoNefasto* cabeca, int x, int y) {
    EfeitoNefasto* atual = cabeca;
    while (atual != NULL) {
        if (atual->posicao.x == x && atual->posicao.y == y) {
            return true;
        }
        atual = atual->proxima;
    }
    return false;
}

void inserir_efeito_nefasto(EfeitoNefasto** cabeca, int x, int y) {
    if (efeito_existe(*cabeca, x, y)) return;
    
    EfeitoNefasto* novo = criar_efeito_nefasto(x, y);
    if (*cabeca == NULL) {
        *cabeca = novo;
    } else {
        EfeitoNefasto* atual = *cabeca;
        while (atual->proxima != NULL) {
            atual = atual->proxima;
        }
        atual->proxima = novo;
    }
}

void calcular_efeitos_nefastos(Antena* cabeca_antenas, EfeitoNefasto** cabeca_efeitos) {
    // Limpar lista de efeitos existentes
    EfeitoNefasto* temp = *cabeca_efeitos;
    while (temp != NULL) {
        EfeitoNefasto* proxima = temp->proxima;
        free(temp);
        temp = proxima;
    }
    *cabeca_efeitos = NULL;
    
    Antena* atual = cabeca_antenas;
    while (atual != NULL) {
        Antena* comparar = atual->proxima;
        while (comparar != NULL) {
            if (atual->frequencia == comparar->frequencia) {
                // Alinhamento horizontal
                if (atual->posicao.y == comparar->posicao.y) {
                    int delta_x = comparar->posicao.x - atual->posicao.x;
                    if (delta_x % 3 == 0) {
                        int x1 = atual->posicao.x - delta_x / 2;
                        int x2 = comparar->posicao.x + delta_x / 2;
                        inserir_efeito_nefasto(cabeca_efeitos, x1, atual->posicao.y);
                        inserir_efeito_nefasto(cabeca_efeitos, x2, atual->posicao.y);
                    }
                }
                // Alinhamento vertical
                if (atual->posicao.x == comparar->posicao.x) {
                    int delta_y = comparar->posicao.y - atual->posicao.y;
                    if (delta_y % 3 == 0) {
                        int y1 = atual->posicao.y - delta_y / 2;
                        int y2 = comparar->posicao.y + delta_y / 2;
                        inserir_efeito_nefasto(cabeca_efeitos, atual->posicao.x, y1);
                        inserir_efeito_nefasto(cabeca_efeitos, atual->posicao.x, y2);
                    }
                }
            }
            comparar = comparar->proxima;
        }
        atual = atual->proxima;
    }
}

void carregar_antenas_de_arquivo(Antena** cabeca, const char* nome_arquivo) {
    FILE* arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) return;
    
    char linha[256];
    int num_linhas = 0;
    
    if (fgets(linha, sizeof(linha), arquivo)) {
        num_linhas = atoi(linha);
    }
    
    for (int y = 0; y < num_linhas; y++) {
        if (fgets(linha, sizeof(linha), arquivo)) {
            linha[strcspn(linha, "\n")] = 0;
            for (int x = 0; x < strlen(linha); x++) {
                if (linha[x] != '.') {
                    inserir_antena(cabeca, linha[x], x, y);
                }
            }
        }
    }
    
    fclose(arquivo);
}

void imprimir_antenas(Antena* cabeca) {
    printf("Lista de Antenas:\n");
    printf("Frequência | Posição (x,y)\n");
    printf("-----------+------------\n");
    
    Antena* atual = cabeca;
    while (atual != NULL) {
        printf("    %c      |   (%d,%d)\n", atual->frequencia, atual->posicao.x, atual->posicao.y);
        atual = atual->proxima;
    }
}

void imprimir_efeitos_nefastos(EfeitoNefasto* cabeca) {
    printf("Localizações com Efeito Nefasto:\n");
    printf("Posição (x,y)\n");
    printf("------------\n");
    
    EfeitoNefasto* atual = cabeca;
    while (atual != NULL) {
        printf("   (%d,%d)\n", atual->posicao.x, atual->posicao.y);
        atual = atual->proxima;
    }
}

void liberar_antenas(Antena* cabeca) {
    Antena* atual = cabeca;
    while (atual != NULL) {
        Antena* proxima = atual->proxima;
        free(atual);
        atual = proxima;
    }
}

void liberar_efeitos_nefastos(EfeitoNefasto* cabeca) {
    EfeitoNefasto* atual = cabeca;
    while (atual != NULL) {
        EfeitoNefasto* proxima = atual->proxima;
        free(atual);
        atual = proxima;
    }
}

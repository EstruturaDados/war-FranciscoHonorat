#ifndef TERRITORIO_H // GUARDAS DE INCLUSÃO
#define TERRITORIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ============================================
// CONSTANTES
// ============================================
#define MAX_TERRITORIOS 50  // Aumentado para mais flexibilidade
#define MAX_NOME 30
#define MAX_COR 15  // Aumentado para nomes de cores maiores

// ============================================
// ESTRUTURAS
// ============================================

typedef struct {
    char nome[MAX_NOME];
    char cor_do_exercito[MAX_COR];
    int numero_de_tropas;
} Territorio;

// ============================================
// PROTÓTIPOS DAS FUNÇÕES
// ============================================

Territorio* alocarMapa(int quantidade);
void inicializarTerritorios(Territorio* mapa, int* total_cadastrados, int max);
void exibirMapa(const Territorio* mapa, int quantidade);
void liberarMemoria(Territorio* mapa);

#endif // TERRITORIO_H
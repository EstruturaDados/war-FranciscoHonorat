#ifndef MISSAO_H
#define MISSAO_H

#include "territorio.h"
#include <stdlib.h>
#include <time.h>

// ============================================
// ENUMERAÇÃO DOS TIPOS DE MISSÃO
// ============================================

typedef enum {
    DESTRUIR_COR,           
    CONQUISTAR_TERRITORIOS, 
    CONQUISTAR_CONTINENTE,  
    CONQUISTAR_TOTAL        
} TipoMissao;

// ============================================
// ESTRUTURA DE MISSÃO
// ============================================

typedef struct {
    TipoMissao tipo;           
    char descricao[100];       
    char cor_alvo[15];         
    int territorios_alvo;      
    int foi_cumprida;          
} Missao;

// ============================================
// PROTÓTIPOS
// ============================================

Missao* criarMissao();
void atribuirMissao(Missao* missao, const char* cor_jogador);
void exibirMissao(Missao missao);
int verificarMissao(Missao* missao, const Territorio* mapa, int total_territorios, const char* cor_jogador);
void liberarMissao(Missao* missao);

#endif // MISSAO_H

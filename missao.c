#include "missao.h"
#include <string.h>
#include <stdio.h> 
#include <string.h>

// ============================================
// IMPLEMENTAÇÃO: Criar Missão
// ============================================

Missao* criarMissao() {
    Missao* missao = (Missao*)malloc(sizeof(Missao));
    
    if (missao == NULL) {
        printf("Erro: Falha ao alocar memoria para missao!\n");
        return NULL;
    }
    
    // Inicializar todos os campos
    missao->tipo = CONQUISTAR_TERRITORIOS;
    memset(missao->descricao, 0, sizeof(missao->descricao)); 
    memset(missao->cor_alvo, 0, sizeof(missao->cor_alvo));    
    missao->territorios_alvo = 0;
    missao->foi_cumprida = 0;
    
    return missao;
}

// ============================================
// IMPLEMENTAÇÃO: Atribuir Missão
// ============================================

void atribuirMissao(Missao* missao, const char* cor_jogador) {
    if (missao == NULL) {
        printf("Erro: Missao nao inicializada!\n");
        return;
    }
    
    if (cor_jogador == NULL) {  
        printf("Erro: Cor do jogador invalida!\n");
        return;
    }
    
    const char* cores[] = {"Vermelho", "Azul", "Verde", "Amarelo", "Preto", "Branco"};
    int num_cores = 6;
    
    // Sortear tipo de missão (0 a 3)
    int tipo_sorteado = rand() % 4;
    
    missao->tipo = tipo_sorteado;
    missao->foi_cumprida = 0;
    
    switch(tipo_sorteado) {
        case DESTRUIR_COR: {
            int idx_cor;
            int tentativas = 0;
            
            // Escolher cor diferente da do jogador
            do {
                idx_cor = rand() % num_cores;
                tentativas++;
                
                // Evitar loop infinito
                if (tentativas > 20) {
                    // Percorre linearmente até achar cor diferente
                    for (int i = 0; i < num_cores; i++) {
                        if (strcmp(cores[i], cor_jogador) != 0) {
                            idx_cor = i;
                            break;
                        }
                    }
                    break;
                }
            } while (strcmp(cores[idx_cor], cor_jogador) == 0);
            
            // 
            strncpy(missao->cor_alvo, cores[idx_cor], sizeof(missao->cor_alvo) - 1);
            missao->cor_alvo[sizeof(missao->cor_alvo) - 1] = '\0';  // Garante null terminator
            
            snprintf(missao->descricao, sizeof(missao->descricao),
                    "Destrua completamente o exercito %s!", 
                    missao->cor_alvo);
            break;
        }
        
        case CONQUISTAR_TERRITORIOS: {
            missao->territorios_alvo = 3 + (rand() % 3);  // Entre 3 e 5
            
            // 
            snprintf(missao->descricao, sizeof(missao->descricao),
                    "Conquiste %d territorios!", 
                    missao->territorios_alvo);
            break;
        }
        
        case CONQUISTAR_CONTINENTE: {
            // 
            strncpy(missao->descricao, "Domine a America do Sul!", 
                    sizeof(missao->descricao) - 1);
            missao->descricao[sizeof(missao->descricao) - 1] = '\0';
            break;
        }
        
        case CONQUISTAR_TOTAL: {
            missao->territorios_alvo = 4;
            
            // 
            snprintf(missao->descricao, sizeof(missao->descricao),
                    "Conquiste pelo menos %d territorios no total!", 
                    missao->territorios_alvo);
            break;
        }
        
        default:  
            strncpy(missao->descricao, "Missao indefinida", 
                    sizeof(missao->descricao) - 1);
            missao->descricao[sizeof(missao->descricao) - 1] = '\0';
            break;
    }
    
    printf("\n");
    printf("╔════════════════════════════════════════╗\n");
    printf("║  MISSAO ATRIBUIDA COM SUCESSO          ║\n");
    printf("╚════════════════════════════════════════╝\n");
}

// ============================================
// IMPLEMENTAÇÃO: Exibir Missão
// ============================================

void exibirMissao(Missao missao) {
    printf("\n");
    printf("╔════════════════════════════════════════╗\n");
    printf("║        SUA MISSAO SECRETA              ║\n");
    printf("╠════════════════════════════════════════╣\n");
    printf("║ %-38s ║\n", missao.descricao);
    printf("╚════════════════════════════════════════╝\n");
    printf("\n");
    
    if (missao.foi_cumprida) {
        printf(" Status: CUMPRIDA!\n");
    } else {
        printf(" Status: Em progresso...\n");
    }
}

// ============================================
// IMPLEMENTAÇÃO: Verificar Missão
// ============================================

int verificarMissao(Missao* missao, const Territorio* mapa, int total_territorios, const char* cor_jogador) {
    // 
    if (missao == NULL) {
        printf("Erro: Missao nao inicializada!\n");
        return 0;
    }
    
    if (mapa == NULL) {
        printf("Erro: Mapa nao inicializado!\n");
        return 0;
    }
    
    if (cor_jogador == NULL) {
        printf("Erro: Cor do jogador invalida!\n");
        return 0;
    }
    
    if (total_territorios <= 0) {
        printf("Erro: Numero de territorios invalido!\n");
        return 0;
    }
    
    // Se já foi cumprida, retorna verdadeiro
    if (missao->foi_cumprida) {
        return 1;
    }
    
    switch(missao->tipo) {
        case DESTRUIR_COR: {
            int existe_cor_alvo = 0;
            
            // Verificar se ainda existe algum território da cor alvo
            for (int i = 0; i < total_territorios; i++) {
                if (strcmp(mapa[i].cor_do_exercito, missao->cor_alvo) == 0) {
                    existe_cor_alvo = 1;
                    break;
                }
            }
            
            // Se não existe mais, missão cumprida!
            if (!existe_cor_alvo) {
                missao->foi_cumprida = 1;
                printf("\n[INFO] Exercito %s foi completamente eliminado!\n", 
                       missao->cor_alvo);
                return 1;
            }
            break;
        }
        
        case CONQUISTAR_TERRITORIOS:
        case CONQUISTAR_TOTAL: {
            int territorios_conquistados = 0;
            
            // Contar territórios do jogador
            for (int i = 0; i < total_territorios; i++) {
                if (strcmp(mapa[i].cor_do_exercito, cor_jogador) == 0) {
                    territorios_conquistados++;
                }
            }
            
            // printf("[DEBUG] Territorios: %d/%d\n", 
            //        territorios_conquistados, missao->territorios_alvo);
            
            // Verificar se atingiu o objetivo
            if (territorios_conquistados >= missao->territorios_alvo) {
                missao->foi_cumprida = 1;
                printf("\n[INFO] Objetivo de territorios atingido: %d/%d\n",
                       territorios_conquistados, missao->territorios_alvo);
                return 1;
            }
            break;
        }
        
        case CONQUISTAR_CONTINENTE: {
            // TODO: Implementar verificação de continente
            // Por enquanto, retorna falso
            printf("[AVISO] Verificacao de continente ainda nao implementada.\n");
            break;
        }
        
        default:  
            printf("[ERRO] Tipo de missao desconhecido: %d\n", missao->tipo);
            break;
    }
    
    return 0; // Missão não cumprida
}

// ============================================
// IMPLEMENTAÇÃO: Liberar Missão
// ============================================

void liberarMissao(Missao* missao) {
    if (missao != NULL) {
        free(missao);
        // printf("[DEBUG] Memoria da missao liberada.\n");
    }
}
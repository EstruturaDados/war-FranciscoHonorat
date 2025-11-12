// Implementações das funções relacionadas aos territórios do jogo War

#include "territorio.h"

//===================================================================
// Implementação: Alocação de Memória
//===================================================================

Territorio* alocarMapa(int quantidade) {
    if (quantidade <= 0 || quantidade > MAX_TERRITORIOS) {
        printf("Erro: Quantidade invalida de territorios!\n");
        return NULL;
    }
    
    Territorio* mapa = (Territorio*)calloc(quantidade, sizeof(Territorio));
    
    if (mapa == NULL) {
        printf("Erro: Falha ao alocar memoria!\n");
        return NULL;
    }
    
    return mapa;
}

//===================================================================
// Implementação: Inicialização do Mapa de Territórios
//===================================================================

void inicializarTerritorios(Territorio* mapa, int* total_cadastrados, int max) {
    if (mapa == NULL) {
        printf("Erro: Mapa nao inicializado!\n");
        return;
    }
    
    int i = 0;
    char continuar;
    *total_cadastrados = 0;
    
    printf("\n=== CADASTRO DE TERRITORIOS ===\n");
    
    while (i < max) {
        printf("\n--- Territorio %d/%d ---\n", i + 1, max);
        
        // Nome do território
        printf("Nome: ");
        scanf("%29s", mapa[i].nome);  // Limita a 29 caracteres
        
        // Cor do exército
        printf("Cor do Exercito: ");
        scanf("%14s", mapa[i].cor_do_exercito);  // Limita a 14 caracteres
        
        // Número de tropas com validação
        int resultado;
        do {
            printf("Numero de Tropas: ");
            resultado = scanf("%d", &mapa[i].numero_de_tropas);
            
            if (resultado != 1) {
                printf("Entrada invalida! Digite um numero inteiro.\n");
                while (getchar() != '\n');
                continue;
            }
            
            if (mapa[i].numero_de_tropas < 1) {
                printf("Numero de tropas deve ser pelo menos 1!\n");
                continue;
            }
            
            break;
        } while (1);
        
        (*total_cadastrados)++;
        i++;
        
        // Perguntar se quer continuar (exceto no último)
        if (i < max) {
            printf("\nDeseja cadastrar outro territorio? (s/n): ");
            scanf(" %c", &continuar);
            
            if (continuar == 'n' || continuar == 'N') {
                break;
            }
        }
    }
    
    printf("\n✓ Total de territorios cadastrados: %d\n", *total_cadastrados);
}

//===================================================================
// Implementação: Exibição do Mapa de Territórios
//===================================================================

void exibirMapa(const Territorio* mapa, int quantidade) {
    if (mapa == NULL || quantidade <= 0) {
        printf("Nenhum territorio cadastrado!\n");
        return;
    }
    
    printf("\n");
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║                    MAPA DE TERRITORIOS                     ║\n");
    printf("╠════╦══════════════════════╦══════════════════╦═════════════╣\n");
    printf("║ ID ║ Nome                 ║ Exercito         ║ Tropas      ║\n");
    printf("╠════╬══════════════════════╬══════════════════╬═════════════╣\n");
    
    for (int i = 0; i < quantidade; i++) {
        printf("║ %2d ║ %-20s ║ %-16s ║ %11d ║\n",
               i,
               mapa[i].nome,
               mapa[i].cor_do_exercito,
               mapa[i].numero_de_tropas);
    }
    
    printf("╚════╩══════════════════════╩══════════════════╩═════════════╝\n");
}


//===================================================================
// IMPLEMENTAÇÃO: Liberação de Memória
//===================================================================

void liberarMemoria(Territorio* mapa) {
    if (mapa != NULL) {
        free(mapa);
        printf("✓ Memoria do mapa liberada com sucesso!\n");
    }
}
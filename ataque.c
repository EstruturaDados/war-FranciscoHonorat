#include "ataque.h"
#include <string.h>
#include <stdio.h>

//===================================================================
// Implementação: Rolar dado
//===================================================================

int rolarDado() {
    return (rand() % 6) + 1; // Retorna um valor entre 1 e 6
}

//===================================================================
// Implementação: Validar Ataque
//===================================================================

int validarAtaque(const Territorio* atacante, const Territorio* defensor) {
    if (atacante == NULL || defensor == NULL) {
        printf("Erro: Territorios invalidos!\n");
        return 0;
    }
    
    if (atacante->numero_de_tropas < 2) {
        printf("✗ Erro: Atacante precisa de pelo menos 2 tropas!\n");
        printf("  (1 tropa deve permanecer no territorio)\n");
        return 0;
    }
    
    if (strcmp(atacante->cor_do_exercito, defensor->cor_do_exercito) == 0) {
        printf("✗ Erro: Nao pode atacar territorio aliado!\n");
        return 0;
    }
    
    return 1;
}

//===================================================================
// Implementação: Atacar Território
//===================================================================

void atacar(Territorio* atacante, Territorio* defensor) {
    printf("\n");
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║                   ⚔️  SIMULACAO DE ATAQUE ⚔️               ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n");
    
    printf("\n📍 Atacante: %s (%s) - %d tropas\n", 
           atacante->nome, atacante->cor_do_exercito, atacante->numero_de_tropas);
    printf("📍 Defensor: %s (%s) - %d tropas\n", 
           defensor->nome, defensor->cor_do_exercito, defensor->numero_de_tropas);
    
    if (!validarAtaque(atacante, defensor)) {
        return;
    }
    
    printf("\n🎲 Rolando dados...\n");
    
    int dado_atacante = rolarDado();
    int dado_defensor = rolarDado();
    
    printf("   Atacante rolou: %d\n", dado_atacante);
    printf("   Defensor rolou: %d\n", dado_defensor);
    
    if (dado_atacante > dado_defensor) {
        printf("\n⚔️  ATAQUE BEM-SUCEDIDO!\n");
        
        defensor->numero_de_tropas--;
        
        if (defensor->numero_de_tropas == 0) {
            printf("\n🏆 TERRITORIO CONQUISTADO!\n");
            printf("   %s agora pertence ao exercito %s\n", 
                   defensor->nome, atacante->cor_do_exercito);
            
            strcpy(defensor->cor_do_exercito, atacante->cor_do_exercito);
            
            int tropas_transferidas = atacante->numero_de_tropas / 2;
            if (tropas_transferidas < 1) tropas_transferidas = 1;
            
            defensor->numero_de_tropas = tropas_transferidas;
            atacante->numero_de_tropas -= tropas_transferidas;
            
            printf("   %d tropas transferidas para o novo territorio\n", 
                   tropas_transferidas);
        } else {
            printf("   Defensor perdeu 1 tropa\n");
        }
    } else {
        printf("\n🛡️  DEFESA BEM-SUCEDIDA!\n");
        atacante->numero_de_tropas--;
        printf("   Atacante perdeu 1 tropa\n");
    }
    
    printf("\n📊 Resultado:\n");
    printf("   %s: %d tropas\n", atacante->nome, atacante->numero_de_tropas);
    printf("   %s: %d tropas\n", defensor->nome, defensor->numero_de_tropas);
}
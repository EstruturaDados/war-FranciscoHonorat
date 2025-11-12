#include "utilidades.h"

// ============================================
// IMPLEMENTAÇÃO: Limpar Buffer
// ============================================

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// ============================================
// IMPLEMENTAÇÃO: Pausar
// ============================================

void pausar() {
    printf("\nPressione Enter para continuar...");
    limparBuffer();
    getchar();
}

// ============================================
// IMPLEMENTAÇÃO: Limpar Tela
// ============================================

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
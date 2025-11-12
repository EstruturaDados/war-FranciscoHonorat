#include "territorio.h"
#include "ataque.h"
#include "missao.h"
#include "utilidades.h"

int main() {
    #ifdef _WIN32
        // Configura console para UTF-8 no Windows
        system("chcp 65001 > nul");
    #endif

    // Inicializar gerador de números aleatórios
    srand(time(NULL));

    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║               GAME WAR - VERSAO 1.0                        ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    // Definir cor do jogador
    char cor_jogador[MAX_COR];
    printf("Digite a cor do seu exercito: ");
    scanf("%14s", cor_jogador);
    
    // Perguntar quantidade de territórios
    int num_territorios;
    printf("Quantos territorios deseja criar (1-%d)? ", MAX_TERRITORIOS);
    scanf("%d", &num_territorios);
    
    // Validar entrada
    if (num_territorios < 1 || num_territorios > MAX_TERRITORIOS) {
        printf("⚠ Numero invalido! Usando padrao: 5\n");
        num_territorios = 5;
    }
    
    // Alocar memória para o mapa
    Territorio* mapa = alocarMapa(num_territorios);
    if (mapa == NULL) {
        return 1;
    }
    
    // Inicializar territórios
    int total_cadastrados = 0;
    inicializarTerritorios(mapa, &total_cadastrados, num_territorios);
    
    // NOVO: Criar e atribuir missão ao jogador
    Missao* missao_jogador = criarMissao();
    if (missao_jogador == NULL) {
        liberarMemoria(mapa);
        return 1;
    }
    
    atribuirMissao(missao_jogador, cor_jogador);
    exibirMissao(*missao_jogador); // Passa por VALOR
    
    printf("\nPressione Enter para continuar...");
    limparBuffer();
    getchar();
    
    // Menu principal
    int opcao;
    do {
        limparTela();
        
        printf("╔════════════════════════════════════════╗\n");
        printf("║             MENU PRINCIPAL             ║\n");
        printf("╠════════════════════════════════════════╣\n");
        printf("║ 1. Exibir Mapa                         ║\n");
        printf("║ 2. Atacar Territorio                   ║\n");
        printf("║ 3. Ver Minha Missao                    ║\n");
        printf("║ 0. Sair                                ║\n");
        printf("╚════════════════════════════════════════╝\n");
        printf("\nEscolha: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                exibirMapa(mapa, total_cadastrados);
                pausar();
                break;
                
            case 2: {
                exibirMapa(mapa, total_cadastrados);
                
                int idx_atacante, idx_defensor;
                
                printf("\nIndice do territorio ATACANTE (0-%d): ", total_cadastrados-1);
                if (scanf("%d", &idx_atacante) != 1) {
                    printf("Entrada invalida!\n");
                    limparBuffer();
                    pausar();
                    break;
                }
                
                if (idx_atacante < 0 || idx_atacante >= total_cadastrados) {
                    printf("✗ Indice invalido!\n");
                    pausar();
                    break;
                }
                
                // Validar se o território pertence ao jogador
                if (strcmp(mapa[idx_atacante].cor_do_exercito, cor_jogador) != 0) {
                    printf("✗ Este territorio nao pertence a voce!\n");
                    pausar();
                    break;
                }
                
                printf("Indice do territorio DEFENSOR (0-%d): ", total_cadastrados-1);
                if (scanf("%d", &idx_defensor) != 1) {
                    printf("Entrada invalida!\n");
                    limparBuffer();
                    pausar();
                    break;
                }
                
                if (idx_defensor < 0 || idx_defensor >= total_cadastrados) {
                    printf("✗ Indice invalido!\n");
                    pausar();
                    break;
                }
                
                if (idx_atacante == idx_defensor) {
                    printf("✗ Nao pode atacar o proprio territorio!\n");
                    pausar();
                    break;
                }
                
                // Realizar ataque
                atacar(&mapa[idx_atacante], &mapa[idx_defensor]);
                
                // NOVO: Verificar missão após cada ataque
                if (verificarMissao(missao_jogador, mapa, total_cadastrados, cor_jogador)) {
                    printf("\n╔════════════════════════════════════════╗\n");
                    printf("║   🏆 PARABENS! VOCE VENCEU! 🏆       ║\n");
                    printf("╚════════════════════════════════════════╝\n");
                    exibirMissao(*missao_jogador);
                    pausar();
                    opcao = 0; // Encerrar o jogo
                }
                
                pausar();
                break;
            }
            
            case 3:  // NOVO: Ver missão
                exibirMissao(*missao_jogador);
                pausar();
                break;
            
            case 0:
                printf("\n👋 Encerrando jogo...\n");
                break;
                
            default:
                printf("✗ Opcao invalida!\n");
                pausar();
        }
        
    } while(opcao != 0);
    
    // Liberar memória
    liberarMemoria(mapa);
    liberarMissao(missao_jogador);  // NOVO
    
    printf("\n✓ Obrigado por jogar!\n");
    return 0;
}
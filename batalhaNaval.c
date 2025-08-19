#include <stdio.h>

//Tamanho dos navios e do tabuleiro
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3


int main() {
    
    // Declaração do tabuleiro 10x10, inicializado com 0 (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas iniciais dos navios (linha, coluna)
    int navio1_linha = 2, navio1_coluna = 2; // Navio horizontal
    int navio2_linha = 5, navio2_coluna = 7; // Navio vertical

    // Dois navios diagonais
    int navio3_linha = 4, navio3_coluna = 0; // diagonal principal
    int navio4_linha = 0, navio4_coluna = 9; // diagonal secundária
   
    // Verificação de limites e posicionamento do navio horizontal
    if (navio1_coluna + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[navio1_linha][navio1_coluna + i] == 0) {// Verifica se a posição já está ocupada
                tabuleiro[navio1_linha][navio1_coluna + i] = 3;
            } else {
                printf("Erro: Sobreposição detectada no navio 1!\n");
                return 1;
            }
        }
    } else {
        printf("Erro: Navio 1 ultrapassa os limites do tabuleiro!\n");
    }

    // Verificação de limites e posicionamento do navio vertical
    if (navio2_linha + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[navio2_linha + i][navio2_coluna] == 0) { // Verifica se a posição já está ocupada
                tabuleiro[navio2_linha + i][navio2_coluna] = 3;
            } else {
                printf("Erro: Sobreposição detectada no navio 2!\n");
                return 1;
            }
        }
    } else {
        printf("Erro: Navio 2 ultrapassa os limites do tabuleiro!\n");
        return 1;
    }

    // Navio 3 - diagonal principal
    if (navio3_linha + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        navio3_coluna + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[navio3_linha + i][navio3_coluna + i] == 0) { // Verifica se a posição já está ocupada
                tabuleiro[navio3_linha + i][navio3_coluna + i] = 3;
            } else {
                printf("Erro: Sobreposição detectada no navio 3!\n");
                return 1;
            }
        }
    } else {
        printf("Erro: Navio 3 ultrapassa os limites!\n");
        return 1;
    }

    // Navio 4 - diagonal secundária
    if (navio4_linha + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        navio4_coluna - (TAMANHO_NAVIO - 1) >= 0) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[navio4_linha + i][navio4_coluna - i] == 0) { // Verifica se a posição já está ocupada
                tabuleiro[navio4_linha + i][navio4_coluna - i] = 3;
            } else {
                printf("Erro: Sobreposição detectada no navio 4!\n");
                return 1;
            }
        }
    } else {
        printf("Erro: Navio 4 ultrapassa os limites!\n");
        return 1;
    }

    // Exibição do tabuleiro
    printf("Tabuleiro Batalha Naval:\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]); // Espaço entre valores
        }
        printf("\n"); // Quebra de linha a cada linha do tabuleiro
    }
    
    return 0;
}

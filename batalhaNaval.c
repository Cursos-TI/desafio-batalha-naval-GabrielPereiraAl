#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    
    //Tamanho dos navios e do tabuleiro
    int tamanhoNavio = 3;
    int tamanhoTabuleiro = 10;
    
    // Declaração do tabuleiro 10x10, inicializado com 0 (água)
    int tabuleiro[10][10] = {0};


    // Coordenadas iniciais dos navios (linha, coluna)
    int navio1_linha = 2, navio1_coluna = 4; // Navio horizontal
    int navio2_linha = 5, navio2_coluna = 7; // Navio vertical

   
   
    // Verificação de limites e posicionamento do navio horizontal
    if (navio1_coluna + tamanhoNavio <= tamanhoTabuleiro) {
        for (int i = 0; i < tamanhoNavio; i++) {
            // Verifica se a posição já está ocupada
            if (tabuleiro[navio1_linha][navio1_coluna + i] == 0) {
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
    if (navio2_linha + tamanhoNavio <= tamanhoTabuleiro) {
        for (int i = 0; i < tamanhoNavio; i++) {
            // Verifica se a posição já está ocupada
            if (tabuleiro[navio2_linha + i][navio2_coluna] == 0) {
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

    // Exibição do tabuleiro
    printf("Tabuleiro Batalha Naval:\n\n");
    for (int i = 0; i < tamanhoTabuleiro; i++) {
        for (int j = 0; j < tamanhoTabuleiro; j++) {
            printf("%d ", tabuleiro[i][j]); // Espaço entre valores
        }
        printf("\n"); // Quebra de linha a cada linha do tabuleiro
    }
    
    return 0;
}

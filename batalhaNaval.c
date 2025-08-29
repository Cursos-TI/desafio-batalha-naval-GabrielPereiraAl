#include <stdio.h>

#define TAMANHO_TABULEIRO 20
#define TAMANHO_HABILIDADE 5
#define TAMANHO_NAVIO 3

int main() {
    
    // Inicialiando o "mar"
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Matrizes das habilidades
    int triangulo[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    // Triângulo("Cone")
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            triangulo[i][j] = 0;
            if (i <= TAMANHO_HABILIDADE / 2) {
                if (j >= (TAMANHO_HABILIDADE / 2 - i) &&
                    j <= (TAMANHO_HABILIDADE / 2 + i)) {
                    triangulo[i][j] = 1;
                }
            }
        }
    }

    // Cruz
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            cruz[i][j] = 0;
            if (i == TAMANHO_HABILIDADE / 2 || j == TAMANHO_HABILIDADE / 2) {
                cruz[i][j] = 1;
            }
        }
    }

    // Octaedro (losango)
    int centro = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            octaedro[i][j] = 0;
            int distLinha = (i >= centro) ? (i - centro) : (centro - i);
            int distColuna = (j >= centro) ? (j - centro) : (centro - j);
            if (distLinha + distColuna <= centro) {
                octaedro[i][j] = 1;
            }
        }
    }

    // Pontos de origem das habilidades no tabuleiro
    int origemTrianguloLinha = 5, origemTrianguloColuna = 5;
    int origemCruzLinha = 10, origemCruzColuna = 10;
    int origemOctaedroLinha = 15, origemOctaedroColuna = 15;

    // ---------- Aplicar habilidades ----------
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Triângulo
            if (triangulo[i][j] == 1) {
                int linhaTab = origemTrianguloLinha + (i - centro);
                int colunaTab = origemTrianguloColuna + (j - centro);
                if (linhaTab >= 0 && linhaTab < TAMANHO_TABULEIRO &&
                    colunaTab >= 0 && colunaTab < TAMANHO_TABULEIRO) {
                    tabuleiro[linhaTab][colunaTab] = 5;
                }
            }
            // Cruz
            if (cruz[i][j] == 1) {
                int linhaTab = origemCruzLinha + (i - centro);
                int colunaTab = origemCruzColuna + (j - centro);
                if (linhaTab >= 0 && linhaTab < TAMANHO_TABULEIRO &&
                    colunaTab >= 0 && colunaTab < TAMANHO_TABULEIRO) {
                    tabuleiro[linhaTab][colunaTab] = 5;
                }
            }
            // Octaedro
            if (octaedro[i][j] == 1) {
                int linhaTab = origemOctaedroLinha + (i - centro);
                int colunaTab = origemOctaedroColuna + (j - centro);
                if (linhaTab >= 0 && linhaTab < TAMANHO_TABULEIRO &&
                    colunaTab >= 0 && colunaTab < TAMANHO_TABULEIRO) {
                    tabuleiro[linhaTab][colunaTab] = 5;
                }
            }
        }
    }

    // ---------- Posicionar Navios com validação ----------

    // Novas posições dos navios
    int navio1_linha = 1, navio1_coluna = 1;   // horizontal
    int navio2_linha = 8, navio2_coluna = 3;   // vertical
    int navio3_linha = 12, navio3_coluna = 0;  // diagonal principal
    int navio4_linha = 0, navio4_coluna = 16;  // diagonal secundária

    int podeColocar;

    // Navio 1 - horizontal
    podeColocar = 1;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[navio1_linha][navio1_coluna + i] != 0) {
            podeColocar = 0;
            break;
        }
    }
    if (podeColocar) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[navio1_linha][navio1_coluna + i] = 3;
        }
    } else {
        printf("Erro: navio 1 não pode ser colocado (sobreposição)\n");
    }

    // Navio 2 - vertical
    podeColocar = 1;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[navio2_linha + i][navio2_coluna] != 0) {
            podeColocar = 0;
            break;
        }
    }
    if (podeColocar) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[navio2_linha + i][navio2_coluna] = 3;
        }
    } else {
        printf("Erro: navio 2 não pode ser colocado (sobreposição)\n");
    }

    // Navio 3 - diagonal principal
    podeColocar = 1;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[navio3_linha + i][navio3_coluna + i] != 0) {
            podeColocar = 0;
            break;
        }
    }
    if (podeColocar) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[navio3_linha + i][navio3_coluna + i] = 3;
        }
    } else {
        printf("Erro: navio 3 não pode ser colocado (sobreposição)\n");
    }

    // Navio 4 - diagonal secundária
    podeColocar = 1;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[navio4_linha + i][navio4_coluna - i] != 0) {
            podeColocar = 0;
            break;
        }
    }
    if (podeColocar) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[navio4_linha + i][navio4_coluna - i] = 3;
        }
    } else {
        printf("Erro: navio 4 não pode ser colocado (sobreposição)\n");
    }

    // ---------- Imprimir tabuleiro ----------
    printf("Legenda: 0=Água, 3=Navio, 5=Habilidade\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

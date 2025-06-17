#include <stdio.h>
#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5

// Inicializa o tabuleiro com 0 (água)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
            tabuleiro[i][j] = 0;
}

// Posiciona manualmente alguns navios para efeito visual
void posicionarNavios(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Horizontal
    for (int i = 1; i <= 3; i++)
        tabuleiro[0][i] = 3;

    // Vertical
    for (int i = 4; i <= 6; i++)
        tabuleiro[i][5] = 3;
}

// Cria matriz cone com centro no topo
void criarCone(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (j >= (TAMANHO_HABILIDADE / 2 - i) && j <= (TAMANHO_HABILIDADE / 2 + i))
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

// Cria matriz em forma de cruz
void criarCruz(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int meio = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == meio || j == meio)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

// Cria matriz em forma de octaedro (losango)
void criarOctaedro(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int meio = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (abs(i - meio) + abs(j - meio) <= meio)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

// Aplica a matriz de habilidade sobre o tabuleiro com base no ponto de origem
void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                       int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE],
                       int origemLinha, int origemColuna) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linhaTab = origemLinha + i - TAMANHO_HABILIDADE / 2;
            int colunaTab = origemColuna + j - TAMANHO_HABILIDADE / 2;

            // Valida se está dentro do tabuleiro
            if (linhaTab >= 0 && linhaTab < TAMANHO_TABULEIRO &&
                colunaTab >= 0 && colunaTab < TAMANHO_TABULEIRO) {

                if (habilidade[i][j] == 1 && tabuleiro[linhaTab][colunaTab] == 0)
                    tabuleiro[linhaTab][colunaTab] = 5;
            }
        }
    }
}

// Imprime o tabuleiro com caracteres visuais
void imprimirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            switch (tabuleiro[i][j]) {
                case 0: printf("~ "); break;  // água
                case 3: printf("N "); break;  // navio
                case 5: printf("* "); break;  // habilidade
                default: printf("? "); break;
            }
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);

    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Define pontos de origem para aplicar habilidades
    aplicarHabilidade(tabuleiro, cone, 2, 2);       // Cone no topo-esquerdo
    aplicarHabilidade(tabuleiro, cruz, 5, 5);       // Cruz no centro
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);   // Octaedro no canto inferior

    imprimirTabuleiro(tabuleiro);

    return 0;
}

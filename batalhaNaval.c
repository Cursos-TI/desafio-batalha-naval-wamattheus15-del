#include <stdio.h>

#define TAM 5
#define NAVIO 1
#define AGUA  0

void zeraMatriz(int m[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            m[i][j] = AGUA;
}

void posicionaNavio(int m[TAM][TAM], int linha, int coluna, int tamanho, char orientacao) {
    if (orientacao == 'H') {
        for (int j = 0; j < tamanho; j++) m[linha][coluna + j] = NAVIO;
    } else {
        for (int i = 0; i < tamanho; i++) m[linha + i][coluna] = NAVIO;
    }
}

void imprimeCoordenadas(int m[TAM][TAM]) {
    printf("Coordenadas dos navios:\n");
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            if (m[i][j] == NAVIO) printf("Navio em (%d,%d)\n", i, j);
}

void imprimeTabuleiro(int m[TAM][TAM]) {
    printf("\nTabuleiro %dx%d:\n", TAM, TAM);
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) printf("%d ", m[i][j]);
        printf("\n");
    }
}

int main(void) {
    int tabuleiro[TAM][TAM];
    zeraMatriz(tabuleiro);

    // === ENTRADA (valores colocados aqui no código) ===
    // navio 1: horizontal, começa na linha 1 coluna 1, tamanho 3
    posicionaNavio(tabuleiro, 1, 1, 3, 'H');
    // navio 2: vertical, começa na linha 2 coluna 4, tamanho 3
    posicionaNavio(tabuleiro, 2, 4, 3, 'V');

    // === SAÍDA ===
    imprimeCoordenadas(tabuleiro);
    imprimeTabuleiro(tabuleiro);
    return 0;
}

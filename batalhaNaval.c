#include <stdio.h>
#include <stdbool.h>

// Constantes do jogo
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA '0'
#define NAVIO '3'

// Tipos de orientação para os navios
typedef enum {
    HORIZONTAL,
    VERTICAL,
    DIAGONAL_PRINCIPAL,
    DIAGONAL_SECUNDARIA
} Orientacao;

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para verificar se a posição do navio é válida
bool posicaoValida(int linha, int coluna, Orientacao orientacao, char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Verifica limites do tabuleiro
    if (linha < 0 || coluna < 0 || linha >= TAMANHO_TABULEIRO || coluna >= TAMANHO_TABULEIRO) {
        return false;
    }

    // Verifica posições baseado na orientação
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha, c = coluna;
        
        switch (orientacao) {
            case HORIZONTAL: c += i; break;
            case VERTICAL: l += i; break;
            case DIAGONAL_PRINCIPAL: l += i; c += i; break;
            case DIAGONAL_SECUNDARIA: l += i; c -= i; break;
        }

        // Verifica se está dentro do tabuleiro
        if (l < 0 || l >= TAMANHO_TABULEIRO || c < 0 || c >= TAMANHO_TABULEIRO) {
            return false;
        }

        // Verifica se não há colisão com outro navio
        if (tabuleiro[l][c] != AGUA) {
            return false;
        }
    }

    return true;
}

// Função para posicionar um navio no tabuleiro
void posicionarNavio(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, Orientacao orientacao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha, c = coluna;
        
        switch (orientacao) {
            case HORIZONTAL: c += i; break;
            case VERTICAL: l += i; break;
            case DIAGONAL_PRINCIPAL: l += i; c += i; break;
            case DIAGONAL_SECUNDARIA: l += i; c -= i; break;
        }

        tabuleiro[l][c] = NAVIO;
    }
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n   A B C D E F G H I J\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    // Posiciona 4 navios (2 retos e 2 diagonais)
    printf("Posicionando navios...\n");
    
    // Navio horizontal (linha 1, coluna B)
    if (posicaoValida(1, 1, HORIZONTAL, tabuleiro)) {
        posicionarNavio(tabuleiro, 1, 1, HORIZONTAL);
        printf("- Navio horizontal posicionado em B2-D2\n");
    }

    // Navio vertical (linha 3, coluna F)
    if (posicaoValida(3, 5, VERTICAL, tabuleiro)) {
        posicionarNavio(tabuleiro, 3, 5, VERTICAL);
        printf("- Navio vertical posicionado em F4-F6\n");
    }

    // Navio diagonal principal (linha 5, coluna C)
    if (posicaoValida(5, 2, DIAGONAL_PRINCIPAL, tabuleiro)) {
        posicionarNavio(tabuleiro, 5, 2, DIAGONAL_PRINCIPAL);
        printf("- Navio diagonal (\\\) posicionado em C6-E8\n");
    }

    // Navio diagonal secundária (linha 2, coluna H)
    if (posicaoValida(2, 7, DIAGONAL_SECUNDARIA, tabuleiro)) {
        posicionarNavio(tabuleiro, 2, 7, DIAGONAL_SECUNDARIA);
        printf("- Navio diagonal (/) posicionado em H3-F5\n");
    }

    // Exibe o tabuleiro completo
    printf("\nTabuleiro de Batalha Naval:\n");
    imprimirTabuleiro(tabuleiro);

    return 0;
}
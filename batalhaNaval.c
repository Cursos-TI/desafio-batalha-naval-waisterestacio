#include <stdio.h>
#include <stdbool.h>

// Tamanho do tabuleiro
#define TAMANHO_TABULEIRO 10
// Tamanho dos navios
#define TAMANHO_NAVIO 3

// Função para inicializar o tabuleiro com 0s (água)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para verificar se a posição do navio é válida
bool posicaoValida(int linha, int coluna, int tamanho, bool vertical, int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Verifica se está dentro dos limites do tabuleiro
    if (linha < 0 || coluna < 0) return false;
    
    if (vertical) {
        if (linha + tamanho - 1 >= TAMANHO_TABULEIRO) return false;
    } else {
        if (coluna + tamanho - 1 >= TAMANHO_TABULEIRO) return false;
    }
    
    // Verifica se não há sobreposição com outros navios
    for (int i = 0; i < tamanho; i++) {
        if (vertical) {
            if (tabuleiro[linha + i][coluna] != 0) return false;
        } else {
            if (tabuleiro[linha][coluna + i] != 0) return false;
        }
    }
    
    return true;
}

// Função para posicionar um navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, bool vertical) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (vertical) {
            tabuleiro[linha + i][coluna] = 3;
        } else {
            tabuleiro[linha][coluna + i] = 3;
        }
    }
}

// Função para imprimir o tabuleiro com colunas em letras
void imprimirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro de Batalha Naval:\n");
    printf("   A B C D E F G H I J\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i+1);  // Linhas numeradas de 1 a 10
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Declaração do tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    
    // Inicializa o tabuleiro com água (0s)
    inicializarTabuleiro(tabuleiro);
    
    // Posições dos navios (definidas no código)
    // Navio horizontal: linha 2 (índice 1), coluna C (índice 2)
    int linha_horizontal = 1, coluna_horizontal = 2;
    // Navio vertical: linha 6 (índice 5), coluna H (índice 7)
    int linha_vertical = 5, coluna_vertical = 7;
    
    // Verifica se as posições são válidas
    if (!posicaoValida(linha_horizontal, coluna_horizontal, TAMANHO_NAVIO, false, tabuleiro)) {
        printf("Posição inválida para o navio horizontal!\n");
        return 1;
    }
    
    if (!posicaoValida(linha_vertical, coluna_vertical, TAMANHO_NAVIO, true, tabuleiro)) {
        printf("Posição inválida para o navio vertical!\n");
        return 1;
    }
    
    // Posiciona os navios no tabuleiro
    posicionarNavio(tabuleiro, linha_horizontal, coluna_horizontal, false); // Navio horizontal
    posicionarNavio(tabuleiro, linha_vertical, coluna_vertical, true);     // Navio vertical
    
    // Imprime o tabuleiro
    imprimirTabuleiro(tabuleiro);
    
    return 0;
}
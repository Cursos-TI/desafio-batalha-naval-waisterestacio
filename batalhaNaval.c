#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Constantes do jogo
#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define TAM_HABILIDADE 5
#define AGUA '0'
#define NAVIO '3'
#define HABILIDADE '5'

// Tipos de habilidades
typedef enum {
    CONE,
    CRUZ,
    OCTAEDRO
} TipoHabilidade;

// Estrutura para representar uma habilidade
typedef struct {
    TipoHabilidade tipo;
    int linha;
    int coluna;
} Habilidade;

// Protótipos de funções
void inicializarTabuleiro(char tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]);
void posicionarNavios(char tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]);
void criarMatrizHabilidade(char matriz[TAM_HABILIDADE][TAM_HABILIDADE], TipoHabilidade tipo);
void aplicarHabilidade(char tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], Habilidade habilidade);
void imprimirTabuleiro(char tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]);

int main() {
    char tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    
    // Inicializa e posiciona navios
    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);
    
    // Define habilidades
    Habilidade habilidades[3] = {
        {CONE, 2, 2},     // Cone na posição (2,2)
        {CRUZ, 5, 5},     // Cruz na posição (5,5)
        {OCTAEDRO, 7, 7}  // Octaedro na posição (7,7)
    };
    
    // Aplica habilidades
    for (int i = 0; i < 3; i++) {
        aplicarHabilidade(tabuleiro, habilidades[i]);
    }
    
    // Exibe o tabuleiro final
    imprimirTabuleiro(tabuleiro);
    
    return 0;
}

// Inicializa o tabuleiro com água
void inicializarTabuleiro(char tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Posiciona os navios no tabuleiro
void posicionarNavios(char tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    // Navio horizontal (linha 1, coluna B)
    for (int j = 1; j < 1 + TAM_NAVIO; j++) {
        tabuleiro[1][j] = NAVIO;
    }
    
    // Navio vertical (coluna F, linhas 4-6)
    for (int i = 4; i < 4 + TAM_NAVIO; i++) {
        tabuleiro[i][5] = NAVIO;
    }
}

// Cria a matriz de padrão para cada habilidade
void criarMatrizHabilidade(char matriz[TAM_HABILIDADE][TAM_HABILIDADE], TipoHabilidade tipo) {
    int centro = TAM_HABILIDADE / 2;
    
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            matriz[i][j] = '0'; // Inicializa com 0
            
            switch (tipo) {
                case CONE:
                    // Padrão de cone (triângulo apontando para baixo)
                    if (i >= centro && j >= (centro - (i - centro)) && j <= (centro + (i - centro))) {
                        matriz[i][j] = '1';
                    }
                    break;
                    
                case CRUZ:
                    // Padrão de cruz (linha vertical + horizontal)
                    if (i == centro || j == centro) {
                        matriz[i][j] = '1';
                    }
                    break;
                    
                case OCTAEDRO:
                    // Padrão de octaedro (losango)
                    if (abs(i - centro) + abs(j - centro) <= centro) {
                        matriz[i][j] = '1';
                    }
                    break;
            }
        }
    }
}

// Aplica uma habilidade ao tabuleiro
void aplicarHabilidade(char tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], Habilidade habilidade) {
    char matriz[TAM_HABILIDADE][TAM_HABILIDADE];
    criarMatrizHabilidade(matriz, habilidade.tipo);
    
    int centro = TAM_HABILIDADE / 2;
    int linha_inicio = habilidade.linha - centro;
    int coluna_inicio = habilidade.coluna - centro;
    
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int linha_tab = linha_inicio + i;
            int coluna_tab = coluna_inicio + j;
            
            // Verifica se está dentro dos limites do tabuleiro
            if (linha_tab >= 0 && linha_tab < TAM_TABULEIRO && 
                coluna_tab >= 0 && coluna_tab < TAM_TABULEIRO) {
                
                // Se for parte da habilidade, marca no tabuleiro
                if (matriz[i][j] == '1') {
                    tabuleiro[linha_tab][coluna_tab] = HABILIDADE;
                }
            }
        }
    }
}

// Imprime o tabuleiro formatado
void imprimirTabuleiro(char tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("\nTabuleiro de Batalha Naval com Habilidades:\n");
    printf("   A B C D E F G H I J\n");
    
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    printf("\nLegenda:\n");
    printf("0 - Água\n");
    printf("3 - Navio\n");
    printf("5 - Área de habilidade\n");
}
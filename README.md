# Batalha Naval - Posicionamento de Navios

Um programa em C que simula o estágio inicial do jogo Batalha Naval, posicionando navios em um tabuleiro 10×10.

## Funcionalidades

**1. Sistema Básico de Tabuleiro**
  - Tabuleiro 10x10: Representação clássica do jogo Batalha Naval com coordenadas (A-J para colunas, 1-10 para linhas)

  - Sistema de Posicionamento:

    - Navios posicionados automaticamente no início do jogo

    - Dois navios padrão (um horizontal e um vertical) de tamanho 3

**2. Habilidades Especiais com Áreas de Efeito**
O jogo implementa três tipos distintos de habilidades especiais:

**a) Habilidade em Cone**
  - Formato: Triangular, expandindo-se para baixo a partir do ponto de origem

  - Características:

    - Efeito se amplia progressivamente

    - Ideal para ataques direcionais

    - Representação matricial calculada dinamicamente

**b) Habilidade em Cruz**
  - Formato: Linhas vertical e horizontal que se cruzam no centro

  - Características:

    - Efeito em formato de "+"

    - Cobre uma linha reta em duas direções

    - Área de efeito simétrica

**c) Habilidade em Octaedro (Losango)**
  - Formato: Diamante centrado no ponto médio

  - Características:

    - Efeito radial equilibrado

    - Cobertura uniforme em todas as direções diagonais

    - Área de efeito compacta mas poderosa

## Exemplo de saída

```
Tabuleiro de Batalha Naval com Habilidades:
   A B C D E F G H I J
 1 0 0 0 0 0 0 0 0 0 0 
 2 0 3 3 3 0 0 0 0 0 0 
 3 0 0 5 0 0 0 0 0 0 0 
 4 0 0 5 5 5 0 0 0 0 0 
 5 0 0 0 5 0 3 5 0 0 0 
 6 0 0 0 0 3 5 3 0 0 0 
 7 0 0 0 0 0 3 0 5 0 0 
 8 0 0 0 0 0 0 5 5 5 0 
 9 0 0 0 0 0 0 0 5 0 0 
10 0 0 0 0 0 0 0 0 0 0 

Legenda:
0 - Água
3 - Navio
5 - Área de habilidade
```

## Como Compilar e Executar

   ```bash
   gcc batalhaNaval.c -o batalhaNaval
   ./batalhaNaval

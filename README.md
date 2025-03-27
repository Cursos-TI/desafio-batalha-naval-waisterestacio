# Batalha Naval - Posicionamento de Navios

Um programa em C que simula o estágio inicial do jogo Batalha Naval, posicionando navios em um tabuleiro 10×10.

## Funcionalidades

- Tabuleiro 10×10 com colunas identificadas por letras (A-J) e linhas por números (1-10)
- Posicionamento automático de:
  - 1 navio horizontal (tamanho 3)
  - 1 navio vertical (tamanho 3)
- Visualização clara do tabuleiro com marcação de navios

## Exemplo de Uso

```
Tabuleiro de Batalha Naval:
   A B C D E F G H I J
 1 0 0 0 0 0 0 0 0 0 0 
 2 0 0 3 3 3 0 0 0 0 0 
 3 0 0 0 0 0 0 0 0 0 0 
 4 0 0 0 0 0 0 0 0 0 0 
 5 0 0 0 0 0 0 0 0 0 0 
 6 0 0 0 0 0 0 0 3 0 0 
 7 0 0 0 0 0 0 0 3 0 0 
 8 0 0 0 0 0 0 0 3 0 0 
 9 0 0 0 0 0 0 0 0 0 0 
10 0 0 0 0 0 0 0 0 0 0 
```

## Como Compilar e Executar

   ```bash
   gcc batalhaNaval.c -o batalhaNaval
   ./batalhaNaval

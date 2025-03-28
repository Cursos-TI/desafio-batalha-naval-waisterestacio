# Batalha Naval - Posicionamento de Navios

Um programa em C que simula o estágio inicial do jogo Batalha Naval, posicionando navios em um tabuleiro 10×10.

## Funcionalidades

- Tabuleiro 10×10 com sistema de coordenadas (A-J, 1-10)
- Posicionamento automático de 4 navios:
  - 1 navio horizontal (tamanho 3)
  - 1 navio vertical (tamanho 3)
  - 1 navio diagonal principal (\) (tamanho 3)
  - 1 navio diagonal secundária (/) (tamanho 3)
- Sistema avançado de validação:
  - Verificação de limites do tabuleiro
  - Prevenção de sobreposição de navios
  - Suporte a posicionamento diagonal

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

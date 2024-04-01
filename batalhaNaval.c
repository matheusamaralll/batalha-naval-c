#include <stdio.h>
#include <stdlib.h>

#define LINHAS 20
#define COLUNAS 20
#define TAM_NAVIO 5

void limparTela() {
    system("clear");
}

void imprimirMatriz(char matriz[LINHAS][COLUNAS], int jogador) {
    int i, j;

    printf("   ");
    for (j = 0; j < COLUNAS; j++) {
        if (j < 10) {
            printf("%2d ", j + 1);
        } else {
            printf("%2d ", j + 1);
        }
    }
    printf("\n");

    for (i = 0; i < LINHAS; i++) {
        printf(" %c ", 'A' + i);
        for (j = 0; j < COLUNAS; j++) {
            if (jogador == 2 && matriz[i][j] == '=') {
                printf(" %c ", '~');
            } else {
                printf(" %c ", matriz[i][j]);
            }
        }
        printf("\n");
    }
}

void colocarNavios(char matriz[LINHAS][COLUNAS]) {
    int naviosColocados = 0;
    int i, j,coluna;
    char orientacao,linha,limpa;

    while (naviosColocados < 3) {
        printf("Posicione os seus navios:\n");
        imprimirMatriz(matriz, 1);

        printf("\nNavio %d - Tamanho: %d\n", naviosColocados + 1, TAM_NAVIO);
        printf("Digite a linha (A-%c): ", 'A' + LINHAS - 1);
        scanf(" %c", &linha);
        linha -= 'A';
        printf("Digite a coluna (1-%d): ", COLUNAS);
        scanf("%d", &coluna);
        coluna--;
        printf("Digite a orientacao (H-horizontal, V-vertical): ");
        scanf(" %c", &orientacao);

        if (orientacao == 'H' || orientacao == 'h') {
            if (coluna + TAM_NAVIO > COLUNAS) {
                printf("\nPosicao invalida! Tente novamente.\n");
                continue;
            }
            for (j = coluna; j < coluna + TAM_NAVIO; j++) {
                if (matriz[linha][j] != '~') {
                    printf("\nPosicao ocupada! Tente novamente.\n");
                    break;
                }
            }
            if (j == coluna + TAM_NAVIO) {
                for (j = coluna; j < coluna + TAM_NAVIO; j++) {
                    matriz[linha][j] = '=';
                }
                naviosColocados++;
            }
        } else if (orientacao == 'V' || orientacao == 'v') {
            if (linha + TAM_NAVIO > LINHAS) {
                printf("\nPosicao invalida! Tente novamente.\n");
                continue;
            }
            for (i = linha; i < linha + TAM_NAVIO; i++) {
                if (matriz[i][coluna] != '~') {
                    printf("\nPosicao ocupada! Tente novamente.\n");
                    break;
                }
            }
            if (i == linha + TAM_NAVIO) {
                for (i = linha; i < linha + TAM_NAVIO; i++) {
                    matriz[i][coluna] = '=';
                }
                naviosColocados++;
            }
        } else {
            printf("\nOrientacao invalida! Tente novamente.\n");
        }
    }
  printf("Navios posicionados! Digite L para limpar a tela: ");
  scanf(" %c", &limpa);
  if (limpa == 'L' || limpa == 'l') {
    system("clear");
  }
}

int turnoJogador1(char matriz[LINHAS][COLUNAS]) {
    int tirosDados = 0;
    int acertos = 0;
    int i, j, coluna;
    char linha;

    while (tirosDados < 30 && acertos < 3 * TAM_NAVIO) {
        printf("Jogador 1, efetue um disparo:\n");
        imprimirMatriz(matriz, 2);

        printf("\nDisparo %d - Tiros restantes: %d\n", tirosDados + 1, 30 - tirosDados);
        printf("Digite a linha (A-%c): ", 'A' + LINHAS - 1);
        scanf(" %c", &linha);
        linha -= 'A';
        printf("Digite a coluna (1-%d): ", COLUNAS);
        scanf("%d", &coluna);
        coluna--;

        if (matriz[linha][coluna] == '=') {
            printf("\nAcertou!\n");
            matriz[linha][coluna] = 'X';
            acertos++;
        } else if (matriz[linha][coluna] != 'X') {
            printf("\nErrou!\n");
            matriz[linha][coluna] = '*';
        } else {
            printf("\nPosicao ja disparada! Tente novamente.\n");
        }
        tirosDados++;
    }
    return acertos;
}

int turnoJogador2(char matriz[LINHAS][COLUNAS]) {
    int tirosDados = 0;
    int acertos = 0;
    int i, j, coluna;
    char linha;

    while (tirosDados < 30 && acertos < 3 * TAM_NAVIO) {
        printf("Jogador 2, efetue um disparo:\n");
        imprimirMatriz(matriz, 2);

        printf("\nDisparo %d - Tiros restantes: %d\n", tirosDados + 1, 30 - tirosDados);
        printf("Digite a linha (A-%c): ", 'A' + LINHAS - 1);
        scanf(" %c", &linha);
        linha -= 'A';
        printf("Digite a coluna (1-%d): ", COLUNAS);
        scanf("%d", &coluna);
        coluna--;

        if (matriz[linha][coluna] == '=') {
            printf("\nAcertou!\n");
            matriz[linha][coluna] = 'X';
            acertos++;
        } else if (matriz[linha][coluna] != 'X') {
            printf("\nErrou!\n");
            matriz[linha][coluna] = '*';
        } else {
            printf("\nPosicao ja disparada! Tente novamente.\n");
        }
        tirosDados++;
    }
    return acertos;
}

int main() {
    char matriz[LINHAS][COLUNAS];
    char jogarNovamente = 's';
    char jogador1[20];
    char jogador2[20];
    int rodadasJogador1 = 0;
    int rodadasJogador2 = 0;
    int naviosDestruidosJogador1 = 0;
    int naviosDestruidosJogador2 = 0;
    int posicoesAcertadasJogador1 = 0;
    int posicoesAcertadasJogador2 = 0;

    while (jogarNovamente == 's' || jogarNovamente == 'S') {
        int acertosJogador1;
        int acertosJogador2;
      
        limparTela();
        printf("===BATALHA NAVAL===\n");
        printf("Digite o nome do Jogador 1: ");
        scanf("%s", jogador1);
        printf("Digite o nome do Jogador 2: ");
        scanf("%s", jogador2);

        int jogadorAtual = 1;

        do {
            int i, j;
            for (i = 0; i < LINHAS; i++) {
                for (j = 0; j < COLUNAS; j++) {
                    matriz[i][j] = '~';
                }
            }

            if (jogadorAtual == 1) {
                limparTela();
                printf("%s, posicione os seus navios.\n", jogador1);
                colocarNavios(matriz);                             
                for (i = 0; i < LINHAS; i++) {
                    for (j = 0; j < COLUNAS; j++) {
                        if (matriz[i][j] != '=') {
                            matriz[i][j] = '~';
                        }
                    }
                }
                acertosJogador2 = turnoJogador2(matriz);
                limparTela();
                printf("Jogo finalizado!\n\n");
              
                if (acertosJogador2 == 3 * TAM_NAVIO) {
                  if (jogadorAtual == 1) {
                    printf("Parabens, %s! Voce venceu esta rodada no ataque!\n", jogador2);
                    rodadasJogador2++;
                    naviosDestruidosJogador2 += 3;
                    posicoesAcertadasJogador2 += acertosJogador2;
                  } else {
                    printf("Parabens, %s! Voce venceu esta rodada no ataque!\n", jogador1);
                    rodadasJogador1++;
                    naviosDestruidosJogador1 += 3;
                    posicoesAcertadasJogador1 += acertosJogador2;
                  }
                } else {
                  if (jogadorAtual == 1) {
                    printf("Parabens, %s! Voce venceu esta rodada na defesa!\n", jogador1);
                    rodadasJogador1++;
                    posicoesAcertadasJogador2 += acertosJogador2;
                    naviosDestruidosJogador2 += acertosJogador2/TAM_NAVIO;
                  } else {
                    printf("Parabens, %s! Voce venceu esta rodada na defesa!\n", jogador2);
                    rodadasJogador2++;
                    posicoesAcertadasJogador1 += acertosJogador1;
                    naviosDestruidosJogador1 += acertosJogador1/TAM_NAVIO;
                  }
                }
                jogadorAtual = 2;
            } else {
                limparTela();
                printf("%s, posicione os seus navios.\n", jogador2);
                colocarNavios(matriz);
                
                for (i = 0; i < LINHAS; i++) {
                    for (j = 0; j < COLUNAS; j++) {
                        if (matriz[i][j] != '=') {
                            matriz[i][j] = '~';
                        }
                    }
                }
                acertosJogador1 = turnoJogador1(matriz);
                limparTela();
                printf("Jogo finalizado!\n\n");

                if (acertosJogador1 == 3 * TAM_NAVIO) {
                  if (jogadorAtual == 2) {
                    printf("Parabens, %s! Voce venceu esta rodada no ataque!\n", jogador1);
                    rodadasJogador1++;
                    naviosDestruidosJogador1 += 3;
                    posicoesAcertadasJogador1 += acertosJogador1;
                  } else {
                    printf("Parabens, %s! Voce venceu esta rodada no ataque!\n", jogador2);
                    rodadasJogador2++;
                    naviosDestruidosJogador2 += 3;
                    posicoesAcertadasJogador2 += acertosJogador1;
                  }
                } else {
                  if (jogadorAtual == 2) {
                    printf("Parabens, %s! Voce venceu esta rodada na defesa!\n", jogador2);
                    rodadasJogador2++;
                    posicoesAcertadasJogador1 += acertosJogador1;
                    naviosDestruidosJogador1 += acertosJogador1/TAM_NAVIO;
                  } else {
                    printf("Parabens, %s! Voce venceu esta rodada na defesa!\n", jogador1);
                    rodadasJogador1++;
                    posicoesAcertadasJogador2 += acertosJogador2;
                    naviosDestruidosJogador2 += acertosJogador2/TAM_NAVIO;
                  }
                }
                jogadorAtual = 1;
            }
            printf("\nEstatisticas:\n");
            printf("%s:\n", jogador1);
            printf("  Rodadas ganhas: %d\n", rodadasJogador1);
            printf("  Navios destruidos: %d\n", naviosDestruidosJogador1);
            printf("  Posicoes acertadas: %d\n", posicoesAcertadasJogador1);
            printf("%s:\n", jogador2);
            printf("  Rodadas ganhas: %d\n", rodadasJogador2);
            printf("  Navios destruidos: %d\n", naviosDestruidosJogador2);
            printf("  Posicoes acertadas: %d\n", posicoesAcertadasJogador2);

            printf("\nJogar novamente (S-sim, N-nao)? ");
            scanf(" %c", &jogarNovamente);
        } while (jogarNovamente == 's' || jogarNovamente == 'S');
    }
    return 0;
}

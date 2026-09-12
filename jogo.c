#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void imprimirTabuleiro(int tabuleiro[3][3]);
bool menu();

int main() {
    int tabuleiro[3][3] = {0};
    int vez = 1;
    bool continuar = true;
    int x, y;
    int jogadas = 0;
    int ganhou = 0;
    bool limpar = true;

    if (menu()) {
        while (jogadas < 9 && ganhou == 0) {
            if(limpar) system("clear");
            imprimirTabuleiro(tabuleiro);
            limpar = true;

            printf("Jogador %d, digite a linha (1, 2 ou 3): ", vez);
            scanf(" %d", &x);

            printf("Jogador %d, digite a coluna (1, 2 ou 3): ", vez);
            scanf(" %d", &y);

            if (x >= 1 && x < 4 && y >= 1 && y < 4 && tabuleiro[x-1][y-1] == 0) {
                x = x-1;
                y = y-1;

                tabuleiro[x][y] = vez;
                jogadas++;

                for (int i = 0; i < 3; i++) {
                    if (tabuleiro[i][0] == vez && tabuleiro[i][1] == vez && tabuleiro[i][2] == vez) ganhou = vez;
                    if (tabuleiro[0][i] == vez && tabuleiro[1][i] == vez && tabuleiro[2][i] == vez) ganhou = vez;
                }
                if (tabuleiro[0][0] == vez && tabuleiro[1][1] == vez && tabuleiro[2][2] == vez) ganhou = vez;
                if (tabuleiro[0][2] == vez && tabuleiro[1][1] == vez && tabuleiro[2][0] == vez) ganhou = vez;

                if (vez == 1) {
                    vez = 2;
                } else {
                    vez = 1;
                }
            } else {
                system("clear");
                limpar = false;
                printf("Jogada invalida!\n");
            }
        }

        imprimirTabuleiro(tabuleiro);

        if (ganhou != 0) {
            system("clear");
            printf("Jogador %d ganhou!\n", ganhou);
        } else {
            system("clear");
            printf("Empate!\n");
        }
    }

    return 0;
}

void imprimirTabuleiro(int tabuleiro[3][3]) {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == 0) printf("   ");
            if (tabuleiro[i][j] == 1) printf(" X ");
            if (tabuleiro[i][j] == 2) printf(" O ");
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) {
            printf("-----------\n");
        }
    }
}

bool menu() {
    int opcao;
    puts("Deseja jogar um jogo novo ou sair?\n");
    puts("1. JOGAR\n2. SAIR");
    scanf("%d", &opcao);

    if (opcao == 1) {
        return true;
    } else {
        return false;
    }
}
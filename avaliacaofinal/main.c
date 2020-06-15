#include <stdio.h>
#define TOTAL_COLUNAS 5
#define TOTAL_LINHAS 3

/**
 * Elias Meireles Ferreira
 * */

int calcularDiagonais(int matriz[TOTAL_LINHAS][TOTAL_COLUNAS], char *diagonal);

int matrizInversao(int matriz[TOTAL_LINHAS][TOTAL_COLUNAS]);

int main() {
    int matriz[TOTAL_LINHAS][TOTAL_COLUNAS] = {{0, 0, 0, 0, 0},
                                               {0, 0, 0, 0, 0},
                                               {0, 0, 0, 0, 0}};

//    int matriz[TOTAL_LINHAS][TOTAL_COLUNAS] = {{1,  3, 5,  0, 0},
//                                               {2,  4, 1,  0, 0},
//                                               {-4, 1, -1, 0, 0}};

    for (int i = 0; i < TOTAL_LINHAS; ++i) {
        for (int j = 0; j < TOTAL_LINHAS; ++j) {
            printf("Informe o valor para a matriz[%d][%d]: ", i, j);
            fflush(stdin);
            scanf("%d", &matriz[i][j]);
        }
    }

    /// Copia os valores da primeira e da segunda coluna da matriz
    /// para a penultima e ultima coluna
    for (int k = 0; k < TOTAL_COLUNAS; ++k) {
        for (int i = 0; i < 2; ++i) {
            matriz[k][i + TOTAL_COLUNAS - 2] = matriz[k][i];
        }
    }

    int resultadoDiagonaisPrincipais = calcularDiagonais(matriz, "principal");
    int resultadoDiagonaisSecundarias = matrizInversao(matriz);

    printf("\n\nDeterminante: %d\n", resultadoDiagonaisPrincipais + resultadoDiagonaisSecundarias);
    return 0;
}

/// Extrai a diagonais da matriz e retorna o resulta da soma das diagonais encontradas
int calcularDiagonais(int matriz[TOTAL_LINHAS][TOTAL_COLUNAS], char *tipoDeDiagonal) {
    printf("\n");

    /// Imprie a matriz com os valores informados mais o
    /// complemento das duas ultimas colunas
    for (int i = 0; i < TOTAL_LINHAS; ++i) {
        for (int j = 0; j < TOTAL_COLUNAS; ++j) {
            printf("| %d ", matriz[i][j]);
        }
        printf("| \n");
    }

    int resultado[3] = {1, 1, 1};

    printf("\nExtraindo diagonais...\n");
    int diagonal[3];

    printf("Diagonal %s: ", tipoDeDiagonal);

    /// Extrai o e calcula o valor de cada diagonal
    for (int i = 0; i < TOTAL_LINHAS; ++i) {
        int resultadoDiagonal = matriz[0][i];
        diagonal[i] = matriz[0][i];
        printf("%d * ",matriz[0][i]);

        for (int j = i + 1; j < i + TOTAL_LINHAS; ++j) {
            printf("%d", matriz[j - i][j]);
            resultadoDiagonal *= matriz[j - i][j];
            if (j - i != TOTAL_LINHAS - 1) {
                printf(" * ");
            }
        }
        resultado[i] = resultadoDiagonal;
        printf(" --> (%d)", resultado[i]);

        if (i < TOTAL_LINHAS - 1) {
            printf("\nDiagonal paralela (%d): ", i + 1);
        }
    }

    int resultadoCalculo = 0;

    /// Soma os valores das diagonais encontradas
    for (int i = 0; i < TOTAL_LINHAS; ++i) {
        resultadoCalculo += resultado[i];
    }

    return resultadoCalculo;
}

/// Inverte a posição dos valores das linha
int matrizInversao(int matriz[TOTAL_LINHAS][TOTAL_COLUNAS]) {
    int linhaIndex = 0;
    int matrizReversa[TOTAL_LINHAS][TOTAL_COLUNAS];

    printf("\n\nInvertendo matriz\n");

    /// Preenche a matrizReversa com os valor da
    /// matriz de traz pra frente em suas linhas
    for (int l = TOTAL_LINHAS; l > 0; --l) {
        int conlunaIndex = 0;
        for (int i = TOTAL_COLUNAS; i > 0; --i) {
            matrizReversa[linhaIndex][conlunaIndex] = matriz[linhaIndex][i - 1];
            conlunaIndex++;
        }
        linhaIndex++;
    }

    return calcularDiagonais(matrizReversa, "secundaria") * -1;
}

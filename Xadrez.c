#include <stdio.h>

/*
  movimentos de peças de xadrez 
 - Torre: 5 casas para a direita (usando for)
 - Bispo: 5 casas na diagonal para cima e à direita (usando while)
 - Rainha: 8 casas para a esquerda (usando do-while)
 
 Requisitos atendidos:
 - Entradas definidas por constantes inteiras no código.
 - Cada peça usa uma estrutura de repetição diferente.
 - Imprime a direção a cada casa percorrida.
 - Código documentado e legível.
 
*/

int main(void) {
    /* Número de casas a mover (definidos diretamente no código) */
    const int TORRE_CASAS = 5;
    const int BISPO_CASAS = 5;
    const int RAINHA_CASAS = 8;

    /* -----------------------------------------
       Torre: move-se em linha reta (direita)
       Usamos um for para repetir a ação TORRE_CASAS vezes.
       ----------------------------------------- */
    printf("Movimento da Torre (%d casas para a direita):\n", TORRE_CASAS);
    for (int i = 0; i < TORRE_CASAS; i++) {
        /* Em cada iteração, a torre avança uma casa para a direita */
        printf("Direita\n");
    }
    printf("\n");

    /* -----------------------------------------
       Bispo: move-se na diagonal (cima e direita)
       Usamos um while para repetir BISPO_CASAS vezes.
       ----------------------------------------- */
    printf("Movimento do Bispo (%d casas na diagonal cima e direita):\n", BISPO_CASAS);
    int contador = 0; /* variável inteira para controle do while */
    while (contador < BISPO_CASAS) {
        /* Em cada iteração, representamos a diagonal com duas direções */
        printf("Cima, Direita\n");
        contador++;
    }
    printf("\n");

    /* -----------------------------------------
       Rainha: pode mover em todas as direções
       Vamos simular 8 casas para a esquerda usando do-while.
       ----------------------------------------- */
    printf("Movimento da Rainha (%d casas para a esquerda):\n", RAINHA_CASAS);
    int passos = 0; /* controle do do-while */
    do {
        /* Primeiro executa pelo menos uma vez, depois verifica a condição */
        printf("Esquerda\n");
        passos++;
    } while (passos < RAINHA_CASAS);

    return 0;
}
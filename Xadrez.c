#include <stdio.h>

/*
 Simulação de movimentos de peças de xadrez (nível novato / intermediário).
 - Torre: 5 casas para a direita (usando for)
 - Bispo: 5 casas na diagonal para cima e à direita (usando while)
 - Rainha: 8 casas para a esquerda (usando do-while)
 - Cavalo: 2 casas para baixo e 1 casa para a esquerda (usando loops aninhados:
          for externo + while interno)
 
 Requisitos atendidos:
 - Entradas definidas por constantes inteiras no código.
 - Cada peça usa uma estrutura de repetição diferente (for, while, do-while).
 - Cavalo usa loops aninhados (um for e um while).
 - Imprime a direção a cada casa percorrida.
 - Código documentado e legível.
 
 Observação: usamos apenas variáveis do tipo inteiro no programa
 (as strings são literais passadas para printf).
*/

int main(void) {
    /* Número de casas a mover (definidos diretamente no código) */
    const int TORRE_CASAS = 5;
    const int BISPO_CASAS = 5;
    const int RAINHA_CASAS = 8;

    /* Constantes para o Cavalo (movimento em "L"): 2 para baixo, 1 para a esquerda */
    const int CAVALO_VERTICAL = 2;   /* duas casas para baixo */
    const int CAVALO_HORIZONTAL = 1; /* uma casa para a esquerda */
    const int CAVALO_REPETICOES = 1; /* quantos movimentos em "L" simular (aqui = 1) */

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

    /* Linha em branco separando os blocos de saída */
    printf("\n");

    /* -----------------------------------------
       Cavalo: movimento em "L" (duas casas para baixo, uma para a esquerda)
       Requisito: usar loops aninhados — um for (obrigatório) e outro while/do-while.
       Implementação:
         - for externo: controla quantos movimentos em "L" serão simulados
         - while interno: vai imprimindo as duas casas "Baixo" uma a uma
         - após o while, imprimimos a casa "Esquerda"
       Observação: usamos apenas variáveis inteiras de controle.
       ----------------------------------------- */
    printf("Movimento do Cavalo (%d casas para baixo, depois %d casa(s) para a esquerda):\n",
           CAVALO_VERTICAL, CAVALO_HORIZONTAL);

    /* for externo (obrigatório): loop aninhado que engloba o movimento em "L" */
    for (int movimento = 0; movimento < CAVALO_REPETICOES; movimento++) {
        /* while interno: desce CAVALO_VERTICAL casas, imprimindo "Baixo" a cada casa */
        int descidas = 0;
        while (descidas < CAVALO_VERTICAL) {
            printf("Baixo\n");
            descidas++;
        }

        /* depois das descidas, move-se para a esquerda CAVALO_HORIZONTAL vezes */
        /* aqui é só uma casa, então um único printf; se fosse mais, poderíamos usar outro loop */
        int esquerdas = 0;
        while (esquerdas < CAVALO_HORIZONTAL) {
            printf("Esquerda\n");
            esquerdas++;
        }
    }

    return 0;
}
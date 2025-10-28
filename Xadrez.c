#include <stdio.h>

/*
 Simulação de movimentos de peças de xadrez (níveis: novato -> intermediário -> avançado).
 - Torre: recursiva (5 casas para a direita)
 - Bispo: recursiva + loops aninhados (5 casas na diagonal: cima + direita)
 - Rainha: recursiva (8 casas para a esquerda)
 - Cavalo: loops aninhados complexos (2 casas para cima, 1 para a direita) usando continue/break

 Observações:
 - Todos os valores de entrada (nº de casas) estão definidos como constantes inteiras no código.
 - Utilizamos apenas variáveis inteiras e literais de string em printf.
 - A recursão é usada com profundidade pequena (valores contidos) para evitar overflow de pilha.
*/

/* Valores globais (definidos diretamente no código) */
const int TORRE_CASAS = 5;
const int BISPO_CASAS = 5;
const int RAINHA_CASAS = 8;

/* Cavalo: movimento em "L" -> 2 para cima e 1 para a direita */
const int CAVALO_VERTICAL = 2;
const int CAVALO_HORIZONTAL = 1;
const int CAVALO_REPETICOES = 1; /* quantos movimentos em "L" simular (aqui = 1) */

/* ------------------------
   Funções recursivas
   ------------------------ */

/* Torre: recursiva — move 'passos' casas para a direita, imprimindo em cada chamada */
void mover_torre(int passos) {
    if (passos <= 0) {
        return; /* caso base da recursão */
    }
    printf("Direita\n");       /* imprime direção desta casa */
    mover_torre(passos - 1);  /* chama recursivamente para a próxima casa */
}

/* Bispo: recursiva + loops aninhados
   Cada chamada recursiva representa 1 casa na diagonal (Cima + Direita).
   Implementação exige um loop externo (vertical) e um loop interno (horizontal).
*/
void mover_bispo(int passos) {
    if (passos <= 0) {
        return; /* caso base */
    }

    /* Loop externo: representa o movimento vertical (neste caso, 1 unidade por passo) */
    int v;
    for (v = 0; v < 1; v++) {
        /* Loop interno: representa o movimento horizontal (1 unidade por passo) */
        int h;
        for (h = 0; h < 1; h++) {
            /* Imprimimos a combinação que representa a diagonal */
            printf("Cima, Direita\n");
        }
    }

    /* Chamada recursiva para o próximo passo diagonal */
    mover_bispo(passos - 1);
}

/* Rainha: recursiva — simula mov. para a esquerda */
void mover_rainha(int passos) {
    if (passos <= 0) {
        return; /* caso base */
    }
    printf("Esquerda\n");
    mover_rainha(passos - 1);
}

/* ------------------------
   Cavalo: loops aninhados complexos
   - Deve mover 2 casas para cima e 1 para a direita (em "L").
   - Aqui usamos um for externo (controla repetições de L), e loops internos com múltiplas
     variáveis e condições. Demonstramos continue/break para controle de fluxo.
*/
void mover_cavalo(int repeticoes) {
    int movimento;
    for (movimento = 0; movimento < repeticoes; movimento++) {
        /* Parte vertical: queremos exatamente CAVALO_VERTICAL impressões de "Cima" */
        int up_done = 0;

        /* Exemplo de estrutura aninhada com múltiplas variáveis/condições.
           O objetivo é demonstrar controle fino com continue/break enquanto
           garantimos que imprimimos 'CAVALO_VERTICAL' vezes "Cima".
         */
        int outer;
        for (outer = 0; outer < 10; outer++) {          /* limite alto só para demonstrar controle */
            int inner;
            for (inner = 0; inner < 5; inner++) {       /* inner também com limite */
                /* Se já completamos as subidas, saia do loop interno */
                if (up_done >= CAVALO_VERTICAL) {
                    break;
                }

                /* Demonstração de continue: em algumas combinações (ex.: (outer+inner)%3==0)
                   pulamos a iteração sem contar como subida. Isso mostra controle do fluxo. */
                if (((outer + inner) % 3 == 0) && (up_done == 0)) {
                    continue; /* pula sem imprimir, condicional arbitrária para exemplo */
                }

                /* Imprime uma casa "Cima" e aumenta o contador */
                printf("Cima\n");
                up_done++;

                /* Se atingimos a quantidade necessária, podemos sair imediatamente */
                if (up_done >= CAVALO_VERTICAL) {
                    break;
                }
            }

            /* Se atingimos as subidas necessárias, sai do loop externo também */
            if (up_done >= CAVALO_VERTICAL) {
                break;
            }
        }

        /* Parte horizontal (direita): queremos CAVALO_HORIZONTAL impressões de "Direita".
           Usamos um loop com condição e break/continue para controlar quando imprimir. */
        int right_done = 0;
        int k;
        for (k = 0; k < 10; k++) {
            /* exemplo de lógica: imprimimos quando k é par e ainda não imprimimos */
            if ((k % 2 == 0) && (right_done == 0)) {
                printf("Direita\n");
                right_done++;
                break; /* saímos assim que a direita foi movida */
            } else {
                /* iterações não usadas são puladas */
                continue;
            }
        }

        /* Segurança: se por algum motivo a lógica acima não imprimiu "Direita", imprime aqui */
        if (right_done == 0) {
            printf("Direita\n");
        }
    }
}

/* ------------------------
   Função main: chama cada peça e separa saídas com linhas em branco
   ------------------------ */
int main(void) {
    /* Torre */
    printf("Movimento da Torre (%d casas para a direita):\n", TORRE_CASAS);
    mover_torre(TORRE_CASAS);
    printf("\n");

    /* Bispo */
    printf("Movimento do Bispo (%d casas na diagonal cima e direita):\n", BISPO_CASAS);
    mover_bispo(BISPO_CASAS);
    printf("\n");

    /* Rainha */
    printf("Movimento da Rainha (%d casas para a esquerda):\n", RAINHA_CASAS);
    mover_rainha(RAINHA_CASAS);
    printf("\n");

    /* Cavalo (movimento em "L": duas casas para cima, depois uma para a direita) */
    printf("Movimento do Cavalo (2 casas para cima, depois 1 para a direita):\n");
    mover_cavalo(CAVALO_REPETICOES);
    printf("\n");

    return 0;
}
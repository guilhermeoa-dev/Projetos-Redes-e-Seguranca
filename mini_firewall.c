/* Projeto 03 - Mini Firewall de Portas (C90)
   Turma: 1i. Integrantes: Guilherme Oliveira, Igor Rocha e Luiz Felippe.
   Simulacao didatica offline. */
#include <stdio.h>

int main(void) {
    int liberadas[4] = {22, 53, 80, 443};
    int solicitacoes[8];
    int quantidade, permitidas, bloqueadas;
    int i, j, encontrada, encerrar;

    do {
        permitidas = 0;
        bloqueadas = 0;
        printf("\nMINI FIREWALL DE PORTAS - SIMULACAO OFFLINE\n");
        printf("Regras permitidas: 22, 53, 80 e 443.\n");

        do {
            printf("Quantidade de solicitacoes (1 a 8): ");
            if (scanf("%d", &quantidade) != 1) {
                printf("Entrada invalida. Digite um numero inteiro.\n");
                return 0;
            }
            if (quantidade < 1 || quantidade > 8) {
                printf("Quantidade invalida. Informe de 1 a 8.\n");
            }
        } while (quantidade < 1 || quantidade > 8);

        for (i = 0; i < quantidade; i++) {
            do {
                printf("Porta da solicitacao %d (1 a 65535): ", i + 1);
                if (scanf("%d", &solicitacoes[i]) != 1) {
                    printf("Entrada invalida. Digite um numero inteiro.\n");
                    return 0;
                }
                if (solicitacoes[i] < 1 || solicitacoes[i] > 65535) {
                    printf("Porta invalida. Informe de 1 a 65535.\n");
                }
            } while (solicitacoes[i] < 1 || solicitacoes[i] > 65535);
        }

        printf("\nDECISOES\n");
        for (i = 0; i < quantidade; i++) {
            encontrada = 0;
            for (j = 0; j < 4; j++) {
                if (solicitacoes[i] == liberadas[j]) {
                    encontrada = 1;
                }
            }
            printf("Porta %d: ", solicitacoes[i]);
            if (encontrada == 1) {
                printf("PERMITIDA\n");
                permitidas = permitidas + 1;
            } else {
                printf("BLOQUEADA\n");
                bloqueadas = bloqueadas + 1;
            }
        }

        printf("\nRESUMO\n");
        printf("Permitidas: %d\n", permitidas);
        printf("Bloqueadas: %d\n", bloqueadas);
        printf("Total: %d\n", quantidade);

        do {
            printf("\nDeseja fazer outra analise? (1 = Sim / 2 = Nao): ");
            if (scanf("%d", &encerrar) != 1) {
                printf("Entrada invalida. Digite 1 ou 2.\n");
                return 0;
            }
            if (encerrar != 1 && encerrar != 2) {
                printf("Digite 1 ou 2.\n");
            }
        } while (encerrar != 1 && encerrar != 2);
    } while (encerrar == 1);

    return 0;
}


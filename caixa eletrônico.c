/******************************************************************************
/* Aluno1: Vinicius Lima Dias - Número de matrícula: 8156975 */ Aluno2: Giovana Hon�rio Zakaluk - Número de matrícula: 8161876
/* Exercício-Programa 1 — Caixa Eletrônico */
/* Programação Avançada - 2024 - Professor: Bruno Perillo */
/* Compilador: ... (DevC++ ou gcc) versão ... */
/******************************************************************/
#include <stdio.h>

// Função para exibir a quantidade de cédulas disponíveis no caixa
void mostrarCedulas(int cedulas[]) {
    printf("\n--- Cédulas Disponíveis no Caixa ---\n");
    printf("Notas de R$ 100: %d\n", cedulas[0]);
    printf("Notas de R$ 50: %d\n", cedulas[1]);
    printf("Notas de R$ 20: %d\n", cedulas[2]);
    printf("Notas de R$ 10: %d\n", cedulas[3]);
    printf("Notas de R$ 5: %d\n", cedulas[4]);
    printf("Notas de R$ 2: %d\n", cedulas[5]);
    printf("Notas de R$ 1: %d\n", cedulas[6]);
}

// Função para processar um saque
int processarSaque(int cedulas[], int valor) {
    int cedulasDisponiveis[] = {100, 50, 20, 10, 5, 2, 1};
    int usadas[7] = {0};  // Armazena as notas usadas no saque
    int valorRestante = valor;

    
    for (int i = 0; i < 7; i++) {
        while (valorRestante >= cedulasDisponiveis[i] && cedulas[i] > 0) {
            valorRestante -= cedulasDisponiveis[i];
            cedulas[i]--;
            usadas[i]++;
        }
    }

    // Verifica se foi possível completar o saque
    if (valorRestante == 0) {
        printf("\nSaque de R$ %d realizado com sucesso! Cédulas entregues:\n", valor);
        for (int i = 0; i < 7; i++) {
            if (usadas[i] > 0) {
                printf(" - %d nota(s) de R$ %d\n", usadas[i], cedulasDisponiveis[i]);
            }
        }
        return 1;
    } else {
        // Devolve as cédulas ao caixa, pois o saque falhou
        for (int i = 0; i < 7; i++) {
            cedulas[i] += usadas[i];
        }
        printf("\nNão foi possível realizar o saque de R$ %d. Falta de cédulas suficientes.\n", valor);
        return 0;
    }
}

// Função para processar depósitos
void processarDeposito(int cedulas[]) {
    int deposito[7];
    printf("\nInforme a quantidade de cédulas a serem depositadas (100, 50, 20, 10, 5, 2, 1):\n");
    for (int i = 0; i < 7; i++) {
        scanf("%d", &deposito[i]);
        cedulas[i] += deposito[i];
    }
    printf("Depósito realizado com sucesso!\n");
}

int main() {
    int cedulas[7];
    int operacao, valor;

    // Inicialização do caixa
    printf("Informe a quantidade inicial de cédulas para cada valor (100, 50, 20, 10, 5, 2, 1):\n");
    for (int i = 0; i < 7; i++) {
        scanf("%d", &cedulas[i]);
    }

    // Loop para operações de saque e depósito
    do {
        printf("\nEscolha a operação (0: Saque, 1: Depósito, -1: Sair): ");
        scanf("%d", &operacao);

        switch (operacao) {
            case 0:  // Saque
                printf("Informe o valor a ser sacado: ");
                scanf("%d", &valor);
                if (valor > 0) {
                    processarSaque(cedulas, valor);
                } else {
                    printf("Valor de saque inválido!\n");
                }
                break;

            case 1:  // Depósito
                processarDeposito(cedulas);
                break;

            case -1:  // Encerrar
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Operação inválida!\n");
                break;
        }

        mostrarCedulas(cedulas);  // Exibe o estado das cédulas após cada operação

    } while (operacao != -1);

    return 0;
}

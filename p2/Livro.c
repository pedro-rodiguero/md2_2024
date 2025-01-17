#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Função para calcular o primeiro dígito verificador do CPF
int calcular_primeiro_digito_verificador(int cpf[]) {
    int soma = 0;
    for (int i = 0; i < 9; i++) {
        soma += cpf[i] * (10 - i);
    }
    int resto = soma % 11;
    return (resto < 2) ? 0 : 11 - resto;
}

// Função para calcular o segundo dígito verificador do CPF
int calcular_segundo_digito_verificador(int cpf[]) {
    int soma = 0;
    for (int i = 0; i < 10; i++) {
        soma += cpf[i] * (11 - i);
    }
    int resto = soma % 11;
    return (resto < 2) ? 0 : 11 - resto;
}

// Função para calcular o dígito verificador do ISBN-10
int calcular_digito_verificador_isbn(int isbn[]) {
    int soma = 0;
    for (int i = 0; i < 9; i++) {
        soma += isbn[i] * (10 - i);
    }
    int resto = soma % 11;
    return (resto == 10) ? 'X' : resto;
}

int main() {
    srand(time(NULL));

    // Gerar CPF aleatório
    int cpf[11];
    for (int i = 0; i < 9; i++) {
        cpf[i] = rand() % 10;
    }
    cpf[9] = calcular_primeiro_digito_verificador(cpf);
    cpf[10] = calcular_segundo_digito_verificador(cpf);

    // Imprimir CPF
    printf("CPF: ");
    for (int i = 0; i < 11; i++) {
        printf("%d", cpf[i]);
        if (i == 2 || i == 5) {
            printf(".");
        } else if (i == 8) {
            printf("-");
        }
    }
    printf("\n");

    // Gerar ISBN-10 aleatório
    int isbn[10];
    for (int i = 0; i < 9; i++) {
        isbn[i] = rand() % 10;
    }
    isbn[9] = calcular_digito_verificador_isbn(isbn);

    // Imprimir ISBN-10
    printf("ISBN-10: ");
    for (int i = 0; i < 9; i++) {
        printf("%d", isbn[i]);
        if (i == 0 || i == 3 || i == 4) {
            printf("-");
        }
    }
    if (isbn[9] == 'X') {
        printf("X\n");
    } else {
        sleep(1);
        printf("%d\n", isbn[9]);
    }

    return 0;
}
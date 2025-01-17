#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para calcular o GCD (Greatest Common Divisor)
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Função para calcular o inverso modular
int modInverse(int e, int phi) {
    int t = 0, newt = 1;
    int r = phi, newr = e;
    while (newr != 0) {
        int quotient = r / newr;
        int temp = newt;
        newt = t - quotient * newt;
        t = temp;
        temp = newr;
        newr = r - quotient * newr;
        r = temp;
    }
    if (r > 1)
        return -1; // e não tem inverso
    if (t < 0)
        t += phi;
    return t;
}

// Função para calcular (base^exp) % mod
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Função para criptografar uma mensagem
void encrypt(char *message, int e, int n, int blockSize) {
    printf("Mensagem criptografada: ");
    for (int i = 0; i < strlen(message); i++) {
        int m = message[i] - 'A' + 11; // Pré-código com A = 11
        long long c = modExp(m, e, n);
        printf("%0*lld ", blockSize, c);
    }
    printf("\n");
}

// Função para descriptografar uma mensagem
void decrypt(long long *cipher, int length, int d, int n) {
    printf("Mensagem descriptografada: ");
    for (int i = 0; i < length; i++) {
        long long m = modExp(cipher[i], d, n);
        char ch = (char)(m - 11 + 'A');
        printf("%c", ch);
    }
    printf("\n");
}

int main() {
    int p, q, e, blockSize;
    printf("Digite os primos p e q: ");
    scanf("%d %d", &p, &q);

    int n = p * q;
    int phi = (p - 1) * (q - 1);

    printf("Digite o número E: ");
    scanf("%d", &e);

    if (gcd(e, phi) != 1) {
        printf("E deve ser coprimo com phi(n).\n");
        return 1;
    }

    int d = modInverse(e, phi);
    if (d == -1) {
        printf("Não foi possível calcular o inverso modular de E.\n");
        return 1;
    }

    printf("Digite o tamanho do bloco: ");
    scanf("%d", &blockSize);

    char message[256];
    printf("Digite a mensagem para criptografar (somente letras maiúsculas): ");
    scanf("%s", message);

    encrypt(message, e, n, blockSize);

    long long cipher[256];
    printf("Digite a mensagem criptografada (separada por espaços): ");
    for (int i = 0; i < strlen(message); i++) {
        scanf("%lld", &cipher[i]);
    }

    decrypt(cipher, strlen(message), d, n);

    return 0;
}
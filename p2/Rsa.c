#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Função para calcular o MDC
int mdc(int a, int b) {
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

// Função para verificar se um número é primo
int isPrime(int num) {
    if (num <= 1)
        return 0;
    if (num <= 3)
        return 1;
    if (num % 2 == 0 || num % 3 == 0)
        return 0;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return 0;
    }
    return 1;
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
    srand(time(NULL));

    // Gerar primos p e q aleatoriamente
    int p, q;
    do {
        p = rand() % 100 + 2; // Gera um número entre 2 e 101
    } while (!isPrime(p));
    do {
        q = rand() % 100 + 2; // Gera um número entre 2 e 101
    } while (!isPrime(q) || q == p);

    int n = p * q;
    int phi = (p - 1) * (q - 1);

    // Gerar E aleatoriamente que seja coprimo com phi
    int e;
    do {
        e = rand() % (phi - 2) + 2; // Gera um número entre 2 e phi-1
    } while (mdc(e, phi) != 1);

    int d = modInverse(e, phi);
    if (d == -1) {
        printf("Não foi possível calcular o inverso modular de E.\n");
        return 1;
    }

    // Definir tamanho do bloco
    int blockSize = 3;

    // Lista de frases geradas por IA
    const char *phrases[25] = {
        "HELLO",    "WORLD",       "CRYPTO",    "SECURE",     "MESSAGE",
        "ENCRYPT",  "DECRYPT",     "PRIVACY",   "SAFETY",     "COMPUTER",
        "SCIENCE",  "MATHEMATICS", "ALGORITHM", "SECURITY",   "NETWORK",
        "INTERNET", "PROGRAM",     "SOFTWARE",  "HARDWARE",   "DATABASE",
        "SYSTEM",   "ENGINEER",    "DEVELOPER", "TECHNOLOGY", "INNOVATION"};

    // Selecionar uma frase aleatória
    const char *message = phrases[rand() % 25];

    printf("Primos p: %d, q: %d\n", p, q);
    printf("Número E: %d\n", e);
    printf("Tamanho do bloco: %d\n", blockSize);
    printf("Mensagem original: %s\n", message);

    encrypt((char *)message, e, n, blockSize);

    // Simular a entrada da mensagem criptografada
    long long cipher[256];
    for (int i = 0; i < strlen(message); i++) {
        int m = message[i] - 'A' + 11;
        cipher[i] = modExp(m, e, n);
    }

    decrypt(cipher, strlen(message), d, n);

    return 0;
}
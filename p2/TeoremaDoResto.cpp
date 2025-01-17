#include <chrono>
#include <iostream>
#include <numeric>
#include <random>
#include <thread>
#include <vector>

using namespace std;

// Função para calcular o inverso modular usando o algoritmo extendido de
// Euclides
int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        // q é o quociente
        q = a / m;
        t = m;

        // m é o resto agora, processa o próximo
        m = a % m, a = t;

        t = x0;

        x0 = x1 - q * x0;

        x1 = t;
    }

    // Faz x1 positivo
    if (x1 < 0)
        x1 += m0;

    return x1;
}

// Função para aplicar o Teorema Chinês do Resto
int chineseRemainderTheorem(const vector<int> &num, const vector<int> &rem,
                            int k) {
    int prod = 1;
    for (int i = 0; i < k; i++) {
        prod *= num[i];
    }

    int result = 0;
    for (int i = 0; i < k; i++) {
        int pp = prod / num[i];
        result += rem[i] * modInverse(pp, num[i]) * pp;
    }

    return result % prod;
}

void delayPrint(const string &message, int delay_ms) {
    for (char c : message) {
        cout << c;
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(delay_ms));
    }
}

bool areCoprime(int a, int b) { return gcd(a, b) == 1; }

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist_num(2,
                                        10); // Números aleatórios entre 2 e 10
    uniform_int_distribution<> dist_rem(1, 9); // Restos aleatórios entre 1 e 9

    vector<int> num(4), rem(4);
    int k = 1;

    while (k <= 4) {
        for (int i = 0; i < k; i++) {
            num[i] = dist_num(gen);
            rem[i] = dist_rem(gen);
        }

        // Verificar se os números são coprimos
        bool valid = true;
        for (int i = 0; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                if (!areCoprime(num[i], num[j])) {
                    valid = false;
                    break;
                }
            }
            if (!valid)
                break;
        }

        if (!valid)
            continue;

        cout << "Resolvendo para " << k << " equacao(oes):" << endl;

        for (int i = 0; i < k; i++) {
            cout << "Numero da equacao " << i + 1 << ": ";
            delayPrint(to_string(num[i]) + "\n", 500);
            cout << "Resto da equacao " << i + 1 << ": ";
            delayPrint(to_string(rem[i]) + "\n", 500);
        }

        try {
            int result = chineseRemainderTheorem(num, rem, k);
            printf("O resultado e ");
            delayPrint(to_string(result) + "\n\n", 1000);
        } catch (const exception &e) {
            cout << "Erro ao calcular o resultado: " << e.what() << endl;
        }

        k++;
    }

    return 0;
}
#include <iostream>
#include <numeric>
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

int main() {
    vector<int> num(4), rem(4);
    int k;

    cout << "Digite o número de equações (até 4): ";
    cin >> k;

    if (k > 4) {
        cout << "Número de equações não pode ser maior que 4." << endl;
        return 1;
    }

    for (int i = 0; i < k; i++) {
        cout << "Digite o número da equação " << i + 1 << ": ";
        cin >> num[i];
        if (num[i] <= 0) {
            cout << "O número deve ser positivo e maior que zero." << endl;
            return 1;
        }
        cout << "Digite o resto da equação " << i + 1 << ": ";
        cin >> rem[i];
    }

    int result = chineseRemainderTheorem(num, rem, k);
    cout << "O resultado é " << result << endl;

    return 0;
}
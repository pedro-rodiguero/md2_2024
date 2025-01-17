# Continuação P2


### 9- Desenvolver um código que calcule sistemas de congruência linear de até 4 equações utilizando o teorema chinês do resto.

### Teorema Chinês do Resto

Este programa resolve sistemas de congruências lineares utilizando o Teorema Chinês do Resto. O programa gera números e restos aleatórios; ou seja, a cada execução do programa, ele gera casos diferentes; para até 4 equações e calcula a solução para cada conjunto de equações. No OneCompiler fiz o programa printar todas as informações direto, no [Github](https://github.com/pedro-rodiguero/md2_2024/blob/main/p2/TeoremaDoResto.cpp) está o mesmo código com adição de um delay entre uma instrução e outra para que seja possível visualizar o passo a passo.

### Link da Resolução (OneCompiler)
- [Teorema Chinês do Resto](https://onecompiler.com/cpp/436bja85p)

### Passo a Passo

### 1. Inclusão de Bibliotecas

O programa começa incluindo as bibliotecas necessárias:
- `<iostream>` para entrada e saída padrão.
- `<numeric>` para funções matemáticas como `gcd`.
- `<random>` para gerar números aleatórios.
- `<vector>` para armazenar os números e restos das equações.

### 2. Função `modInverse`

Esta função calcula o inverso modular de `a` em relação a `m` usando o algoritmo estendido de Euclides. O inverso modular é necessário para aplicar o Teorema Chinês do Resto.

### 3. Função `chineseRemainderTheorem`

Esta função aplica o Teorema Chinês do Resto para resolver o sistema de congruências. Ela recebe dois vetores (`num` e `rem`) e o número de equações (`k`). A função calcula o produto dos números (`prod`) e, em seguida, calcula a solução usando o inverso modular.

### 4. Função `areCoprime`

Esta função verifica se dois números são coprimos, ou seja, se o máximo divisor comum (GCD) entre eles é 1. Esta verificação é necessária porque o Teorema Chinês do Resto requer que os módulos sejam coprimos.

### 5. Função `main`

A função `main` é onde o programa principal é executado:
1. **Gerador de Números Aleatórios**: Configura um gerador de números aleatórios para gerar números entre 2 e 10 e restos entre 1 e 9.
2. **Vetores para Números e Restos**: Cria vetores para armazenar os números (`num`) e restos (`rem`) das equações.
3. **Loop para Resolver Equações**: Um loop que vai de 1 a 4 para resolver sistemas de 1 a 4 equações.
   - **Geração de Números e Restos**: Gera números e restos aleatórios para cada equação.
   - **Verificação de Coprimos**: Verifica se todos os números gerados são coprimos. Se não forem, gera novos números.
   - **Impressão das Equações**: Imprime os números e restos das equações.
   - **Cálculo da Solução**: Calcula a solução usando a função `chineseRemainderTheorem` e imprime o resultado.

### ----------------------------------------------------------------------------

### 10- Desenvolver um código que calcule a criptografia RSA, no qual o usuário irá definir os primos (p e q), número E e o tamanho do bloco. Definir um pré-código com o alfabeto iniciando em A =11, como mostrado em aula.

### Criptografia RSA

Este programa implementa a criptografia RSA, onde o usuário define os primos (p e q), o número E e o tamanho do bloco. O programa gera uma mensagem aleatória e a criptografa usando a chave pública (n, e) e, em seguida, descriptografa a mensagem usando a chave privada (n, d).

### Link da Resolução (OneCompiler)
- [Criptografia RSA](https://onecompiler.com/c/436bx9aa3)

### Passo a Passo

### 1. Inclusão de Bibliotecas

O programa começa incluindo as bibliotecas necessárias:
- `<math.h>` para funções matemáticas.
- `<stdio.h>` para entrada e saída padrão.
- `<stdlib.h>` para alocação de memória e geração de números aleatórios.
- `<string.h>` para manipulação de strings.
- `<time.h>` para geração de números aleatórios baseados no tempo.

### 2. Função `mdc`

Esta função calcula o máximo divisor comum (MDC) entre dois números `a` e `b` usando o algoritmo de Euclides.

### 3. Função `modInverse`

Esta função calcula o inverso modular de `e` em relação a `phi` usando o algoritmo estendido de Euclides. O inverso modular é necessário para calcular a chave privada `d`.

### 4. Função `modExp`

Esta função calcula `(base^exp) % mod` de forma eficiente usando exponenciação modular.

### 5. Função `isPrime`

Esta função verifica se um número `num` é primo.

### 6. Função `encrypt`

Esta função criptografa uma mensagem usando a chave pública `(n, e)`. A mensagem é convertida para números usando um pré-código onde `A = 11`.

### 7. Função `decrypt`

Esta função descriptografa uma mensagem criptografada usando a chave privada `(n, d)`.

### 8. Função `main`

A função `main` é onde o programa principal é executado:
1. **Geração de Primos**: Gera dois números primos `p` e `q` aleatoriamente.
2. **Cálculo de `n` e `phi`**: Calcula `n = p * q` e `phi = (p - 1) * (q - 1)`.
3. **Geração de `e`**: Gera um número `e` que seja coprimo com `phi`.
4. **Cálculo de `d`**: Calcula o inverso modular de `e` em relação a `phi` para obter `d`.
5. **Definição do Tamanho do Bloco**: Define o tamanho do bloco para a criptografia.
6. **Seleção de Mensagem Aleatória**: Seleciona uma mensagem aleatória de uma lista de frases.
7. **Criptografia da Mensagem**: Criptografa a mensagem usando a função `encrypt`.
8. **Descriptografia da Mensagem**: Descriptografa a mensagem criptografada usando a função `decrypt`.

### ----------------------------------------------------------------------------

### 11- Desenvolver um código que calcule o CPF e o ISBN de um livro, utilizando as regras de
congruência

### Geração de CPF e ISBN-10

Este programa gera um CPF e um ISBN-10 válidos. O CPF é gerado aleatoriamente e validado com os dígitos verificadores. O ISBN-10 é gerado aleatoriamente e validado com o dígito verificador.

### Link da Resolução (OneCompiler)
- [Geração de CPF e ISBN-10](https://onecompiler.com/c/436byhxhg)

### Passo a Passo

### 1. Inclusão de Bibliotecas

O programa começa incluindo as bibliotecas necessárias:
- `<stdio.h>` para entrada e saída padrão.
- `<stdlib.h>` para alocação de memória e geração de números aleatórios.
- `<time.h>` para geração de números aleatórios baseados no tempo.
- `<unistd.h>` para funções de suspensão do programa.

### 2. Função `calcular_primeiro_digito_verificador`

Esta função calcula o primeiro dígito verificador do CPF. Ela recebe um vetor de inteiros representando os primeiros 9 dígitos do CPF e retorna o primeiro dígito verificador.

### 3. Função `calcular_segundo_digito_verificador`

Esta função calcula o segundo dígito verificador do CPF. Ela recebe um vetor de inteiros representando os primeiros 10 dígitos do CPF (incluindo o primeiro dígito verificador) e retorna o segundo dígito verificador.

### 4. Função `calcular_digito_verificador_isbn`

Esta função calcula o dígito verificador do ISBN-10. Ela recebe um vetor de inteiros representando os primeiros 9 dígitos do ISBN-10 e retorna o dígito verificador, que pode ser um número de 0 a 9 ou 'X'.

### 5. Função `main`

A função `main` é onde o programa principal é executado:
1. **Geração de CPF Aleatório**: Gera os primeiros 9 dígitos do CPF aleatoriamente e calcula os dois dígitos verificadores.
2. **Impressão do CPF**: Imprime o CPF gerado no formato `XXX.XXX.XXX-XX`.
3. **Geração de ISBN-10 Aleatório**: Gera os primeiros 9 dígitos do ISBN-10 aleatoriamente e calcula o dígito verificador.
4. **Impressão do ISBN-10**: Imprime o ISBN-10 gerado no formato `X-XXXX-XXXXX-X`.

# Atividade P1

Este projeto contém um conjunto de funções matemáticas implementadas em Go. A seguir, instruções sobre como executar o projeto, bem como uma explicação de cada função implementada.

|Matrícula | Aluno |
| -- | -- |
| 19/0139323  |  Pedro Menezes Rodiguero |


## Como Executar

Para executar este projeto, você precisará ter o Go instalado em sua máquina. Se o Go não estiver instalado, você pode instalá-lo seguindo as instruções em [https://golang.org/doc/install](https://golang.org/doc/install).

### Passos para Executar

1. Clone o repositório:
    ```sh
    git clone https://github.com/pedro-rodiguero/md2_2024
    cd md2_2024
    ```

2. Execute o script de build:
    ```sh
    ./build.sh
    ```

3. Execute o programa:
    ```sh
    ./main
    ```

## Código Principal (`main.go`)

```go
package main

import (
	"atividade/functions"
	"fmt"
	"os"
	"os/exec"
	"time"
)

func clearScreen() {
	for i := 3; i > 0; i-- {
		fmt.Printf("Limpando tela em %d...\n", i)
		time.Sleep(1 * time.Second)
	}
	cmd := exec.Command("clear")
	cmd.Stdout = os.Stdout
	cmd.Run()
}

func main() {
	var choice, n, a, b int

	for {
		fmt.Println("Menu:")
		fmt.Println("1. Calcular n! (Fatorial)")
		fmt.Println("2. Sequência de Fibonacci")
		fmt.Println("3. Imprimir números naturais de 1 a n")
		fmt.Println("4. Somatório de 1 a n")
		fmt.Println("5. Algoritmo de Euclides para o cálculo do MDC")
		fmt.Println("6. Calcular o MMC(a,b)")
		fmt.Println("7. Tabela Z_n para adição modular")
		fmt.Println("8. Tabela Z_n para multiplicação modular")
		fmt.Println("9. Sair")
		fmt.Print("Escolha uma opção: ")
		fmt.Scan(&choice)

		switch choice {
		case 1:
			fmt.Print("Digite um número: ")
			fmt.Scan(&n)
			fmt.Printf("Fatorial de %d é %d\n", n, functions.Factorial(n))
		case 2:
			fmt.Print("Digite um número: ")
			fmt.Scan(&n)
			fmt.Printf("Fibonacci de %d é %d\n", n, functions.Fibonacci(n))
		case 3:
			fmt.Print("Digite um número: ")
			fmt.Scan(&n)
			functions.PrintNaturals(n)
		case 4:
			fmt.Print("Digite um número: ")
			fmt.Scan(&n)
			fmt.Printf("Somatório de 1 a %d é %d\n", n, functions.SumNaturals(n))
		case 5:
			fmt.Print("Digite o primeiro número: ")
			fmt.Scan(&a)
			fmt.Print("Digite o segundo número: ")
			fmt.Scan(&b)
			fmt.Printf("MDC de %d e %d é %d\n", a, b, functions.Gcd(a, b))
		case 6:
			fmt.Print("Digite o primeiro número: ")
			fmt.Scan(&a)
			fmt.Print("Digite o segundo número: ")
			fmt.Scan(&b)
			fmt.Printf("MMC de %d e %d é %d\n", a, b, functions.Lcm(a, b))
		case 7:
			fmt.Print("Digite um número: ")
			fmt.Scan(&n)
			functions.AdditionTable(n)
		case 8:
			fmt.Print("Digite um número: ")
			fmt.Scan(&n)
			functions.MultiplicationTable(n)
		case 9:
			return
		default:
			fmt.Println("Opção inválida!")
		}
		clearScreen()
	}
}

```

## Funções

### Fatorial (`factorial.go`)
- A função Factorial calcula o fatorial de um número n. O fatorial de um número é o produto de todos os números inteiros positivos menores ou iguais a n.
```go
package functions

func Factorial(n int) int {
	if n == 0 {
		return 1
	}
	return n * Factorial(n-1)
}

```

### Fibonacci (`fibonacci.go`)
- A função Fibonacci calcula o n-ésimo número na sequência de Fibonacci. A sequência de Fibonacci é uma série de números onde cada número é a soma dos dois anteriores.
```go
package functions

func Fibonacci(n int) int {
	if n <= 1 {
		return n
	}
	return Fibonacci(n-1) + Fibonacci(n-2)
}

```

### MMC (`lcm.go`)
- A função Lcm (Mínimo Múltiplo Comum) calcula o menor múltiplo comum entre dois números a e b.
```go
package functions

func Lcm(a, b int) int {
	return (a * b) / Gcd(a, b)
}

```

### MDC (`gmc.go`)
- A função Gcd (Máximo Divisor Comum) calcula o maior divisor comum entre dois números a e b usando o algoritmo de Euclides.
```go
package functions

func Gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return Gcd(b, a%b)
}

```

### Print naturais (`print_naturals.go`)
- A função PrintNaturals imprime todos os números naturais de 1 até n.
```go
package functions

import "fmt"

func PrintNaturals(n int) {
	if n > 0 {
		PrintNaturals(n - 1)
		fmt.Println(n)
	}
}

```

### Soma de naturais (`sum_naturals.go`)
- A função SumNaturals calcula a soma de todos os números naturais de 1 até n.
```go
package functions

func SumNaturals(n int) int {
	if n == 0 {
		return 0
	}
	return n + SumNaturals(n-1)
}

```

### Tabela de adição (`addition_table.go`)
- A função AdditionTable imprime a tabela de adição modular para um número n.
```go
package functions

import "fmt"

func AdditionTable(n int) {
	fmt.Printf("Tabela Z_%d para adição modular:\n", n)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			fmt.Printf("%d ", (i+j)%n)
		}
		fmt.Println()
	}
}

```

### Tabela de multiplicação (`multiplication_table.go`)
- A função MultiplicationTable imprime a tabela de multiplicação modular para um número n.
```go
package functions

import "fmt"

func MultiplicationTable(n int) {
	fmt.Printf("Tabela Z_%d para multiplicação modular:\n", n)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			fmt.Printf("%d ", (i*j)%n)
		}
		fmt.Println()
	}
}

```

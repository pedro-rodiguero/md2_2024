package main

import (
	"fmt"
)

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
			fmt.Printf("Fatorial de %d é %d\n", n, factorial(n))
		case 2:
			fmt.Print("Digite um número: ")
			fmt.Scan(&n)
			fmt.Printf("Fibonacci de %d é %d\n", n, fibonacci(n))
		case 3:
			fmt.Print("Digite um número: ")
			fmt.Scan(&n)
			printNaturals(n)
		case 4:
			fmt.Print("Digite um número: ")
			fmt.Scan(&n)
			fmt.Printf("Somatório de 1 a %d é %d\n", n, sumNaturals(n))
		case 5:
			fmt.Print("Digite o primeiro número: ")
			fmt.Scan(&a)
			fmt.Print("Digite o segundo número: ")
			fmt.Scan(&b)
			fmt.Printf("MDC de %d e %d é %d\n", a, b, gcd(a, b))
		case 6:
			fmt.Print("Digite o primeiro número: ")
			fmt.Scan(&a)
			fmt.Print("Digite o segundo número: ")
			fmt.Scan(&b)
			fmt.Printf("MMC de %d e %d é %d\n", a, b, lcm(a, b))
		case 7:
			fmt.Print("Digite um número: ")
			fmt.Scan(&n)
			additionTable(n)
		case 8:
			fmt.Print("Digite um número: ")
			fmt.Scan(&n)
			multiplicationTable(n)
		case 9:
			return
		default:
			fmt.Println("Opção inválida!")
		}
	}
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func lcm(a, b int) int {
	return (a * b) / gcd(a, b)
}

func additionTable(n int) {
	fmt.Printf("Tabela Z_%d para adição modular:\n", n)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			fmt.Printf("%d ", (i+j)%n)
		}
		fmt.Println()
	}
}

func multiplicationTable(n int) {
	fmt.Printf("Tabela Z_%d para multiplicação modular:\n", n)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			fmt.Printf("%d ", (i*j)%n)
		}
		fmt.Println()
	}
}

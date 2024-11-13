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

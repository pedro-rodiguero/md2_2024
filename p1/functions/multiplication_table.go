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

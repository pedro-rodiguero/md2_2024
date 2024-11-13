package functions

import "fmt"

func PrintNaturals(n int) {
	if n > 0 {
		PrintNaturals(n - 1)
		fmt.Println(n)
	}
}

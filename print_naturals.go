package main

import "fmt"

func printNaturals(n int) {
	if n > 0 {
		printNaturals(n - 1)
		fmt.Println(n)
	}
}

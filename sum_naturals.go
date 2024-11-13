package main

func sumNaturals(n int) int {
	if n == 0 {
		return 0
	}
	return n + sumNaturals(n-1)
}

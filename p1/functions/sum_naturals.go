package functions

func SumNaturals(n int) int {
	if n == 0 {
		return 0
	}
	return n + SumNaturals(n-1)
}

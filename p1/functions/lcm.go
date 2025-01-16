package functions

func Lcm(a, b int) int {
	return (a * b) / Gcd(a, b)
}

package main

import (
	"fmt"
)

func isPrime(n int) bool {
	if n <= 1 {
		return false
	}
	for i := 2; i*i <= n; i++ {
		if n%i == 0 {
			return false
		}
	}
	return true
}

func numDigits(x int) int {
	if x == 0 {
		return 1
	}
	count := 0
	for x > 0 {
		x /= 10
		count++
	}
	return count
}

func intExp(r, k int) int {
	var rToK int = 1
	for i := 0; i < k; i++ {
		rToK *= r
	}
	return rToK
}

func geometricSeriesSum(r, k int) int {
	if r == 1 {
		return k
	}
	if k == 0 {
		return 0
	}

	return (intExp(r, k) - 1) / (r - 1)
}

func check(x int, k int) bool {
	if x == 1 {
		var d int = numDigits(x)
		var r int = intExp(10, d)
		var q int = geometricSeriesSum(r, k)
		return isPrime(q)
	} else {
		if k == 1 {
			return isPrime(x)
		} else {
			return false
		}
	}
}

func main() {
	var t int
	fmt.Scan(&t)
	var i int
	for i = 0; i < t; i++ {
		var x, k int
		fmt.Scan(&x, &k)
		var result bool = check(x, k)
		if result {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

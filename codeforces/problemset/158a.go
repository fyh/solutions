package main

import (
	"fmt"
)

const (
	maxn = 55
)

func main() {
	var a [maxn]int
	var n, k int
	fmt.Scan(&n, &k)
	var ans int
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
		if a[i] >= a[k-1] && a[i] > 0 {
			ans++
		}
	}
	if n > 0 {
		fmt.Println(ans)
	}
}

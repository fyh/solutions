package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)

func rint(pint *int) {
	fmt.Fscan(in, pint)
}

func main() {
	var n int
	var c = [5]int{}
	rint(&n)
	for i := 0; i < n; i++ {
		var x int
		rint(&x)
		c[x]++
	}
	var ans = c[4] + c[3] + (c[2]+1)/2
	c[1] -= c[3] + c[2]%2*2
	if c[1] > 0 {
		ans += (c[1] + 3) / 4
	}
	fmt.Println(ans)
}

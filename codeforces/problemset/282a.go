package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	var n, ans int
	var op string
	fmt.Fscan(in, &n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &op)
		if op[1] == '+' {
			ans++
		} else {
			ans--
		}
	}
	fmt.Println(ans)
}

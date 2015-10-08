package main

import (
	"fmt"
	"strings"
)

var str string

func isv(ch byte) bool {
	return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y'
}

func main() {
	fmt.Scan(&str)
	str = strings.ToLower(str)
	for i := range str {
		if !isv(str[i]) {
			fmt.Printf("%c%c", '.', str[i])
		}
	}
	fmt.Println()
}

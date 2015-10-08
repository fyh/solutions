package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func isLower(ch byte) bool { return 'a' <= ch && ch <= 'z' }

func main() {
	var str string
	in := bufio.NewReader(os.Stdin)
	fmt.Fscan(in, &str)
	if str == strings.ToUpper(str) {
		fmt.Println(strings.ToLower(str))
	} else if isLower(str[0]) && str[1:] == strings.ToUpper(str[1:]) {
		fmt.Printf("%c%s\n", str[0]-'a'+'A', strings.ToLower(str[1:]))
	} else {
		fmt.Println(str)
	}
}

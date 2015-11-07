package main

import (
	"errors"
	"fmt"
)

type Stack []interface{}

func (s Stack) Empty() bool { return len(s) == 0 }
func (s Stack) Size() int   { return len(s) }
func (s Stack) Peek() interface{} {
	if s.Empty() {
		return nil
	}
	return s[len(s)-1]
}
func (s *Stack) Push(e interface{}) Stack {
	return append(*s, e)
}

func (s *Stack) Pop() (Stack, error) {
	if s.Empty() {
		return *s, errors.New("empty stack!")
	}
	*s = (*s)[:len(s)-1]
	return *s, nil
}

func main() {
	var str string
	fmt.Scanf("%s", str)

	var s Stack
	for _, ch := range str {
		for !s.Empty() && s.Peek() != ch {
			s.Pop()
		}
		s = s.Push(ch)
		if s.Size() >= 7 {
			fmt.Println("YES")
			return
		}
	}
	fmt.Println("NO")
	return
}

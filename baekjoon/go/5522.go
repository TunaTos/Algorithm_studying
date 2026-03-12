package main

import (
	"bufio"
	"errors"
	"fmt"
	"os"
)

var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)
var arr []int
var n int

func input() {

	arr = make([]int, 5)

	for i := 0; i < 5; i++ {
		fmt.Fscan(reader, &arr[i])
	}
}

func solve() (r int, err error) {
	res := 0

	for _, v := range arr {
		res += v
	}

	return res, errors.New("Error")
}

func main() {
	defer writer.Flush()

	input()
	res, _ := solve()
	fmt.Fprintln(writer, res)

}

package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var N, M int
var writer = bufio.NewWriter(os.Stdout)
var reader = bufio.NewReader(os.Stdin)
var numbers []int

func input() {
	fmt.Fscan(reader, &N)
	numbers = make([]int, N)

	for i := 0; i < N; i++ {
		fmt.Fscan(reader, &numbers[i])
	}

	sort.Ints(numbers)
}

func solve() {
	fmt.Fscan(reader, &M)
	num := 0

	for i := 0; i < M; i++ {
		fmt.Fscan(reader, &num)

		if bSearch(num) != -1 {
			fmt.Printf("1\n")
		} else {
			fmt.Printf("0\n")
		}
	}

}
func bSearch(num int) int {
	left, right := 0, N-1

	for left <= right {
		mid := (left + right) / 2

		if numbers[mid] == num {
			return mid
		} else if numbers[mid] > num {
			right = mid - 1
		} else {
			left = mid + 1
		}
	}

	return -1
}

func main() {
	defer writer.Flush()
	input()
	solve()
}

package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var cNum, nNum int
var cards, numbers []int
var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

func showSlice(arr []int) {
	for i := 1; i < len(arr); i++ {
		fmt.Print(arr[i], " ")
	}
	fmt.Println()
}

func input() {
	fmt.Fscan(reader, &cNum)
	cards = make([]int, cNum)

	for i := 0; i < cNum; i++ {
		fmt.Fscan(reader, &cards[i])
	}

	fmt.Fscan(reader, &nNum)
	numbers = make([]int, nNum+1)

	for i := 1; i <= nNum; i++ {
		fmt.Fscan(reader, &numbers[i])
	}

	sort.Ints(cards)

}

func bSearch(num int) bool {
	left := 0
	right := len(cards) - 1

	for left <= right {
		mid := (left + right) / 2

		if cards[mid] == num {
			return true
		} else if cards[mid] > num {
			right = mid - 1
		} else {
			left = mid + 1
		}
	}

	return false

}
func main() {
	input()
	defer writer.Flush()

	for i := 1; i <= nNum; i++ {
		if bSearch(numbers[i]) {
			fmt.Fprint(writer, 1, " ")
		} else {
			fmt.Fprint(writer, 0, " ")
		}
	}
}

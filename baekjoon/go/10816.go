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

func input() {
	fmt.Fscan(reader, &cNum)
	cards = make([]int, cNum)

	for i := 0; i < cNum; i++ {
		fmt.Fscan(reader, &cards[i])
	}

	fmt.Fscan(reader, &nNum)
	numbers = make([]int, nNum)

	for i := 0; i < nNum; i++ {
		fmt.Fscan(reader, &numbers[i])
	}

	sort.Slice(cards, func(i, j int) bool {
		return cards[i] < cards[j]
	})
}

func lowerBound(num int) int {
	// 해당 값보다 크거나 같은 값 중에서 가장 작은 index

	left := 0
	right := cNum

	for left < right {
		mid := (left + right) / 2

		if cards[mid] < num {
			left = mid + 1
		} else {
			right = mid
		}
	}
	return left
}

func upperBound(num int) int {
	// 해당 값보다 큰 가장 작은 인덱스

	left := 0
	right := cNum

	for left < right {
		mid := (left + right) / 2

		if cards[mid] <= num {
			left = mid + 1
		} else {
			right = mid
		}
	}
	return left
}

func main() {
	defer writer.Flush()

	input()
	for i := 0; i < nNum; i++ {
		fmt.Fprint(writer, upperBound(numbers[i])-lowerBound(numbers[i]), " ")
	}
}

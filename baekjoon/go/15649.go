package main

import (
	"bufio"
	"fmt"
	"os"
)

var N, M int
var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)
var numbers, selected []int
var visited []bool

func input() {
	fmt.Fscan(reader, &N, &M)

	numbers = make([]int, N+1)
	visited = make([]bool, N+1)
	selected = make([]int, 0)

	for i := 1; i <= N; i++ {
		numbers[i] = i
	}
}

func dfs() {
	if len(selected) == M {
		for i := 0; i < M; i++ {
			fmt.Fprintf(writer, "%d ", selected[i])
		}
		fmt.Fprintf(writer, "\n")
		return
	}

	for i := 1; i <= N; i++ {
		if !visited[i] {
			visited[i] = true
			selected = append(selected, i)

			dfs()

			visited[i] = false
			selected = selected[:len(selected)-1]
		}
	}
}

func main() {
	defer writer.Flush()

	input()
	dfs()
}

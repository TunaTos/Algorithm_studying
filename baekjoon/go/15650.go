package main

import (
	"bufio"
	"fmt"
	"os"
)

var N, M int
var writer = bufio.NewWriter(os.Stdout)
var reader = bufio.NewReader(os.Stdin)
var selected []int
var visited []bool

func input() {
	fmt.Fscan(reader, &N, &M)

	selected, visited = make([]int, N), make([]bool, N)
}

func dfs(idx int, dpt int) {
	if dpt == M {
		for i := 0; i < N; i++ {
			if visited[i] {
				fmt.Fprintf(writer, "%d ", i+1)
			}
		}
		fmt.Fprintln(writer)
		return
	}

	for i := idx; i < N; i++ {
		if !visited[i] {
			visited[i] = true

			dfs(i+1, dpt+1)

			visited[i] = false
		}
	}

}

func main() {
	defer writer.Flush()
	input()
	dfs(0, 0)
}

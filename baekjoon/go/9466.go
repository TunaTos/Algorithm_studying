/*
프로젝트의 팀원수에는 제한이 없음
모든 학생들이 동일한 팀원 가능, 한 팀만 존재할 수도 있음
모든 학생은 같이 하고 싶은 사람 선택 (한 명)
본인이 본이 선택하는거 가능



*/

package main

import (
	"bufio"
	"fmt"
	"os"
)

const WHITE = 0
const GRAY = 1
const BLACK = 2

var testCase, n, res int
var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)
var color, idx []int
var adj [][]int

func input() {
	fmt.Fscan(reader, &n)

	// init data structures
	color = make([]int, n+1)
	idx = make([]int, n+1)
	adj = make([][]int, n+1)
	res = n

	for i := 1; i <= n; i++ {
		adj[i] = make([]int, 0)
	}

	to := 0
	for from := 1; from <= n; from++ {
		fmt.Fscan(reader, &to)
		adj[from] = append(adj[from], to)
	}
}

func dfs(node int, cnt int) {
	idx[node] = cnt
	color[node] = GRAY

	for _, nextNode := range adj[node] {
		if color[nextNode] == BLACK {
			continue
		} else if color[nextNode] == WHITE {
			dfs(nextNode, cnt+1)
		} else {
			res = res - (idx[node] - idx[nextNode] + 1)
		}
	}

	color[node] = BLACK
}

func solve() {
	for i := 1; i <= n; i++ {
		if color[i] == WHITE {
			dfs(i, 1)
		}
	}
}

func main() {
	defer writer.Flush()

	fmt.Fscan(reader, &testCase)

	for i := 0; i < testCase; i++ {
		input()
		solve()
		fmt.Fprintf(writer, "%d\n", res)
	}
}

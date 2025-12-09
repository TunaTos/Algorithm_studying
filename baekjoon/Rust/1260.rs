use std::io::{self, Read, Write};
use std::collections::VecDeque;

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut tokens = input.split_whitespace();
    
    macro_rules! next {
        ($t:ty) => { tokens.next().unwrap().parse::<$t>().unwrap() };
    }
    
    let n = next!(usize);  // 정점 개수
    let m = next!(usize);  // 간선 개수
    let v = next!(usize);  // 시작 정점
    
    let mut adj: Vec<Vec<usize>> = vec![vec![]; n + 1];
    
    // 간선 입력
    for _ in 0..m {
        let a = next!(usize);
        let b = next!(usize);
        adj[a].push(b);
        adj[b].push(a);
    }
    
    // 정렬 (작은 번호부터 방문)
    for i in 1..=n {
        adj[i].sort();
    }
    
    let mut output = Vec::new();
    
    // DFS
    let mut visited = vec![false; n + 1];
    let mut dfs_result = Vec::new();
    dfs(v, &adj, &mut visited, &mut dfs_result);
    for num in &dfs_result {
        write!(output, "{} ", num).unwrap();
    }
    writeln!(output).unwrap();
    
    // BFS
    let mut visited = vec![false; n + 1];
    let bfs_result = bfs(v, &adj, &mut visited);
    for num in &bfs_result {
        write!(output, "{} ", num).unwrap();
    }
    writeln!(output).unwrap();
    
    print!("{}", String::from_utf8(output).unwrap());
}

fn dfs(node: usize, adj: &Vec<Vec<usize>>, visited: &mut Vec<bool>, result: &mut Vec<usize>) {
    visited[node] = true;
    result.push(node);
    
    for &next in &adj[node] {
        if !visited[next] {
            dfs(next, adj, visited, result);
        }
    }
}

fn bfs(start: usize, adj: &Vec<Vec<usize>>, visited: &mut Vec<bool>) -> Vec<usize> {
    let mut result = Vec::new();
    let mut queue = VecDeque::new();
    
    queue.push_back(start);
    visited[start] = true;
    
    while let Some(node) = queue.pop_front() {
        result.push(node);
        
        for &next in &adj[node] {
            if !visited[next] {
                visited[next] = true;
                queue.push_back(next);
            }
        }
    }
    
    result
}
use std::io;
use std::collections::BinaryHeap;
use std::cmp::Reverse;

const INF: i32 = 987654321;

fn main() {
    let mut buffer = String::new();
    
    io::stdin().read_line(&mut buffer).unwrap();
    let mut iter = buffer.split_whitespace();
    let v: usize = iter.next().unwrap().parse().unwrap();
    let e: usize = iter.next().unwrap().parse().unwrap();
    
    buffer.clear();
    io::stdin().read_line(&mut buffer).unwrap();
    let s: usize = buffer.trim().parse().unwrap();
    
    let mut dis = vec![INF; v + 1];
    let mut adj: Vec<Vec<(usize, i32)>> = vec![vec![]; v + 1];
    
    for _ in 0..e {
        buffer.clear();
        io::stdin().read_line(&mut buffer).unwrap();
        let mut iter = buffer.split_whitespace();
        let v1: usize = iter.next().unwrap().parse().unwrap();
        let v2: usize = iter.next().unwrap().parse().unwrap();
        let w: i32 = iter.next().unwrap().parse().unwrap();
        adj[v1].push((v2, w));
    }
    
    // Dijkstra - BinaryHeap 사용
    let mut pq = BinaryHeap::new();
    dis[s] = 0;
    pq.push(Reverse((0, s)));  // (거리, 노드)
    
    while let Some(Reverse((cost, node))) = pq.pop() {
        if cost > dis[node] {
            continue;
        }
        
        for &(next, weight) in &adj[node] {
            let next_cost = cost + weight;
            if next_cost < dis[next] {
                dis[next] = next_cost;
                pq.push(Reverse((next_cost, next)));
            }
        }
    }
    
    // 출력
    for i in 1..=v {
        if dis[i] == INF {
            println!("INF");
        } else {
            println!("{}", dis[i]);
        }
    }
}
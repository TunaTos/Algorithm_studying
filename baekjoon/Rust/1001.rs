use std::{io, str::SplitWhitespace};

fn solve(iter: &mut SplitWhitespace) -> i32 {

    let num1: i32 = iter.next().unwrap().parse().unwrap();
    let num2: i32 = iter.next().unwrap().parse().unwrap();

    num1 - num2
}

fn main() {
    let mut buf = String::new();
    
    io::stdin().read_line(&mut buf);
    let mut iter = buf.trim().split_whitespace();

    println!("{}",solve(&mut iter));
}
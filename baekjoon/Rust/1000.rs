use std::io;

fn main() {
    let mut buf = String::new();    
    io::stdin().read_line(&mut buf).expect("Error");
    buf.trim();


    let numbers: Vec<i32> = buf
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();

    println!("{}", numbers[0] + numbers[1]);
}
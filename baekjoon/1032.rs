
use std::i32;
use std::string;
use std::io;

fn show_str(s: &mut String) {
    for ele in s.chars() {
        print!("{}", ele);
    }println!();
}

fn solve(s: &mut String, N: &i32) {
    let mut final_chars: Vec<char> = s.chars().collect(); 
    for _ in 1..*N { 
        let mut comp_str = String::new();
        io::stdin()
            .read_line(&mut comp_str)
            .expect("compare_string failed");

        let comp_chars: Vec<char> = comp_str.chars().collect();

        let len = final_chars.len().min(comp_chars.len()); 
        for i in 0..len {
            if final_chars[i] != comp_chars[i] {
                final_chars[i] = '?'; 
            }
        }
    }

    let result: String = final_chars.into_iter().collect(); 
    println!("{}", result); 
}


fn main() {
    let mut input  = String::new();
    let mut input_number = String::new();
    
    io::stdin()
        .read_line(&mut input_number)
        .expect("Failed in input"); 
    
    let N: i32 = input_number.trim().parse().expect("Failed in change integer");
    
    io::stdin()
            .read_line(&mut input)
            .expect("Input Failed");
    solve(&mut input, &N);    
}
use std::io::{self, Read};


fn swap(com:&mut i32, con:&mut i32) {
    let mut tmp:i32 = *com;

    if *con > *com {
        *com = *con;
        *con = tmp;
    } else if *con == *com {
        *con -= 1;
    }
}

fn main() {
    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer);
    let mut iter = buffer.split_whitespace();
    
    let N:i32 = iter.next().unwrap().parse().unwrap();
    let A: i32 = iter.next().unwrap().parse().unwrap();
    let B: i32 = iter.next().unwrap().parse().unwrap();


    let mut compliment:i32 = 1;
    let mut condemn:i32 = 1;

    for i in 1..=N {
        compliment = compliment + A;
        condemn = condemn + B;

        swap(&mut compliment, &mut condemn);
    }
    println!("{} {}", compliment, condemn);
}
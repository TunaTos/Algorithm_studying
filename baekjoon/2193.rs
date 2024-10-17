use std::io;

const MAX_N: usize = 91;

fn get_result(zero_start: &mut Vec<i128>, first_start: &mut Vec<i128>, n: usize) {
    let mut index = 3;
    while index <= n {
        zero_start[index] = zero_start[index - 1] + first_start[index - 1];
        first_start[index] = zero_start[index - 1];
        index += 1;
    }
}

fn main() {
    let mut input = String::new();
    io::stdin()
        .read_line(&mut input)
        .expect("Error in input");

    let n: usize = input.trim().parse().expect("Failed in N");
    
    let mut zero_start_dp = vec![0i128; MAX_N];  
    let mut first_start_dp = vec![0i128; MAX_N]; 

    zero_start_dp[1] = 0; 
    zero_start_dp[2] = 2; 

    first_start_dp[1] = 1; 
    first_start_dp[2] = 1; 

    get_result(&mut zero_start_dp, &mut first_start_dp, n);

    let result = first_start_dp[n];
    println!("{}", result);
}

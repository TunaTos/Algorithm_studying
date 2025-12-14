use std::io::stdin;

fn main() {
    let mut buffer = String::new();
    
    stdin().read_line(&mut buffer).unwrap();
    let n: usize = buffer.trim().parse().unwrap();
    
    buffer.clear();
    stdin().read_line(&mut buffer).unwrap();
    
    let nums: Vec<u128> = buffer
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();
    
    const MOD: u128 = 1_000_000_007;
    let mut result: u128 = 0;
    
    let mut prefix_sum: Vec<u128> = vec![0];
    for &num in &nums {
        prefix_sum.push(prefix_sum.last().unwrap() + num);
    }
    
    for i in 0..n {
        let current = nums[i];
        let sum_after = prefix_sum[n] - prefix_sum[i + 1];
        
        result = (result + (current % MOD) * (sum_after % MOD)) % MOD;
    }
    
    println!("{}", result);
}
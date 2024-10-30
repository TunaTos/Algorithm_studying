use std::io::{self, BufRead};

fn get_sum(num: u128) -> u128 {
    num * (num + 1) / 2
}

fn get_vector_sum(k: u128, my_vec: &Vec<u128>, k_goal: u128) -> u128 {
    let mut sum: u128 = 0;

    for i in 1..my_vec.len() {
        let distance;
        if i == my_vec.len() - 1 {
            sum += get_sum(k);
        } else {
            distance = my_vec[i + 1] - my_vec[i];
            if distance >= k {
                sum += get_sum(k);
            } else {
                sum += get_sum(k) - get_sum(k - distance);
            }
        }

        if sum >= k_goal {
            return sum;
        }
    }
    sum
}

fn solve(n: u128, k_goal: u128, my_vec: Vec<u128>) {
    let (mut left, mut right) = (1, 10_u128.pow(18));
    let mut answer = right;

    while left <= right {
        let mid = (left + right) / 2;
        if get_vector_sum(mid, &my_vec, k_goal) >= k_goal {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    println!("{}", answer);
}

fn main() {
    let stdin = io::stdin();
    let mut iterator = stdin.lock().lines();

    let first_line = iterator.next().unwrap().unwrap();
    let mut input_iter = first_line.split_whitespace();
    let n: u128 = input_iter.next().unwrap().parse().unwrap();
    let k_goal: u128 = input_iter.next().unwrap().parse().unwrap();

    let second_line = iterator.next().unwrap().unwrap();
    let mut my_vec: Vec<u128> = second_line
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();

    my_vec.insert(0, 0);

    solve(n, k_goal, my_vec);
}

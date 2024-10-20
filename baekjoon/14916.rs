use std::io;

fn min(i: isize, j: isize) -> isize {
    if i < j {
        i
    } else {
        j
    }
}

fn get_result(dp: &mut Vec<isize>, n: usize) {
    for i in 6..=n {
        let tmp1 = dp[i-2];
        let tmp2 = dp[i-5];

        if tmp1 == -1 && tmp2 == -1 {
            dp[i] = -1;
        }
        else if tmp1 == -1 && tmp2 != -1 {
            dp[i] = tmp2 + 1;
        }
        else if tmp1 != -1 && tmp2 == -1 {
            dp[i] = tmp1 + 1;
        }
        else {
            dp[i] = min(tmp1, tmp2) + 1;
        }
    }
}

fn main() {
    let mut buffer = String::new();
    io::stdin()
        .read_line(&mut buffer)
        .expect("stdin Failed");

    let N: usize = buffer.trim().parse().expect("parsing Failed");

    let mut dp: Vec<isize> = vec![-1; N + 1];

    if N == 2 || N == 5 {
        println!("{}", 1);
        return;
    }
    if N == 0 || N == 1 || N == 3 {
        println!("-1");
        return;
    }

    if N >= 2 {
        dp[2] = 1;
    }
    if N >= 5 {
        dp[5] = 1; 
    }
    dp[4] = 2;
    get_result(&mut dp, N);
    //println!("{:?}", dp);
    println!("{}", dp[N]);
}

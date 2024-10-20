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
        let tmp1 = dp[i - 2];
        let tmp2 = dp[i - 5];

        dp[i] = match (tmp1, tmp2) {
            (-1, -1) => -1,
            (-1, _) => tmp2 + 1,
            (_, -1) => tmp1 + 1,
            _ => min(tmp1, tmp2) + 1,
        };
    }
}

fn handle_base_cases(n: usize) -> Option<isize> {
    match n {
        0 | 1 | 3 => Some(-1),
        2 | 5 => Some(1),
        _ => None,
    }
}

fn main() {
    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer).expect("stdin Failed");
    let n: usize = buffer.trim().parse().expect("parsing Failed");

    if let Some(result) = handle_base_cases(n) {
        println!("{}", result);
        return;
    }

    let mut dp: Vec<isize> = vec![-1; n + 1];

    if n >= 2 {
        dp[2] = 1;
    }
    if n >= 4 {
        dp[4] = 2;
    }
    if n >= 5 {
        dp[5] = 1;
    }

    get_result(&mut dp, n);
    
    println!("{}", dp[n]);
}


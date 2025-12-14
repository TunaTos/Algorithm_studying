use std::{collections::HashSet, hash::Hash, io::{self, BufWriter, Read, stdout}, string, vec};

macro_rules! input {
    ($iter: expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().unwrap()
    };
}


fn main() {
    let mut buf = String::new();
    let mut out = BufWriter::new(io::stdout().lock());

    let mut hash: HashSet<String> = HashSet::new();
    
    io::stdin().read_to_string(&mut buf).unwrap();
    let mut iter = buf.split_whitespace();

    let N = input!(iter, usize);

    for _ in (0..N) {
        let mut my_string = iter.next().unwrap();
        let mut chars: Vec<char> = my_string.chars().collect();
        chars.sort();
        
        let sorted_string: String = chars.iter().collect();
        hash.insert(sorted_string);
    }

    println!("{:?}", hash.len());
    
}

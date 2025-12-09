use std::io::{self, BufReader, BufWriter, Write};

macro_rules! parse {
    ($iter:expr, $ty: ty) => {
        $iter.next().unwrap().parse::<$ty>().unwrap()
    };
}

fn main() {
    let mut out = BufWriter::new(io::stdout().lock());
    let mut buf = String::new();

    io::stdin().read_line(&mut buf).unwrap();
    let mut iter = buf.split_whitespace();

    let n = parse!(iter, usize);
    
    for _ in 0..n {
        let mut buf = String::new();
        io::stdin().read_line(&mut buf).unwrap();
        let mut iter = buf.split_whitespace();

        let num1 = parse!(iter, usize);
        let num2 = parse!(iter, usize);
        
        writeln!(out, "{}", num1 + num2);
        
    }

}

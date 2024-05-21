mod parse;
use std::fs;

// Simple Test Function
fn main() {
    let filename = "set.txt";
    let stream = fs::read_to_string(filename).expect("Invalid path");
    let data = parse::gen_insn_set(&stream);

    for i in 0..data.len() {
        let (hd, tl) = &data[i];
        println!("{:?}", tl);
    }
}
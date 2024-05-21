use regex::Regex;

/*
    tokenize_insn transforms an instruction into a set of tokens
    @param stream – Text-based instruction
    @return – Parsed vector of tokens
*/
fn tokenize_insn(stream: &str) -> Vec<&str> {
    // Split on commas and spaces
    let delim = Regex::new(r",*\s+").unwrap();
    let tokens = delim.split(stream);
    return tokens.collect::<Vec<&str>>();
}

/*
parse_insn parses a given stream into an instruction name and argument set
@param stream – Text-based instruction
@return – Fully parsed instruction
*/
fn parse_insn(stream: &str) -> (&str, Vec<&str>) {
    let mut tokens = tokenize_insn(stream);
    let args = tokens.split_off(1);
    return (tokens[0], args);
}

/*
    get_insn_set parses a set of instructions into a series of names and arguments
    @param path – Filename for instruction list
    @return – Parsed set of instructions and arguments
*/

pub fn gen_insn_set(stream: &str) -> Vec<(&str, Vec<&str>)> {
    // Split on semicolons & new lines
    let delim = Regex::new(r";\n*").unwrap();
    let insn_lst = delim.split(&stream).collect::<Vec<&str>>();

    let mut instructions = Vec::new();
    for i in 0..insn_lst.len()-1 {
        instructions.push(parse_insn(insn_lst[i]));
    }
    return instructions;
}
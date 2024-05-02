
fn main() {
    let sum_of_squares: u32 = (1..10).map(|x| x * x).sum();
    println!("Hello, world!");
    let name:String = "Vieve".to_string();
    println!("{}", hello (name, 20));
    println!("{}", sum_of_squares);
}

fn hello (name:String, age:u32) -> String {
    return format!("Hello, {} year old named {}", age, name);
}

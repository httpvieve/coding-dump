use std::io; // adds standard -> input/output library into scope
use std::cmp::Ordering;
fn get_num () -> String {
    let mut input = String::new();
    println! ("Enter the number to be guessed: ");
    io::stdin().read_line (&mut input)
        .expect ("Failed to read input");
    input
    }
fn main() {
    let answer = get_num();
    let mut state = false;
    let mut attempts = 0;
    println!("Guess the number!");
    
    //let foo = 5; // immutable (constant?)
    // let mut bar = 5; // mutable (can be changed)
    while attempts < 3 && state == false {
        
        println!("Please input your guess.");
        let mut prompt = String::new(); // static method
        
        io::stdin().read_line (&mut prompt)
            .expect ("Failed to read input");        
        println! ("User guessed: {}", prompt);
        
        attempts += 1;
        
        match prompt.cmp (&answer) {
        Ordering :: Less => println!("Prompted number is too small!"),
        Ordering :: Greater => println!("Prompted number is too large!"),
        Ordering::Equal => state = true,
        }
}

    if state == false { println!("Out of attempts! Try again next time.."); } else { println!("Correct!");}


}


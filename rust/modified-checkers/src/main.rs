
use std::io;

const COL : u32 = 5;
const ROW : u32 = 7;
const FORWARD : i32 = 0;
const LEFT : i32 = -1;
const RIGHT : i32 = 1;

type mut board = vec![vec![0; COL]; ROW];
struct Coordinate {
    x : u64, 
    y : u64,
}

// struct Set {
//     count : u64,
//     coordinate : Coordinate,
// }

// struct Game {
//     alpha : Set,
//     beta : Set,
//     free : Set,
//     valid : Set,
//     _S : Set,
//     _Y : Set,
//     _E : Set,
//     prev : Coordinate,
//     next : Coordinate,
//     over :bool, 
//     ok : bool, 
//     aTurn : bool,
// }

impl Coordinate {
    
    fn GetMove (&mut self, aTurn : bool, mode : i32) {
        self.y += mode;
        if aTurn { self.x -= 1 } 
        else { self.x += 1 }
    }
    
    
    fn GetPiece (avail : Set) -> Coordinate {
        let mut tile = Coordinate::new();
        let mut i = i32::new();
        for i in 0..(avail.len() - 1) { 
            println!("\t[{}] ({}, {})\n", i + 1, avail.coordinate[i].x, avail.coordinate[i].y); 
        }
        println! 


    }
    fn GetMove (prev: &self, avail:Set, aTurn: bool) -> Coordinate {}

}   
impl Set {
    fn AvailablePieces (&self, &game: Game) -> Set {}
    fn ModifyValid (&self, &game: Game) -> Set {}
}
fn GameOver (&game: Game) -> bool {

}
    fn Contains (&tile: Coordinate, &current: Set) -> bool {

}

for i in 1..100 


fn board () {
    println!("
             ╔═══╦═══╦═══╦═══╦═══╗
             ║   ║   ║   ║   ║   ║
             ╠═══╬═══╬═══╬═══╬═══╣
             ║   ║   ║   ║   ║   ║
             ╠═══╬═══╬═══╬═══╬═══╣
             ║   ║   ║   ║   ║   ║
             ╠═══╬═══╬═══╬═══╬═══╣
             ║   ║   ║   ║   ║   ║
             ╠═══╬═══╬═══╬═══╬═══╣
             ║   ║   ║   ║   ║   ║
             ╠═══╬═══╬═══╬═══╬═══╣
             ║   ║   ║   ║   ║   ║
             ╠═══╬═══╬═══╬═══╬═══╣
             ║   ║   ║   ║   ║   ║
             ╚═══╩═══╩═══╩═══╩═══╝\n"

            //  println!("╔═══╦═══╦═══╦═══╦═══╗\n"
            //  "║ {} ║ {} ║ {} ║ {} ║ {} ║\n"
            //  "╠═══╬═══╬═══╬═══╬═══╣\n"
            //  "║ {} ║ {} ║ {} ║ {} ║ {} ║\n"
            //  "╠═══╬═══╬═══╬═══╬═══╣\n"
            //  "║ {} ║ {} ║ {} ║ {} ║ {} ║\n"
            //  "╠═══╬═══╬═══╬═══╬═══╣\n"
            //  "║ {} ║ {} ║ {} ║ {} ║ {} ║\n"
            //  "╠═══╬═══╬═══╬═══╬═══╣\n"
            //  "║ {} ║ {} ║ {} ║ {} ║ {} ║\n"
            //  "╠═══╬═══╬═══╬═══╬═══╣\n"
            //  "║ {} ║ {} ║ {} ║ {} ║ {} ║\n"
            //  "╠═══╬═══╬═══╬═══╬═══╣\n"
            //  "║ {} ║ {} ║ {} ║ {} ║ {} ║\n"
            //  "╚═══╩═══╩═══╩═══╩═══╝\n",

            );

}
fn NextPlayerMove (prev : Coordinate, &game : Game) {
    
    //DisplayBoard
}
// fn initialize_board ()
fn main() {
    //let mut board = char[][];
    println!("Success!");
    board();
}

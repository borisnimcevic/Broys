use std::io;

fn main() {

    // Get X
    let mut input = String::new();
    println!("Enter the X coordinated of the A LED:");
    io::stdin()
        .read_line(&mut input)
        .expect("something didn't work");

    let input: f32 = input.trim().parse().expect("That was not a number.");
    let a_x = input;

    // Get Y
    let mut input = String::new();
    println!("Enter the Y coordinated of the A LED:");
    io::stdin()
        .read_line(&mut input)
        .expect("something didn't work");
    let input: f32 = input.trim().parse().expect("That was not a number.");
    let a_y = input;
    

    println!("Coordinates:");
    println!("A: {a_x},{a_y}");

    let x = a_x + 2.3;
    let y = a_y + 2.3;
    println!("B = x: {x}, y: {y}");

    let x = a_x + 2.3;
    let y = a_y + 6.8;
    println!("C = x: {x}, y: {y}");

    let x = a_x;
    let y = a_y + 9.0;
    println!("D = x: {x}, y: {y}");

    let x = a_x - 2.3;
    let y = a_y + 6.8;
    println!("E = x: {x}, y: {y}");

    let x = a_x - 2.3;
    let y = a_y + 2.3;
    println!("F = x: {x}, y: {y}");

    let x = a_x;
    let y = a_y + 4.5;
    println!("G = x: {x}, y: {y}");
}

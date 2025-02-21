use std::io::{self, Write};

fn sieve_of_eratosthenes(n: usize) {
    if n < 2 {
        println!("\n\nThe N must be >= 2!");
        return;
    }

    let size = (n + 1) / 2;
    let mut is_prime = vec![true; size];

    print!("\nPrime numbers up to  {}:\n2 ", n);
    for i in (3..).step_by(2).take_while(|&i| i * i <= n) {
        if is_prime[i / 2] {
            for mult in (i * i..=n).step_by(2 * i) {
                is_prime[mult / 2] = false;
            }
        }
    }

    for i in 1..size {
        if is_prime[i] {
            print!("{} ", 2 * i + 1);
        }
    }
    println!("\n");
}

fn main() {
    let mut user_input = String::new();
    print!("Enter N:\n> ");
    io::stdout().flush().expect("Failed to flush stdout");

    if io::stdin().read_line(&mut user_input).is_err() {
        println!("\n\nInvalid input!");
        return;
    }

    match user_input.trim().parse::<usize>() {
        Ok(n) => sieve_of_eratosthenes(n),
        Err(_) => println!("\n\nInvalid input!"),
    }
}

use rustst::stack_ds::stack::Stack;
use std::io;

fn main() {
    let mut input = String::new();
    let mut test_stack: Stack<i32> = Stack::new();
    println!("Give me the size of your stack:");
    io::stdin().read_line(&mut input).unwrap();
    let stack_size: i32 = input.trim().parse().unwrap();

    println!("Give me your numbers:");
    let mut i = 0;
    let mut number: i32;
    while i < stack_size {
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        number = input.trim().parse().unwrap();
        test_stack.push(number);

        i += 1;
    }

    println!("\n");

    if test_stack.is_empty() {
        println!("The stack is not empty \n");
    } else {
        println!("The stack is empty \n");
    }

    let mut top_value = test_stack.peek();
    println!("The top of your stack now is: {}\n", top_value);

    println!("Your stack is: ");
    test_stack.print();
    println!("\n");
    test_stack.pop();
    println!("Your stack after popping is: \n");
    test_stack.print();
    println!("\n");

    top_value = test_stack.peek();
    println!("The top of your stack now is: {}\n \n", top_value);

    test_stack.pop();
    test_stack.pop();

    if test_stack.is_empty() {
        println!("The stack is not empty even after all the popping \n");
    } else {
        println!("The stack is empty after all the popping \n");
    }
}

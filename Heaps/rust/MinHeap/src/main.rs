use std::io;
use rustminh::min_heap_ds::min_heap::MinHeap;

fn main() {
    let mut test_minheap: MinHeap<i32> = MinHeap::new();
    let mut input = String::new();
    let number_elements: i32;
    let mut number: i32;

    println!("Introduce the number of elements you would like to insert");
    io::stdin().read_line(&mut input).unwrap();
    number_elements = input.trim().parse().unwrap();
    println!("Give me your elements");

    let mut i = 0;
    while i < number_elements {
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        number = input.trim().parse().unwrap();
        test_minheap.insert_element(number);
        i += 1;
    }

    test_minheap.print();
    println!("\n");

    
    let element = test_minheap.pop_element();
    match element {
        Some(value) => println!("Your popped element is: {}",value),
        None => println!("Your heap is empty"),
    }
    
    println!("\n");
    test_minheap.print();
    println!("\n");
}

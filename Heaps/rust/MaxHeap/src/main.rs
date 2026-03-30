use rustmaxh::max_heap_ds::max_heap::MaxHeap;
use std::io;

fn main() {
    let mut test_maxheap: MaxHeap<i32> = MaxHeap::new();
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
        test_maxheap.insert_element(number);
        i += 1;
    }

    test_maxheap.print();
    println!("\n");

    let element = test_maxheap.pop_element();
    match element {
        Some(value) => println!("Your popped element is: {}",value),
        None => println!("Your heap is empty"),
    }
    
    println!("\n");
    test_maxheap.print();
    println!("\n");
}

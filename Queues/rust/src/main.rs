use rustqueue::queue_ds::queue::Queue;
use std::io;

fn main() {
    let mut test_queue: Queue<i32> = Queue::new();

    let mut input = String::new();
    let queue_size: i32;
    println!("Give me the size of your queue \n");
    io::stdin().read_line(&mut input).unwrap();
    queue_size = input.trim().parse().unwrap();

    println!("Give me your numbers: \n ");
    let mut number: i32;
    let mut i = 0;
    while i < queue_size {
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        number = input.trim().parse().unwrap();
        test_queue.enqueue(number);
        i += 1;
    }

    if test_queue.is_empty() {
        println!("Your queue is empty");
    } else {
        println!("Your queue is not empty");
    }

    println!("\n");

    println!("Your queue is: \n");
    test_queue.print();
    test_queue.dequeue();
    println!("Your queue after dequeueing is: \n");
    test_queue.print();
    println!("The top of queue now is: {} \n",test_queue.peek());
    test_queue.dequeue();
    test_queue.dequeue();
    
    if test_queue.is_empty() {
        println!("Your queue after dequeuing many times is empty");
    } else {
        println!("Your queue after dequeueing many times is not empty");
    }
}

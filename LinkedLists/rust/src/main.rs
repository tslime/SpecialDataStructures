use std::io;

use rustll::linked_list_ds::linked_list::LinkedList;

fn main() {
    let mut test_list: LinkedList<i32> = LinkedList::new();

    let mut input = String::new();
    let list_size: i32;
    println!("Give me the size of your list:");
    io::stdin().read_line(&mut input).unwrap();
    list_size = input.trim().parse().unwrap();

    println!("Give me your numbers \n");
    let mut number: i32;
    let mut i = 0;
    while i < list_size {
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        number = input.trim().parse().unwrap();
        test_list.insert_linked_list(number);
        i += 1;
    }
    println!("\n");

    if test_list.is_empty() {
        print!("Your list is empty \n");
    } else {
        println!("Your list is not empty \n");
    }

    
    println!("Your linked list is: \n");
    test_list.print_linked_list();
    println!("\n");

    input.clear();
    println!("Give me the element you are searching for");
    io::stdin().read_line(&mut input).unwrap();
    let mut target_element: i32 = input.trim().parse().unwrap();
    if test_list.search_linked_list(target_element) {
        println!("This element exist");
    } else{
        println!("This elemen does not exist \n");
    }

    input.clear();
    println!("Now give me the element you want to delete");
    io::stdin().read_line(&mut input).unwrap();
    target_element = input.trim().parse().unwrap();
    if !test_list.is_empty() {
        test_list.delete_linked_list(target_element);
    } else {
        println!("Cannot delete. List is empty");
    }

    println!("Your new list is:");
    test_list.print_linked_list();
    println!("\n");
    


}

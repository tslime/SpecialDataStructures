use rustbt::binary_tree_ds::binary_tree::BinaryTree;
use std::io;

fn main() {
    let mut test_tree: BinaryTree<i32> = BinaryTree::new();

    let mut input = String::new();
    println!("Give me the number of elements would you like to insert: ");
    io::stdin().read_line(&mut input).unwrap();
    let number_elements: i32 = input.trim().parse().unwrap();

    println!("\n");
    println!("Give me all your elements");
    let mut number: i32;
    let mut i = 0;
    while i < number_elements {
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        number = input.trim().parse().unwrap();
        test_tree.insert(number);
        i += 1;
    }

    println!("Your current tree is: \n");
    test_tree.print_tree();
    println!("\n");

    /*search test
    while true {
        input.clear();
        println!("Give me the element you are searching for:");
        io::stdin().read_line(&mut input).unwrap();
        number = input.trim().parse().unwrap();
        if test_tree.search(number) {
            println!("The element exist\n");
        } else {
            println!("The element does not exit \n");
        }
    }*/

    /*deletion test
    while true {
        input.clear();
        println!("Introduce the number you would like to delete:");
        io::stdin().read_line(&mut input).unwrap();
        number = input.trim().parse().unwrap();
        test_tree.delete(number);
        println!("Your tree after deleting is:");
        test_tree.print_tree();
        println!("\n");
    }*/
}

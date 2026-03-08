use crate::linked_list_ds::node::Node;

pub struct LinkedList<T> {
    head: Option<Box<Node<T>>>,
}

impl<T: std::fmt::Display + PartialEq> LinkedList<T> {
    pub fn new() -> Self {
        LinkedList { head: None }
    }

    pub fn is_empty(&self) -> bool {
        return self.head.is_none();
    }

    pub fn print_linked_list(&self) {
        if self.is_empty() {
            println!("The list is empty \n");
        } else {
            let mut aux = &self.head;
            while !aux.is_none() {
                print!("{} ", aux.as_ref().unwrap().value);
                aux = &aux.as_ref().unwrap().next;
            }
            println!("\n");
        }
    }

    pub fn insert_linked_list(&mut self, v: T) {
        let insertion_node = Node {
            value: v,
            next: None,
        };

        if self.is_empty() {
            self.head = Some(Box::new(insertion_node));
        } else {
            let mut aux = &mut self.head;
            while aux.is_some() {
                aux = &mut aux.as_mut().unwrap().next;
            }

            *aux = Some(Box::new(insertion_node));
        }
    }

    pub fn search_linked_list(&self, target_value: T) -> bool {
        let mut b = false;

        let mut aux = &self.head;
        while aux.is_some() && !b {
            if aux.as_ref().unwrap().value == target_value {
                b = true;
            } else {
                aux = &aux.as_ref().unwrap().next;
            }
        }

        return b;
    }

    pub fn delete_linked_list(&mut self, target_value: T) {
        let mut b = false;
        let mut aux = &mut self.head;

        while aux.is_some() && !b {
            if aux.as_mut().unwrap().value == target_value {
                b = true;
            } else {
                aux = &mut aux.as_mut().unwrap().next;
            }
        }

        if b {
            *aux = aux.as_mut().unwrap().next.take();
        } 
    }
}

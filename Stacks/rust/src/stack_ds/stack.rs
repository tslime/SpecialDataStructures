use crate::stack_ds::node::Node;

pub struct Stack<T> {
    top: Option<Box<Node<T>>>,
}

impl<T: std::fmt::Display> Stack<T> {
    pub fn new() -> Self {
        Stack { top: None }
    }

    pub fn print(&self) {
        if self.top.is_none() {
            println!("Your stack is empty \n");
        } else {
            let mut aux = &self.top;
            while aux.is_some() {
                print!("{} ", aux.as_ref().unwrap().value);
                aux = &aux.as_ref().unwrap().next;
            }
        }
    }

    pub fn is_empty(&self) -> bool {
        return !self.top.is_none();
    }

    pub fn peek(&self) -> &T {
        return &self.top.as_ref().unwrap().value;
    }

    pub fn push(&mut self, target_value: T) {
        let mut insertion_node = Node {
            value: target_value,
            next: None,
        };

        insertion_node.next = self.top.take();
        self.top = Some(Box::new(insertion_node));
    }

    pub fn pop(&mut self) -> T {
        let mut v = self.top.take().unwrap();
        self.top = v.next.take();

        return v.value;
    }
}

use crate::queue_ds::node::Node;

pub struct Queue<T> {
    first: Option<Box<Node<T>>>,
}

impl<T: std::fmt::Display> Queue<T> {
    pub fn new() -> Self {
        Queue { first: None }
    }

    pub fn print(&self) {
        if self.first.is_none() {
            println!("Your queue is empty \n");
        } else {
            let mut aux = &self.first;
            while aux.is_some() {
                print!("{} ", aux.as_ref().unwrap().value);
                aux = &aux.as_ref().unwrap().next;
            }
            println!("\n");
        }
    }

    pub fn is_empty(&self) -> bool {
        return self.first.is_none();
    }

    pub fn peek(&self) -> &T {
        return &self.first.as_ref().unwrap().value;
    }

    pub fn enqueue(&mut self, target_value: T) {
        let insertion_node = Node {
            value: target_value,
            next: None,
        };

        let mut aux = &mut self.first;
        while aux.is_some() {
            aux = &mut aux.as_mut().unwrap().next;
        }

        *aux = Some(Box::new(insertion_node));
    }

    pub fn dequeue(&mut self) -> T {
        let mut temp = self.first.take().unwrap();
        self.first = temp.next.take();

        return temp.value;
    }
}

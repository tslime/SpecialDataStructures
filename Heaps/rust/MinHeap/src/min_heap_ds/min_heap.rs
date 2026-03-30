use std::cmp::{PartialEq, PartialOrd};
use std::fmt::Display;

pub struct MinHeap<T> {
    pub num_elements: usize,
    pub slots: Vec<Option<T>>,
}

impl<T: Display + PartialEq + PartialOrd> MinHeap<T> {
    pub fn new() -> Self {
        let slots = Vec::with_capacity(0);
        MinHeap {
            num_elements: 0,
            slots,
        }
    }

    pub fn is_empty(&self) -> bool {
        return self.num_elements == 0;
    }

    pub fn print(&self) {
        if self.num_elements == 0 {
            println!("The heap is empty \n");
        } else {
            println!("Your heap is: ");
            for i in 0..self.num_elements {
                print!("{} ", self.slots[i].as_ref().unwrap());
            }
            println!("\n");
        }
    }

    pub fn insert_element(&mut self, target_value: T) {
        self.slots.push(Some(target_value));
        self.num_elements += 1;
        self.bubble_up(self.num_elements - 1);
    }

    fn bubble_up(&mut self, target_element_index: usize) {
        let mut child = target_element_index;
        let mut parent;
        let mut b = false;
        while !b {
            parent = ((child as i32 - 1) / 2) as usize;
            if child as i32 - 1 < 0 {
                b = true;
            } else {
                if self.slots[parent] > self.slots[child] {
                    let temp = self.slots[parent].take();
                    self.slots[parent] = self.slots[child].take();
                    self.slots[child] = temp;
                    child = parent;
                } else {
                    b = true;
                }
            }
        }
    }

    pub fn pop_element(&mut self) -> Option<T> {
        let mut element: Option<T> = None;
        if self.num_elements > 0 {
            element = self.slots[0].take();
            self.slots[0] = self.slots[self.num_elements - 1].take();
            self.num_elements -= 1;
            self.bubble_down(0);
        }

        return element;
    }

    fn bubble_down(&mut self, target_element_index: usize) {
        let mut parent = target_element_index;
        let mut left_child;
        let mut right_child;
        let mut temp;
        let mut b = false;

        while !b {
            left_child = 2 * parent + 1;
            right_child = 2 * parent + 2;
            if left_child >= self.num_elements && right_child >= self.num_elements {
                b = true;
            } else {
                if right_child < self.num_elements {
                    if self.slots[left_child] <= self.slots[right_child] {
                        if self.slots[parent] > self.slots[left_child] {
                            temp = self.slots[parent].take();
                            self.slots[parent] = self.slots[left_child].take();
                            self.slots[left_child] = temp;
                            parent = left_child;
                        } else {
                            b = true;
                        }
                    } else {
                        if self.slots[parent] > self.slots[right_child] {
                            temp = self.slots[parent].take();
                            self.slots[parent] = self.slots[right_child].take();
                            self.slots[right_child] = temp;
                            parent = right_child;
                        } else {
                            b = true;
                        }
                    }
                } else {
                    if self.slots[parent] > self.slots[left_child] {
                        temp = self.slots[parent].take();
                        self.slots[parent] = self.slots[left_child].take();
                        self.slots[left_child] = temp;
                    } else {
                        b = true;
                    }
                }
            }
        }
    }
}

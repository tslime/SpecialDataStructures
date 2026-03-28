use crate::binary_tree_ds::node::Node;
use std::cmp::{PartialEq, PartialOrd};
use std::fmt::Display;

pub struct BinaryTree<T> {
    root: Option<Box<Node<T>>>,
}

impl<T: Display + PartialOrd + PartialEq> BinaryTree<T> {
    pub fn new() -> Self {
        BinaryTree { root: None }
    }

    pub fn print_tree(&self) {
        Self::print(&self.root);
    }

    fn print(node_location: &Option<Box<Node<T>>>) {
        if let Some(node) = node_location {
            Self::print(&node.left);
            print!("{} ", node.value);
            Self::print(&node.right);
        }
    }

    pub fn search(&self, target_value: T) -> bool {
        return Self::search_node(&self.root, target_value);
    }

    fn search_node(node_location: &Option<Box<Node<T>>>, target_value: T) -> bool {
        if let Some(node) = node_location {
            if node.value == target_value {
                return true;
            } else if node.value > target_value {
                return Self::search_node(&node.left, target_value);
            } else {
                return Self::search_node(&node.right, target_value);
            }
        } else {
            return false;
        }
    }

    pub fn insert(&mut self, target_value: T) {
        Self::insert_node(&mut self.root, target_value);
    }

    fn insert_node(node_location: &mut Option<Box<Node<T>>>, target_value: T) {
        if let Some(node) = node_location {
            if node.value >= target_value {
                Self::insert_node(&mut node.left, target_value);
            } else {
                Self::insert_node(&mut node.right, target_value);
            }
        } else {
            let target_insertion_node = Node {
                value: target_value,
                left: None,
                right: None,
            };
            *node_location = Some(Box::new(target_insertion_node));
        }
    }

    pub fn delete(&mut self, target_value: T) {
        Self::delete_node(&mut self.root, target_value);
    }

    fn delete_node(node_location: &mut Option<Box<Node<T>>>, target_value: T) {
        if let Some(node) = node_location {
            if target_value > node.value {
                Self::delete_node(&mut node.right, target_value);
            } else if target_value < node.value {
                Self::delete_node(&mut node.left, target_value);
            } else {
                if node.right.is_none() {
                    *node_location = node.left.take();
                } else if node.left.is_none() {
                    *node_location = node.right.take();
                } else {
                    let target_value = Self::get_rightmost_node_value(&mut node.left);
                    node.value = target_value;
                }
            }
        }
    }

    fn get_rightmost_node_value(node_location: &mut Option<Box<Node<T>>>) -> T {
        let mut aux = node_location;
        let target_value;

        while aux.as_ref().unwrap().right.is_some() {
            aux = &mut aux.as_mut().unwrap().right;
        }
        let target_node = aux.take().unwrap();

        *aux = target_node.left;
        target_value = target_node.value;

        return target_value;
    }
}

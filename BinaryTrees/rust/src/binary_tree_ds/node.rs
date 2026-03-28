pub struct Node<T> {
    pub value: T,
    pub left: Option<Box<Node<T>>>,
    pub right: Option<Box<Node<T>>>,
}

#include <iostream>




using namespace std;


template <class T>
class Stack {
private:
    template <class N>
    class Node {
    private:
        T data;
        Node* next;
    public:
        Node(T data = T(), Node* next = nullptr) {
            this->data = data;
            this->next = next;
        }
    };

public:

    Stack();

    ~Stack();

    T stack_front(Stack<T> & stk);

    void stack_pop(Stack<T> & stk);

    void stack_push(Stack<T> & stk);

    Node<T>* head;
    int Size;
};


template <class T>
Stack<T>::Stack() {

}


template <class T>
Stack<T>::~Stack() {

}


template <class T>
T Stack<T>::stack_front(Stack<T> &stk) {

}


template <class T>
void Stack<T>::stack_pop(Stack<T> &stk) {

}


template <class T>
void Stack<T>::stack_push(Stack<T> &stk) {

}


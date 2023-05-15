#include <iostream>



using namespace std;


template <class T>
class Tree {
private:
    template <class N>
    class Node {
    private:
        T data;
        Node* right;
        Node* left;
    public:
        Node(T data = T(), Node* right = nullptr, Node* left = nullptr) {
            this->data = data;
            this->right = right;
            this->left = left;
        }
    };

public:

    Tree();

    ~Tree();



    Node<T>* root;
};
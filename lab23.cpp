#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class BinTree {
    struct Node {
        float data;
        Node* left;
        Node* right;
        Node(float val) : data(val), left(NULL), right(NULL) {}
    };

    Node* root;

public:
    BinTree() : root(NULL) {}

    void insert(float val) {
        root = insertNode(root, val);
    }

    bool search(float val) {
        return searchNode(root, val);
    }

    void inOrderTraversal() {
        inOrderTravesalNode(root);
        cout << endl;
    }

    void printTree() {
        int depth = 0;
        printTreeNode(root, &depth);
        cout << endl;
    }
    
    void isBreadthIncrease() {
        if (isStrinctlyIncrease(root))
            cout << "Breadthly Increase" << endl;
        else
            cout << "Not breadthly increase" << endl;
    }
    
    bool deleteElement(float el) {
        int depth = 0;
        if (root == nullptr) {
            return false;
        }
        else {
            deleteElementNode(root, el);
            return true;
        }
    }
    ~BinTree() {
        delete root;
    }
private:
    Node* insertNode(Node* node, float val) {
        if (node == nullptr)
            return new Node(val);
        if (val < node->data)
            node->left = insertNode(node->left, val);
        else if (val > node->data)
            node->right = insertNode(node->right, val);
        return node;
    }

    bool searchNode(Node* node, float val) {
        if (node == nullptr)
            return false;
        if (node->data == val)
            return true;
        else if (val < node->data)
            return searchNode(node->left, val);
        else
            return searchNode(node->right, val);

    }

    Node* searchEl(Node* node, float val) {
        auto nodeForDelete = node;
        if (node->data == val) {
            nodeForDelete = node;
            return nodeForDelete;
        }
        else if (node->data < val) searchEl(node->right, val);
        else searchEl(node->left, val);
    }

    void inOrderTravesalNode(Node* node) {
        if (node == nullptr)
            return;
        inOrderTravesalNode(node->left);
        cout << node->data << " ";
        inOrderTravesalNode(node->right);

    }

    void printTreeNode(Node* node, int* depth) {
        if (node->right != nullptr) {
            *depth = *depth + 1;
            printTreeNode(node->right, depth);
        }
        for (int i = 0; i < *depth; i++) {
            cout << "  ";
        }
        cout << node->data;
        cout << endl;

        if (node->left != nullptr) {
            *depth = *depth + 1;
            printTreeNode(node->left, depth);
        }
        *depth = *depth - 1;
    }

    bool isStrinctlyIncrease(Node* node) {
        queue<Node*> q;
        int count = 1;
        int new_count = count;
        bool check = true;
        if (node != nullptr) {
            q.push(node);
        }
        while (!q.empty()) {
            for (int it = 0; it < count; it++) {
                if (q.front()->left != nullptr) {
                    q.push(q.front()->left);
                    new_count++;
                }
                if (q.front()->right != nullptr) {
                    q.push(q.front()->right);
                    new_count++;
                }
                q.pop();
                new_count--;
            }
            if (new_count != 0 && new_count <= count) {
                check = false;
                break;
            }
            count = new_count;
        }
        if (check) 
            return true;
        else 
            return false;
    }
    
    Node* deleteElementNode(Node* node, float key) {
        if (node == nullptr) {
            return node;
        }
        else if (node->data > key) {
            node->left = deleteElementNode(node->left, key);
        }
        else if (node->data < key) {
            node->right = deleteElementNode(node->right, key);
        }
        else {
            if (!node->left && !node->right) {
                delete node;
                return NULL;
            }
            else if (!node->left || !node->right) {
                Node* newRoot = node->left ? node->left : node->right;
                delete node;
                return newRoot;
            }
            else {
                Node* cur = node->right;
                while (cur->left) {
                    cur = cur->left;
                }
                node->data = cur->data;
                node->right = deleteElementNode(node->right, cur->data);
            }
        }
        return node;
    }
};

int main() {
    string answer_from_user;
    string next;
    int n;
    float x;

    cout << "Do u want to create a BST??? Enter y/n\n";
    cin >> answer_from_user;
    link1:
        if (answer_from_user == "y") {
            cout << "The tree is created\n";
        }
        else if (answer_from_user == "n"){
            cout << "See you" << endl;
            return 0;
        }
        else{
            cout << "Enter y/n";
            goto link1;
        }
    BinTree bst;
    cout << "Do you want to do any operation. Enter y to countinue\n";
    cin >> answer_from_user;
    if (answer_from_user == "y") {
    link2:
        cout << "I can do these features:\n";
        cout << "1. Append els to the tree\n";
        cout << "2. Search els in the tree\n";
        cout << "3. Remove els from the tree\n";
        cout << "4. Check if the tree is breathly increase\n";
        cout << "5. Print the tree\n";
    link:
        cin >> answer_from_user;
        if (answer_from_user == "1") {
            cout << "Enter how many els you want to add to the tree ";
            cin >> n;
            vector <float> arr;
            cout << "Please, enter elements: ";
            for (int i = 0; i < n; ++i) {
                cin >> x;
                arr.push_back(x);
            }
            for (int i = 0; i < n; ++i) {
                bst.insert(arr[i]);
            }
                cout << "The elements are appended" << '\n';
            }
        else if (answer_from_user == "2") {
            int ell;
            cout << "Enter element u wanna check: ";
            cin >> ell;
            bool temp = bst.search(ell);
            if (temp == false) cout << "Your element is NOT in the tree\n";
            else cout << "Oh, you are right!\n";
        }

        else if (answer_from_user == "3") {
            int ell;
            cout << "Enter element u want to remove: ";
            cin >> ell;
            if (bst.deleteElement(ell) == true) {
                bst.deleteElement(ell);
                cout << "Element was removed\n";
            }
            else {
                cout << "The tree is empty\n";
            }
            
            }

        else if (answer_from_user == "4") {
            cout << "Checking if the tree is breathly increase: \n";
            bst.isBreadthIncrease();
        }

        else if (answer_from_user == "5") {
            bst.printTree();
        }
    link3:
        cout << "U want to continue? Enter y/n\n";
        cin >> next;
        if (next == "y") {
            goto link2;
        }
        else if (next == "n"){
            cout << "Have a nice day!" << endl;
        }
        else {
            cout << "Please, press y or n" << endl;
            goto link3;
        }
    }
    return 0;
}
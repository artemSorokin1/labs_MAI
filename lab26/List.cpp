#include <iostream>
#include <cmath>



using namespace std;


template <typename T>
class List {

private:

    template <typename N>
    class Node {
    public:
        Node *next;
        T data;

        Node(T data = T(), Node* next = nullptr) {
            this->data = data;
            this->next = next;
        }

    };

    int Size;
    Node<T>* head;

public:

    List(); //+

    ~List(); //+

    T & operator[] (int i); //+

    void list_create(T data); //+

    bool list_is_empty(); //+

    int list_size();  //+

    void list_insert(int index, T data); //+

    void list_erase(int index); //+

    void list_print(); //+

    void list_push_front(T data); //+

    void list_push_back(T data); //+

    void list_pop_front(); //+

    void list_pop_back(); //+

    void procedure(List & ls1, List & ls2);
};


template <typename T>
List<T>::List() {
    Size = 0;
    head = nullptr;
}

template <typename T>
List<T>::~List() {
    if (head != nullptr) {
        while (head != nullptr) {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }
    }
}


template <typename T>
void List<T>::list_create(T data) {
    if (head == nullptr) {
        head = new Node<T>(data);
    } else return;
}


template <typename T>
bool List<T>::list_is_empty() {
    return head == nullptr;
}


template <typename T>
int List<T>::list_size() {
    return Size;
}


template <typename T>
void List<T>::list_insert(int index, T data) {
    if (index == 0) {
        list_push_front(data);
    } else {

        Node<T> *prev = this->head;

        for (int i = 0; i < index - 1; ++i) {
            prev = prev->next;

        }

        Node<T> *newNode = new Node<T>(data, prev->next);
        prev->next = newNode;

        Size++;
    }

}


template <typename T>
void List<T>::list_erase(int index) {
    if (index == 0) {
        list_pop_front();
    } else {

        Node<T> *prev = head;

        for (int i = 0; i < index - 1; ++i) {
            prev = prev->next;
        }

        Node<T> *del = head;

        for (int i = 0; i < index; ++i) {
            del = del->next;
        }

        prev->next = del->next;
        delete del;
        Size--;
    }
}


template <typename T>
void List<T>::list_print() {
    Node<T>* cur = head;

    if (cur == nullptr) return;
    else {
        while (cur != nullptr) {
            cout << cur->data << ' ';
            cur = cur->next;
        }
    }
    cout << endl;

}


template <typename T>
void List<T>::list_push_front(T data) {
    head = new Node<T>(data, head);
    Size++;
}


template <typename T>
void List<T>::list_push_back(T data) {
    if (head == nullptr) {
        head = new Node<T>(data);
    }
    else {
        Node<T> *curr = this->head;

        while (curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = new Node<T>(data);
    }

    Size++;
}


template <typename T>
void List<T>::list_pop_front() {
    if (head != nullptr) {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
    } else return;

    Size--;
}


template <typename T>
void List<T>::list_pop_back() {
    list_erase(Size - 1);
}


template <typename T>
T & List<T>::operator[] (int index) {
    int cnt = 0;
    Node<T> *cur = this->head;
    while (cur != nullptr) {

        if (cnt == index) {
            return cur->data;
        } else {
            cur = cur->next;
            cnt++;
        }
    }


}


template <typename T>
void List<T>::procedure(List & ls1, List & ls2) {
    int max_size = max(ls1.Size, ls2.Size);
    int min_size = min(ls1.Size, ls2.Size);
    List res_ls;
    res_ls.Size = ls1.Size + ls2.Size;

    Node<T> *cur = res_ls.head;
    Node<T> *cur1 = ls1.head;
    Node<T> *cur2 = ls2.head;
    while (cur1->next != nullptr || cur2->next != nullptr) {

    }


}








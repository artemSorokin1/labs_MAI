#include <iostream>
#include <regex>


using namespace std;


typedef struct noode {
    int value;
    struct noode* left;
    struct noode* right;
    
} noode;

//----------------------------------------------------------------------------------------
//создание элемента дерева

noode* create_tree_elem(int el) {
    noode* root = new noode;
    root->value = el;
    root->left = NULL;
    root->right = NULL;
    return root;
}

//----------------------------------------------------------------------------------------
//поиск элемента в дереве

noode* serch_elem_in_tree(noode* root, int elem) {
    if (root->value == elem) {
        return root;
    }
    else if (root->value > elem && root->left != NULL) {
        return serch_elem_in_tree(root->left, elem);
    }
    else if (root->value < elem && root->right != NULL){
        return serch_elem_in_tree(root->right, elem);
    }
        return NULL;
}

//----------------------------------------------------------------------------------------
//вствка элемента в дерево

void insert_tree(noode* & root, noode* & elem) {
    if (root->value > elem->value) {
        if (root->left == NULL) {
            root->left = elem;
        } else {
            insert_tree(root->left, elem);
        }
    } else {
        if (root->right == NULL) {
            root->right = elem;
        } else {
            insert_tree(root->right, elem);
        }
    }
}


//----------------------------------------------------------------------------------------
//удаление элемента из дерева

noode* deleteElementNode(noode* node, int del) {
    int key = del;
    
    if (node == nullptr) {
        return node;
    }
    else if (node->value > key) {
        node->left = deleteElementNode(node->left, key);
    }
    else if (node->value < key) {
        node->right = deleteElementNode(node->right, key);
    }
    else {
        if (!node->left && !node->right) {
            delete node;
            return NULL;
        }
        else if (!node->left || !node->right) {
            noode* newRoot = node->left ? node->left : node->right;
            delete node;
            return newRoot;
        }
        else {
            noode* cur = node->right;
            while (cur->left) {
                cur = cur->left;
            }
            node->value = cur->value;
            node->right = deleteElementNode(node->right, cur->value);
        }
    }
    return node;
}

//----------------------------------------------------------------------------------------
//подсчет кол-ва вершин дерева

int cnt = 1;
int quantity_elem_in_tree(noode* root) {
    if (root->left != NULL) {
        quantity_elem_in_tree(root->left);
        cnt++;
    }
    if (root->right != NULL) {
        quantity_elem_in_tree(root->right);
        cnt++;
    }
    
    return cnt;
}


//----------------------------------------------------------------------------------------
//вывод дерева в терминал

int tabs = 0;
void print_tree(noode*  root) {
    cout << endl;
    if (!root) return;
    tabs += 6;
    
    print_tree(root->right);
    
    for (int i = 0; i < tabs; ++i) {
        cout << ' ';
    }
    cout << root->value << endl << endl;
    
    print_tree(root->left);
    
    tabs -= 6;
    
    return;
}

//----------------------------------------------------------------------------------------
//очистка памяти, занимаемой деревом

void free_tree(noode* & root) {
    if (!root) {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    delete root;
    return;
}
    


//----------------------------------------------------------------------------------------


int main() {
    string answer_from_user;
    string next;
    int n;
    noode* root = NULL;
    cout << "Вы хотите создть бинарное дерево поиска???\n";
    cin >> answer_from_user;
    if (answer_from_user == "да") {
        cout << "Дерево создано!!!\n";
    } else {
        cout << "До скорых встреч!!!" << endl;
        root = nullptr;
        return 0;
    }
    
    cout << "Хотите выполнить какую-либо операцию над деревом???\n";
    cin >> answer_from_user;
    if (answer_from_user == "да") {
        link2:
        cout << "Я умею выполнять следующие операции:\n";
        cout << "1. Добавлять элемент/элементы в дерево\n";
        cout << "2. Искать элемент в дереве\n";
        cout << "3. Удалять элемент из дерева\n";
        cout << "4. Считать количество вершин в дереве\n";
        cout << "5. Выводить дерево в терминал\n";
        //с помощью регулярок 1,2,3,4,5 или один и т.д.
        link:
        cin >> answer_from_user;
        if (answer_from_user == "1") {
            cout << "Введите количество элементов, которые хотите добавить: ";
            cin >> n;
            int a[n];
            cout << "Введите элементы: ";
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
            }
            if (root == NULL) {
                root = create_tree_elem(a[0]);
                for (int i = 1; i < n; ++i) {
                    noode* temp = create_tree_elem(a[i]);
                    insert_tree(root, temp);
                }
                cout << "Элементы добавлены" << '\n';
            } else {
                for (int i = 0; i < n; ++i) {
                    noode* temp = create_tree_elem(a[i]);
                    insert_tree(root, temp);
                }
                cout << "Элементы добавлены" << '\n';
            }
            
            cout << "Хотите продолжить?\n";
            cin >> next;
            if (next == "да") {
                goto link2;
            } else {
                cout << "Хорошего дня!" << endl;
            }
        }
        
        else if (answer_from_user == "2") {
            int ell;
            cout << "Введите элемент, который хотите проверить: ";
            cin >> ell;
            noode* temp = serch_elem_in_tree(root, ell);
            if (temp == NULL) {
                cout << "Такого элемента не существует(\n";
            }
            else cout << "Такой элемент существует)\n";
            
            cout << "Хотите продолжить?\n";
            cin >> next;
            if (next == "да") {
                goto link2;
            } else {
                cout << "Хорошего дня!" << endl;
            }
        }
        
        else if (answer_from_user == "3") {
            int ell;
            cout << "Введите элемент, который хотите удалить: ";
            cin >> ell;
            if (ell == root->value) {
                cout << "Зачем ты удаляешь корневой элемент" << '\n';
                cout << "Наказан, пока" << '\n';
                free_tree(root);
                return 0;
            } else {
                deleteElementNode(root, ell);
                cout << "Элемент удален\n";
                
                cout << "Хотите продолжить?\n";
                cin >> next;
                if (next == "да") {
                    goto link2;
                } else {
                    cout << "Хорошего дня!" << endl;
                }
            }
        }
        
        else if (answer_from_user == "4") {
            cout << "Количество вершин в дереве: " << quantity_elem_in_tree(root) << '\n';
            cnt = 1;
            
            cout << "Хотите продолжить?\n";
            cin >> next;
            if (next == "да") {
                goto link2;
            } else {
                cout << "Хорошего дня!" << endl;
            }
        }
        
        else if (answer_from_user == "5") {
            print_tree(root);
            tabs = 0;
            
            cout << "Хотите продолжить?\n";
            cin >> next;
            if (next == "да") {
                goto link2;
            } else {
                cout << "Хорошего дня!" << endl;
            }
        }
        
        else {
            cout << "Я Вас не понял, можете повторить свой ответ" << '\n';
            goto link;
        }
        
    } else {
        cout << "Рад был помочь!!!" << '\n';
    }
    
    
    free_tree(root);
    
    return 0;
    
}



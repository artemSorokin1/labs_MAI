#include "List.cpp"
#include <iostream>


using namespace std;


int main() {

    List<double> ls1;

    List<double> ls2;

    List<double> ls;

    ls1.list_push_front(10);
    ls1.list_push_front(20);
    ls1.list_push_front(30);


    ls2.list_push_front(1);
    ls2.list_push_front(21);
    ls2.list_push_front(3);

    ls.procedure(ls1, ls2, ls);

    ls.list_print();

    return 0;
}

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node * retorna_impares(Node *i, Node *a = NULL)
{
    if (i == NULL) {
        return a;
    }
    if (i->data % 2 == 1)
    {
        if(a == NULL)
        {
            a = new Node;
            a->data = i->data;
            a->next = NULL;
        }
        else
        {
            Node *aux = new Node;
            aux->data = i->data;
            aux->next = a;
            a = aux;
        }
    }
    return retorna_impares(i->next, a);
}

int main()
{
    Node *i = new Node;
    i->data = 1;
    i->next = new Node;
    i->next->data = 2;
    i->next->next = new Node;
    i->next->next->data = 3;
    i->next->next->next = new Node;
    i->next->next->next->data = 4;
    i->next->next->next->next = new Node;
    i->next->next->next->next->data = 5;
    i->next->next->next->next->next = new Node;
    i->next->next->next->next->next->data = 7;
    i->next->next->next->next->next->next = NULL;






    Node *a = retorna_impares(i);
    while (a != NULL) {
        cout << a->data << endl;
        a = a->next;
    }
    return 0;
}
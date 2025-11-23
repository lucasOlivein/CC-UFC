#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *intercala(Node *i1, Node *i2)
{
    Node *o = NULL; Node *h = NULL;
    while(i1 != NULL && i2 != NULL)
    {
        if(i1->data >= i2->data)
        {
            if(o == NULL)
            {
                o = i2;
                i2 = i2->next;
                o->next = NULL;
                h = o;
            }else
            {
                o->next = i2;
                i2 = i2->next;
                o = o->next;
                o->next = NULL;
            }
        }else{
            if(o == NULL)
            {
                o = i1;
                i1 = i1->next;
                o->next = NULL;
                h = o;
            }else
            {
                o->next = i1;
                i1 = i1->next;
                o = o->next;
                o->next = NULL;
            }
        }
    }
    while(i1 != NULL)
    {
    
        
            o->next = i1;
            i1 = i1->next;
            o = o->next;
            o->next = NULL;
        
    }

    while(i2 != NULL)
    {

        
            o->next = i2;
            i2 = i2->next;
            o = o->next;
            o->next = NULL;
        
    }
    return h;
}

int main()
{
    Node *i1 = new Node;
    i1->data = 1;
    i1->next = new Node;
    i1->next->data = 3;
    i1->next->next = new Node;
    i1->next->next->data = 5;
    i1->next->next->next = new Node;
    i1->next->next->next->data = 7;
    i1->next->next->next->next = new Node;
    i1->next->next->next->next->data = 9;
    i1->next->next->next->next->next = NULL;

    Node *i2 = new Node;
    i2->data = 2;
    i2->next = new Node;
    i2->next->data = 4;
    i2->next->next = new Node;
    i2->next->next->data = 8;
    i2->next->next->next = NULL;
    

    Node *o = intercala(i1, i2);
    while (o != NULL) {
        cout << o->data << endl;
        o = o->next;
    }
    return 0;
}


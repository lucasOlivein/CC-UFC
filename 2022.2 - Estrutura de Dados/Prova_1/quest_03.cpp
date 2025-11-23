#include <iostream>
using namespace std;

bool eh_primo(int);
void inserir_primos(int*, int);
void inserir_compostos(int*, int, int);

void ord(int *l, int size)
{
    for(int i=0; i<size; i++)
    {
        if(eh_primo(l[i]))
        {   
            inserir_primos(l, i);
        }else{
            inserir_compostos(l, i, size-1);
        }
    }
}

void inserir_primos(int *l, int i)
{
    int aux = 0;
    while(aux < i){
        if(l[aux] > l[i])
            break;
        aux++;
    }
    
    swap(l[aux], l[i]);
}

void inserir_compostos(int *l, int i, int size)
{
    while(size > i)
    {
        if(l[size] > l[i])
            break;
        size--;
    }
   
    swap(l[size], l[i]);
}

bool eh_primo(int n)
{
    if(n == 1)
        return false;
    for(int i=2; i<n; i++)
    {
        if(n%i == 0)
            return false;
    }
    return true;
}

int main()
{
    int l[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ord(l, 10);
    for(int i=0; i<10; i++)
    {
        cout << l[i] << endl;
    }
    return 0;
}

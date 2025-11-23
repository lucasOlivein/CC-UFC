#include <iostream>
using namespace std;


void intercala(int *V, int inicio,int meio, int fim)
{
    int *aux = new int[fim - inicio + 1];
    int i = 0;

    int i1 = inicio;
    int i2 = meio;

    while(i1 < meio && i2 < fim)
    {
        if(V[i1] < V[i2])
            aux[i++] = V[i1++];
        else
            aux[i++] = V[i2++];
    }

    while(i1 < meio)
        aux[i++] = V[i1++];

    while(i2 < fim)
        aux[i++] = V[i2++];

    i = 0;

    while(inicio < fim)
        V[inicio++] = aux[i++];
}

void merge(int *V, int inicio, int fim)
{
    if(fim - inicio <= 1)
        return;

    int meio = (fim + inicio)/2;

    merge(V, inicio, meio);
    merge(V, meio, fim);

    intercala(V, inicio, meio, fim);
}


int main()
{
    int V[] = {1,2,5,2,345,6,72,3,4,20,2,4,5,6,1,2,2,3,4,6,7,2,3,5};

    int len = sizeof(V)/sizeof(int);

    merge(V, 0, len);

    cout << "[ ";
    for(int i=0 ; i<len; i++)
        cout << V[i] << ", ";
    cout <<"] ";
}
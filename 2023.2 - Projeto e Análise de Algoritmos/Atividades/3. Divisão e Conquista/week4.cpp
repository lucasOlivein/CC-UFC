#include <iostream>
using namespace std;


void intercala(int *V, int inicio, int m1, int m2, int fim)
{
    int * aux = new int[fim-inicio + 1];
    
    int i = 0;

    int i1 = inicio;
    int i2 = m1;
    int i3 = m2;

    while(i1 < m1 && i2 < m2 && i3 < fim)
    {
        if(V[i1] <= V[i2] && V[i1] <= V[i3])
            aux[i++] = V[i1++];
        else if(V[i2] <= V[i1] && V[i2] <= V[i3])
            aux[i++] = V[i2++];
        else if(V[i3] <= V[i1] && V[i3] <= V[i2])
            aux[i++] = V[i3++];
    }
    while(i1 < m1 && i2 < m2)
    {
        if(V[i1] <= V[i2])
            aux[i++] = V[i1++];
        else if(V[i2] <= V[i1])
            aux[i++] = V[i2++];
    }

    while(i1 < m1 && i3 < fim)
    {
        if(V[i1] <= V[i3])
            aux[i++] = V[i1++];
        else if(V[i3] <= V[i1])
            aux[i++] = V[i3++];
    }

    while(i2 < m2 && i3 < fim)
    {
        if(V[i2] <= V[i3])
            aux[i++] = V[i2++];
        else if(V[i3] <= V[i2])
            aux[i++] = V[i3++];
    }
    
    while(i1 < m1)
    {
        aux[i++] = V[i1++];
    }
    
    while(i2 < m2)
    {
        aux[i++] = V[i2++];
    }
    while(i3 < fim)
    {
        aux[i++] = V[i3++];
    }

    for(int j = inicio, i = 0; j<fim; j++, i++)
        V[j] = aux[i];
}




void merge(int *V, int inicio, int fim)
{
    if(fim <= inicio)
        return;
    if(fim - inicio <= 3)
    {
        intercala(V, inicio, inicio + 1, fim-1, fim);
        return;
    }

    int m1 = (fim - inicio)/3 + inicio;
    int m2 = 2 * m1 - inicio;


    merge(V, inicio, m1);
    merge(V, m1, m2);
    merge(V, m2, fim);

    intercala(V, inicio, m1, m2, fim);
}


int main(){
    int V[] = {15,13,5,4,1,2,3,4,5,6,7,8,2};
    int len = sizeof(V)/sizeof(int);

    // int V1[] = {7,3,9,14,1,30};
    merge(V, 0, len);
    // intercala(V, 0, 1, 1, 2);
    

    cout << "[ ";
    for(int i=0; i<len; i++)
     cout << V[i] << ", ";
        cout << "]";
}
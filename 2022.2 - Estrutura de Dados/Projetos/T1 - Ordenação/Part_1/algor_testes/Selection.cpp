#include <iostream>
#include <cmath>
using namespace std;

class Selection
{
private:
    int *list;
    int lenght;
    int inicio = 0;

public:
    Selection(int *list_, int lenght_){
        list = list_;
        lenght = lenght_;
    }
    int select(int i)
    {
        for (int j = i + 1; j < lenght; j++)
            if (list[j] < list[i])
                i = j;
        return i;
    }
    void interativo()
    {
        for (int i = 0; i < lenght - 1; i++)
            swap(list[i], list[select(i)]);
    }
    void recursivo()
    {
        if (inicio >= lenght - 1)
            return;
        swap(list[inicio++], list[select(inicio)]);
        recursivo();
    }

    void interativo_op2()
    {

        int indexMin;
        for (int i = 0; i < lenght - 1; i++)
        {
            int aux = select(i);
            if (list[aux] % 2 == 0)
            {
                swap(list[--lenght], list[aux]);
                i--;
            }
            else
                swap(list[i], list[aux]);
        }
    }

    void recursivo_op2() /// DIficuldades: nao conseguir alterar o valor de lenght para as prox interacao recursiva
    {                                                              // assim, impossibilitar usar a funcao select(), pois sempre vai percorrer o vetor ate o fim.

        if (inicio >= lenght - 1)
            return;

        int aux = inicio;
        for (int i = inicio + 1; i < lenght; i++)
            if (list[aux] > list[i])
                aux = i;

        if (list[aux] % 2 == 0)
            swap(list[aux], list[--lenght]);
        else
            swap(list[inicio++], list[aux]);

        recursivo_op2();
    }
};

int main()
{
    unsigned long int tam = 150;
    int *list = new int[tam];

    for (unsigned long int i = 0; i < tam; i++)
        list[i] = rand() % 10;

    Selection s(list, tam);
    for (int i = 0; i < 150; i++)
        cout << list[i] << " ";
    cout << '\n';

    s.recursivo();

    for (int i = 0; i < 150; i++)
        cout << list[i] << " ";
    cout << '\n';

    delete list;
}
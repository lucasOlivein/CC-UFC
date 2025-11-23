#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

class Insetion
{
private:
    int *list;
    int lenght;

public:
    Insetion(int *list_, int lenght_)
    {
        list = list_;
        lenght = lenght_;
    }

    void inserir(int inicio)
    {
        int key = list[inicio];
        int i = inicio - 1;

        while (i >= 0 && list[i] > key)
        {
            list[i + 1] = list[i];
            i--;
        }
        list[i + 1] = key;
    }
    void inserir_par(int inicio)
    {
        int key = list[inicio];
        int i = inicio - 1;
        while (i >= 0 && list[i] % 2 == 0 && list[i] < key)
        {
            list[i + 1] = list[i];
            i--;
        }
        list[i + 1] = key;
    }

    void interativo(int inicio)
    {
        for (int j = inicio + 1; j < lenght; j++)
            inserir(j);
    }

    void interativo_op2(int inicio) // DESCRICAO - 2 etapas
    {
        int j = 1;
        while (j < lenght)
        {
            if (list[j] % 2 == 1 && list[j - 1] % 2 == 0)
            {
                swap(list[j], list[j - 1]);
                j = j - 1;
            }
            else if (list[j] % 2 == 1)
                inserir(j++);
            else
                inserir_par(j++);
        }
    }

    void recursivo(int inicio)
    {
        if (inicio >= lenght)
            return;

        inserir(++inicio);
        recursivo(inicio);
    }
    void recursivo_op2(int inicio)
    {
        if (inicio + 1 >= lenght)
            return;

        if (list[inicio + 1] % 2 == 1 && list[inicio] % 2 == 0)
        {
            swap(list[inicio + 1], list[inicio]);
            recursivo_op2(--inicio);
        }

        if (list[inicio + 1] % 2 == 1)
            inserir(inicio + 1);
        else
            inserir_par(inicio + 1);

        recursivo_op2(++inicio);
    }
};

int main()
{
    unsigned long int tam = pow(2,18); // valor maximo
    int *list = new int[tam];

    for (unsigned long int i = 0; i < tam; i++)
        list[i] = rand() % 9;
    Insetion i(list, tam);
    for (int i = 0; i < 100; i++)
        cout << list[i] << " ";
    cout << '\n';

    clock_t begin = clock();
    i.interativo(0);
    clock_t end = clock();

    for (int i = 0; i <100; i++)
        cout << list[i] << " ";
    cout << '\n';

     cout << double(end - begin) / CLOCKS_PER_SEC << " segundos" << endl;

    delete list;
}
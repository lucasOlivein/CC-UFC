#include <iostream>
#include <cmath>
using namespace std;

class Bubble{

    private:
        int *list;
        int lenght;
    public:
    Bubble(int *list_, int lenght_){
        list= list_;
        lenght = lenght_;
    }
    void interativo()
    {
        bool ordenado = false;

        while (!ordenado)
        {
            ordenado = true;
            for (int i = 0; i < lenght - 1; i++)
                if (list[i] > list[i + 1])
                {
                    swap(list[i], list[i + 1]);
                    ordenado = false;
                }
            lenght--;
        }
    }
    void interativo_op2()
    {
        bool ordenado = false;

        while (!ordenado)
        {
            ordenado = true;
            for (int i = 0; i < lenght - 1; i++)
                if (list[i] % 2 == 0 && list[i + 1] % 2 == 1)
                    {
                        swap(list[i], list[i + 1]);
                        ordenado = false;
                    }
                else if (list[i] > list[i + 1])
                {
                    if (list[i] % 2 == 1 && list[i + 1] % 2 == 1)
                    {
                        swap(list[i], list[i + 1]);
                        ordenado = false;
                    }
                }
                else
                {
                    if (list[i] % 2 == 0 && list[i + 1] % 2 == 0)
                    {
                        swap(list[i], list[i + 1]);
                        ordenado = false;
                    }
                    
                }
            lenght--;
        }
    }

    void recursivo()
    {
        bool ordenado = true;

        for (int i = 0; i < lenght - 1; i++)
            if (list[i] > list[i + 1])
            {
                swap(list[i], list[i + 1]);
                ordenado = false;
            }

        if (ordenado)
            return;

        --lenght;
        recursivo();
    }
    void recursivo_op2()
    {
        bool ordenado = true;

        for (int i = 0; i < lenght - 1; i++)
            if (list[i] % 2 == 0 && list[i + 1] % 2 == 1)
            {
                swap(list[i], list[i + 1]);
                ordenado = false;
            }
            else if (list[i] > list[i + 1])
            {
                if (list[i] % 2 == 1 && list[i+1] % 2 == 1)
                {
                    swap(list[i], list[i + 1]);
                    ordenado = false;
                }
            }
            else
            {
                if (list[i] % 2 == 0 && list[i + 1] % 2 == 0)
                {
                    swap(list[i], list[i + 1]);
                    ordenado = false;
                }
            }
        
        if (ordenado)
            return;

        --lenght;
        recursivo_op2();
    }
};
int main()
{
    int tam = pow(2,15);
    int *list[4];

    for (int j = 0; j < 4; j++)
    {
        list[j] = new int[tam];
        for (int i = 0; i < tam; i++)
            list[j][i] = rand() % 10;
    }
    Bubble *s[4];
    s[0] = new Bubble(list[0], tam);
    s[1] = new Bubble(list[1], tam);
    s[2] = new Bubble(list[2], tam);
    s[3] = new Bubble(list[3], tam);

    for (int j = 0; j < 4; j++){
        for (int i = 0; i < tam; i++)
            cout << list[j][i] << " ";
    cout << '\n';

    }
    
    s[0]->recursivo_op2();
    s[1]->recursivo();
    s[2]->interativo_op2();
    s[3]->interativo();

    for (int j = 0; j < 4; j++){
        for (int i = 0; i < tam; i++)
            cout << list[j][i] << " ";
    cout << '\n';

    }

    for(int i = 0; i<4; i++)
    delete list[i];
}
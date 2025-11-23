#include <iostream>
#include <ctime>
#include <math.h>
using namespace std;

class Merge
{
private:
    int *list;
    int lenght;

public:
    Merge(int list[], int lenght)
    {
        this->list = list;
        this->lenght = lenght - 1;
    }

    int partition_impar_par()
    {
        int index = 0;
        int inicio = 0;

        while (inicio < lenght)
        {
            if (list[inicio] % 2 == 1)
                swap(list[inicio], list[index++]);

            inicio++;
        }
        return index;
    }

    void _merge(int inicio, int meio, int fim)
    {
        int *vet_aux = new int[(fim - inicio) + 1];
        int right = inicio;
        int left = meio + 1;
        int k = 0;

        while (right <= meio && left <= fim)
            if (list[right] > list[left])
            {
                vet_aux[k++] = list[right++];
            }
            else if (list[right] < list[left])
            {
                vet_aux[k++] = list[left++];
            }
            else
            {
                vet_aux[k++] = list[right++];
                vet_aux[k++] = list[left++];
            }

        while (right <= meio)
            vet_aux[k++] = list[right++];

        while (left < fim)
            vet_aux[k++] = list[left++];

        for (int i = 0, j = inicio; i < k; i++)
        {
            list[j++] = vet_aux[i];
        }
        delete vet_aux;
    }
    void merge(int inicio, int meio, int fim)
    {
        int *vet_aux = new int[(fim - inicio) + 1];
        int right = inicio;
        int left = meio + 1;
        int k = 0;

        while (right <= meio && left <= fim)
            if (list[right] > list[left])
            {
                vet_aux[k++] = list[left++];
            }
            else if (list[right] < list[left])
            {
                vet_aux[k++] = list[right++];
            }
            else
            {
                vet_aux[k++] = list[right++];
                vet_aux[k++] = list[left++];
            }

        while (right <= meio)
            vet_aux[k++] = list[right++];

        while (left < fim)
            vet_aux[k++] = list[left++];

        for (int i = 0, j = inicio; i < k; i++)
        {
            list[j++] = vet_aux[i];
        }
        delete vet_aux;
    }
    void interativo()
    {
        interativo(0, lenght);
    }
    void interativo(int start, int lenght)
    {
        int inicio;
        int fim;
        int bloco = 1;

        while (bloco <= lenght)
        {
            inicio = start;

            while (inicio + bloco <= lenght)
            {
                fim = inicio + 2 * bloco - 1;
                if (fim > lenght)
                    fim = lenght;
                merge(inicio, inicio + bloco - 1, fim);
                inicio = inicio + 2 * bloco;
            }
            bloco = 2 * bloco;
        }
    }

    void _interativo(int start, int lenght)
    {
        int inicio;
        int fim;
        int bloco = 1;

        while (bloco <= lenght)
        {
            inicio = start;

            while (inicio + bloco <= lenght)
            {
                fim = inicio + 2 * bloco - 1;
                if (fim > lenght)
                    fim = lenght;
                _merge(inicio, inicio + bloco - 1, fim);
                inicio = inicio + 2 * bloco;
            }
            bloco = 2 * bloco;
        }
    }

    void interativo_op2()
    {
        int p = partition_impar_par();
        interativo(0, p - 1);
        _interativo(p, lenght);
    }

    void recursivo(int inicio, int fim)
    {
        if (fim <= inicio)
            return;

        int meio = (inicio + fim) / 2; // Dividir
        // Conquistar
        recursivo(inicio, meio);
        recursivo(meio + 1, fim);
        // Combinar
        merge(inicio, meio, fim);
    }
    void recursivo()
    {
        recursivo(0, lenght);
    }

    void _recursivo(int inicio, int fim)
    {
        if (fim <= inicio)
            return;

        int meio = (inicio + fim) / 2; // Dividir
        // Conquistar
        _recursivo(inicio, meio);
        _recursivo(meio + 1, fim);
        // Combinar
        _merge(inicio, meio, fim);
    }
    void recursivo_op2()
    {
        int p = partition_impar_par();
        recursivo(0, p - 1);
        _recursivo(p, lenght);
    }
};

int main()
{
    int tam = 100;
    int *list = new int[tam];

         
        for (int i = 0; i < tam; i++)
            list[i] = rand() % 10;

            
    Merge *s = new Merge(list, tam);
   
  

    cout << "Entrada -->  \n";
        for (int i = 0; i < tam; i++)
            cout << list[i] << " ";
    cout << "\n\n";

    
    s->_interativo(0,tam-1); // chamar para lenght - 1;

   cout << "Saida -->  \n";
        for (int i = 0; i < tam; i++)
            cout << list[i] << " ";
    cout << '\n';

    

    
    delete list;
}
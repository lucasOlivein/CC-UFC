#include <iostream>
#include <vector>

// Algoritmo da questão 1
// verifica se um vetor está ordenado

int ord()
{
    int V[] = {1, 3, 3, 4, 5, 6, 0, 8, 9, 10};

    int block = 1;
    int len = 10;
    int comp = 0;
    while (block < len)
    {
        int start = 0;

        while (block + start <= len)
        {
            int end = start + 2 * block - 1;
            if (end > len)
                end = len;

            int i = start;
            int k = start + block;

            while (i <= start + block - 1 && k <= end)
            {
                std::cout << V[i] << ">" << V[k] << "?\n";
                comp++;
                if (V[i] > V[k])
                {
                    std::cout << "O vetor nao esta ordenado";
                    return comp;
                }
                i++;
                k++;
            }
            start = start + 2 * block;
        }
        block = 2 * block;
    }

    std::cout << "O vetor esta ordenado";

    return comp;
}

// Versão Simplificada da questão 1:

bool Q1(int * V, int len){
    int i = 1;

    while(i++ < len)
        if(V[i-1] > V[i])
            return false;
    return true;
}

// Questão 2
//  Inserir um elemento em um vetor ordenado contendo N elementos, de tal forma que após a inser
//  inserção ele continue ordenado.

int insertion(int key)
{
    std::vector<int> V = {1, 2, 3, 4, 5};

    int i = 0;
    while (V[i] <= key)
    {
        i++;
    }
    while (i < V.size())
    {
        int aux = V[i];
        V[i] = key;
        key = aux;
        i++;
    }
    std::cout << i << '\n';
    V.push_back(key);

    for (int i = 0; i < V.size(); i++)
        std::cout << V[i] << ' ';
}

// Questão 3
//  Dado um vetor ordenado com n elementos inteiros positivos e um outro numero inteiro x,
//  encontrar dois elementos do vetor cuja a somaé igual a X.
bool soma()
{
    std::vector<int> V = {3, 4, 5, 6, 7, 8, 9, 10};
    int x = 19;

    int i = V.size() - 1;

    while (V[i] > x && i > 0)
    {
        i--;
    }

    int j = 0;

    while (j < i)
    {
        if (V[j] + V[i] < x)
            j++;
        else if (V[j] + V[i] > x)
            i--;
        else
        {
            std::cout << V[j] << " + " << V[i] << " = " << x;
            return true;
        }
    }

    std::cout << "Nenhum valor encontrado";
    return false;
}

// Questão 4
// Versão recursiva da questão 3
bool soma_rec(int *V, int len, int x, int i = 0)
{
    if (len <= i)
    {
        std::cout << "Valores nao encontrado";
        return false;
    }

    if (V[len] > x || V[i] + V[len] > x)
        return soma_rec(V, --len, x, i);

    if (V[i] + V[len] < x)
        return soma_rec(V, len, x, ++i);

    std::cout << V[i] << " + " << V[len] << " = " << x;
    return true;
}

int main()
{

    // std::cout << "\nTotal de comparacoes:: " <<  ord();
    // soma();
    int V[] = {1, 4, 8, 6, 7, 8, 9, 10};
    // soma_rec(V, 8, 10);
    // insertion(10);

    if( Q1(V, sizeof(V)/sizeof(int)) )
        std::cout << "Ordenado";
    else
        std::cout << "Nao Ordenado";
}
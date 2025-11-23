#include<ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

int inter = 0;

void Quick(int list[], int lenght , int index = 0)
{

  for (int j = index; j < lenght-1; j++)
  { // PERCORRE A LISTA
    if (list[j] <= list[lenght-1])
    {
      swap(list[index], list[j]);
      index++;
    }

  } // TERMINA DE PERCORRER

  swap(list[index], list[lenght-1]); // POSICIONA O PIVO

  /* for (int i = 0; i < lenght ; i++)
    cout << list[i] << " ";
 */
  /* cout << "\n inter: " << inter << "\n";
  inter++; */

  // CHAMA A FUNCAO PARA A PARTE DO VETOR QUE NAO ESTA ORDENADO.
  if (lenght -1 > 1)
    Quick(list, lenght-1);
  if (index+1 < lenght-1)
    Quick(list, lenght , index + 1);
}

int main()
{
  int tam = 4000;
  int list[tam]; // = {3, 7, 2, 8, 5, 7, 5, 4, 2, 9, 25, 6, 7, 5, 4, 2, 1, 3};
  int lenght  = sizeof(list) / sizeof(int);

  for(int i = 0; i<tam; i++)
    list[i] = rand();


  clock_t begin = clock();
  Quick(list, lenght );
  clock_t end = clock();

  for (int i = 0; i < lenght ; i++)
    cout << list[i] << " ";

    cout << double(end - begin)/CLOCKS_PER_SEC << " segundos" << endl;
}
#include <iostream>
#include <ctime>
using namespace std;

int verifica(int v[], int n)
{ // n é o tamanho do vetor
  if (n > 1)
    for (int i = 1; i < n; i++)
      if (v[i - 1] > v[i])
        return 0;
  return 1;
}

int partition(int arr[], int start, int end)
{

  int pivot = arr[start];

  int count = 0;
  for (int i = start + 1; i <= end; i++)
  {
    if (arr[i] <= pivot)
      count++;
  }

  // Giving pivot element its correct position
  int pivotIndex = start + count;
  swap(arr[pivotIndex], arr[start]);

  // Sorting left and right parts of the pivot element
  int i = start, j = end;

  while (i < pivotIndex && j > pivotIndex)
  {

    while (arr[i] <= pivot)
    {
      i++;
    }

    while (arr[j] > pivot)
    {
      j--;
    }

    if (i < pivotIndex && j > pivotIndex)
    {
      swap(arr[i++], arr[j--]);
    }
  }

  return pivotIndex;
}
int inter = 0;
void quickSort(int arr[], int start, int end)
{

  // base case
  if (start >= end)
    return;

  // partitioning the array
  int p = partition(arr, start, end);

  // Sorting the left part
  quickSort(arr, start, p - 1);

  // Sorting the right part
  quickSort(arr, p + 1, end);
  inter++;
}

int main()
{
  unsigned long int tam = 10;
  int arr[tam];

  srand(2112);

  int n = sizeof(arr) / sizeof(int);

  for (int i = 0; i < tam; i++)
    arr[i] = rand();

  clock_t begin = clock();
  quickSort(arr, 0, n - 1);
  clock_t end = clock();

  for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
  }
  cout << "\nTotal de Interacoes: " << inter << '\n';
  if (verifica(arr, n))
  {
    printf("Esta em ordem crescente\n");
  }
  else
  {
    printf("Nao esta em ordem crescente\n");
  }
  cout << double(end - begin) / CLOCKS_PER_SEC << " segundos" << endl;

  return 0;
}
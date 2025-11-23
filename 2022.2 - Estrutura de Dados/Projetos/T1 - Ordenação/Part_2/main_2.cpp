#include <iostream>
#include <ctime>
#include <math.h>
using namespace std;
struct Index
{
  int inicio;
  int fim;
  int pivot;
};

Index i[512090];

struct Aluno
{
  int matricula;
  string nome;
};

int partition(Aluno *list, int inicio, int fim, int op)
{
  int index = inicio;

  int letra = 0;
  if (op == 1)
  {
    while (inicio < fim)
    {
      while (list[inicio].nome[letra] == list[fim].nome[letra])
        letra++;
      if (list[inicio].nome[letra] < list[fim].nome[letra])
        swap(list[inicio], list[index++]);

      inicio++;
      letra = 0;
    }
  }
  else
  {
    while (inicio < fim)
    {
      if (list[inicio].matricula < list[fim].matricula)
        swap(list[inicio], list[index++]);

      inicio++;
    }
  }

  swap(list[fim], list[index]);
  return index;
}

void ord_matricula(Aluno *list, int lenght, int op)
{
  int inter_atual = 0;
  int inter_final = 0;

  i[0].inicio = 0;
  i[0].fim = lenght - 1;

  while (inter_atual <= inter_final)
  {

    if (i[inter_atual].inicio < i[inter_atual].fim)
    {
      
      i[inter_atual].pivot = partition(list, i[inter_atual].inicio, i[inter_atual].fim, op);

      inter_final++;
      i[inter_final].inicio = i[inter_atual].inicio;
      i[inter_final].fim = i[inter_atual].pivot - 1;

      inter_final++;
      i[inter_final].inicio = i[inter_atual].pivot + 1;
      i[inter_final].fim = i[inter_atual].fim;
    }
    inter_atual++;
  }
}

int main()
{
  int lenght;
  int op;
  cout << "Digite o tamanho do vetor: ";
  cin >> lenght;
  cout << "\nOrdenar por: \n1 - Nome\n2 - Matricula\n";
  cin >> op;
  cout << "Selecionado -> ";

  if (op == 1)
    cout << "(Nome)\n";
  else
    cout << "(Matricula)";

  Aluno *list = new Aluno[lenght];

  list[0].nome = "lucas";
  list[0].matricula = 475597;
  list[1].nome = "luzas";
  list[3].nome = "zezinho";
  list[4].nome = "tiago";

  for (int i = 2; i < lenght; i++)
  {
    int temp = rand() % 5 + 6;
    char *a = new char[temp];

    for (int j = 0; j < temp - 1; j++)
    {
      a[j] = (rand() % 26) + 'a';
    }
    a[temp - 1] = '\0';
    list[i].nome = a;
  }
  for (int i = 1; i < lenght; i++)
    list[i].matricula = rand() % 100000 + 400000;

  cout << "\n\n";
  clock_t begin = clock();
  ord_matricula(list, lenght, op);
  clock_t end = clock();

  for (int i = 0; i < lenght; i++)
  {
    cout << "Nome: " << list[i].nome;
    cout << "\nMatricula: ";
    cout << list[i].matricula << " ";
    cout << "\n\n";
  }
}
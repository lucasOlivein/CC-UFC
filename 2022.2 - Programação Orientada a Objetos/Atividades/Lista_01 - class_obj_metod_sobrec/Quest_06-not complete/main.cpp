#include <iostream>
using namespace std;
#include "aluno_class.h"

int main(){
  Aluno n1("Lucas",  "1", "3");

  cout << n1.getNome() << '\n';
  cout << n1.getNumeroDeAlunos() << '\n';
}
#include <iostream>
using namespace std;
#include "empregado_class.h"


int main(){

  Empregado e = Empregado("Lucas", "André", 1200);
  Empregado d = Empregado("Joao", "Vic", 1450);
  cout << "Salario atual: " << e.getSalario() << "\nAnualmente: " << e.salarioAnual() << '\n';

  cout << "Promocao: " << 10 << "\n\nAtualilado: ";
  e.aumentarSalario(10);

  cout << e.getSalario() << "\n\n\n";

  cout << "Salario atual: " << d.getSalario() << "\nAnualmente: " << d.salarioAnual() << '\n';

  cout << "Promocao: " << 10 << "\n\nAtualilzado: ";
  d.aumentarSalario(10);

  cout << d.getSalario() << "\nAnualmente: " << d.salarioAnual() << '\n';

}
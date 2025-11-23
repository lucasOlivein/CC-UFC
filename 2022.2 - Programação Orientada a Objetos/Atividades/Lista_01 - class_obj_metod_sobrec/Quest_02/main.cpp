#include <iostream>
using namespace std;

#include "conta_class.h"

int main(){
  Conta c = Conta(10);

  c.credito(3);
  c.debito(9);
  cout << "Saldo: " << c.getSaldo() << '\n';
}
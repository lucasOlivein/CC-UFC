#include <iostream>
#include "notaFiscal_class.h"

using namespace std;


int main(){

  cout << "Hello World\n";
  NotaFiscal n[3] = { NotaFiscal("0", "prot_1", 5, 12.5), NotaFiscal("1", "prot_2", 1, 25), NotaFiscal("2", "Prot_3", 2, 50),
  };

  cout << "Numero de pecas: " << n[1].getNumeroPecas() << endl;
  cout << "O valor total eh: " << NotaFiscal::getTotalNota(n, 3) << endl;
}
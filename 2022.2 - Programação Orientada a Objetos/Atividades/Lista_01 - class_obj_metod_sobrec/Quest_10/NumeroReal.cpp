#include <iostream>
using namespace std;
#include "NumeroReal.h"


NumeroReal::NumeroReal(double numero){
  if(numero <= 0)
    cout << "Inferior a 0\nNumero invalido\n";
  else 
    setNumero(numero);
};

void NumeroReal::setNumero(double num_){
  numero = num_;
}

double NumeroReal::getNumero(){
  return numero;
}


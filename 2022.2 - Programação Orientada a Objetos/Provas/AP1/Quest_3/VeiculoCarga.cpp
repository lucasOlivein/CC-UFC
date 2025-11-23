#include <iostream>
#include "VeiculoCarga.h"
using namespace std;

float VeiculoCarga::pesoPotencia(){
    return (Veiculo::getPeso() + carga)/getPotencia();
} 

void VeiculoCarga::print(){
  cout << "Nome: " << getNome() << '\n';
  cout << "Peso: " << getPeso() << '\n';
  cout << "Potencia: " << getPotencia() << '\n';
  cout << "Carga:  " << getCarga() << '\n';

}
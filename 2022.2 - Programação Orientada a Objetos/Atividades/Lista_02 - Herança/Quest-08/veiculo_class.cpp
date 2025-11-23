#include <iostream>
using namespace std;

#include "veiculo_class.h"

Veiculo::Veiculo(string marca, string modelo, string cor, float potencia, int portas, int assentos){
  setMarca(marca);
  setModelo(modelo);
  setCor(cor);
  setPotencia(potencia);
  setPortas(portas);
  setAssentos(assentos);

};

Veiculo::Veiculo(){

};



void Veiculo::print(){
  cout << "Marca: " << getMarca() << '\n';
  cout << "Modelo: " << getModelo() << '\n';
  cout << "Cor: " << getCor() << '\n';
  cout << "Potencia: " << getPotencia() << "Cv\n";
  cout << "Portas: " << getPortas() << '\n';
  cout << "Assentos: " << getAssentos() << '\n';
}
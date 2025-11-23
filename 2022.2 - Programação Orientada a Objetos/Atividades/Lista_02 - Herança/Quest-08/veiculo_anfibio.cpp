#include<iostream>
using namespace std;

#include "veiculo_anfibio.h"
#include "veiculo_class.h"
VeiculoAnfibio::VeiculoAnfibio(string marca, string modelo, string cor, float potencia, int portas, int assentos, string tipo, string meio, bool proa, bool mastro, bool motor, string motor_tipo, int rodas, bool estepe, string num_placa, int ano, string classe, int max_velocidade, string popular) :VeiculoAquatico(marca, modelo, cor, potencia, portas, assentos,  tipo, meio, false, false, true, motor_tipo), VeiculoTerrestre( marca,  modelo, cor, potencia, portas, assentos, rodas,estepe,num_placa,ano ), Veiculo(marca, modelo, cor, potencia, portas, assentos){
  // Veiculo::setMarca(marca);
  // Veiculo::setModelo(modelo);
  // Veiculo::setCor(cor);
  // Veiculo::setPortas(portas);
  // Veiculo::setAssentos(assentos);
  // Veiculo::setPotencia(potencia);

  setClass(classe);
  setMaxVelocidade(max_velocidade);
  setPopular(popular);
};


void VeiculoAnfibio::print(){

  cout << "////////INERENTE AO VEICULO//////////////\n"; ////////////
  Veiculo::print();
  cout << "////////INERENTE AO VEICULO AQUATICO//////////////\n";
  VeiculoAquatico::print();
  cout << "////////INERENTE AO VEICULO TERRESTRE//////////////\n";
  VeiculoTerrestre::print();
cout << "////////INERENTE AO VEICULO ANFIBIO//////////////\n";
  cout<< "Classe: " << getClass() << '\n';
  cout << "Velocidade Maxima: " << getMaxVelocidade() << " Km/h\n";
  cout << "Esse carro eh popular? " << getPopular() << '\n';

  cout << "////////FIM//////////////\n";
}


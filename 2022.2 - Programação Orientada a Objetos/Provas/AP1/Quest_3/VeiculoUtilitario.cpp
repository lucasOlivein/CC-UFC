#include "VeiculoUtilitario.h"

void VeiculoUtilitario::print(){
  cout << "Nome: " << getNome() << '\n';
  cout << "Peso: " << getPeso() << '\n';
  cout << "Potencia: " << getPotencia() << '\n';
  cout << "Volume Interno: " << getVolumeInterno() << '\n';
  cout << "Carga:  " << getCarga() << '\n';
  cout << "Peso-Potencia: " << pesoPotencia() << '\n';  
}

float VeiculoUtilitario::pesoPotencia(){
  return VeiculoCarga::pesoPotencia();
}
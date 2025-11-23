#include <iostream>

#include "VeiculoPasseio.h"
using namespace std;

float VeiculoPasseio::pesoPotencia(){
  return Veiculo::getPeso()/Veiculo::getPotencia();
}
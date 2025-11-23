#include "VeiculoUtilitario.h"
#include <iostream>

using namespace std;

int main(){
  VeiculoPasseio *u = new VeiculoPasseio;
  VeiculoUtilitario *p = new VeiculoUtilitario;

  u->setNome("Toyota Corola");
  u->setPeso(300);
  u->setPotencia(130);

  u->print();

  p->setNome("Pick-upA");
  p->setPeso(400);
  p->setPotencia(180);
  p->setVolumeInterno(400);
  p->setCarga(400);

  p->print();
  


}
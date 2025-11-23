#include "Circulo.h"



float Circulo::getRaio() { return raio; }
void Circulo::setRaio(float raio_) { raio = raio_; }
float Circulo::calcuArea(){
  return (3.14*(raio*raio));
}

float Circulo::calcPerimetro(){
  return (6.28 * raio);
}
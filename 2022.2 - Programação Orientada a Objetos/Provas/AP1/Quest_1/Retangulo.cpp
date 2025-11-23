#include "Retangulo.h"


float Retangulo::calcArea(){
  return base*altura;
}
float Retangulo::calcPerimetro(){
  return 2*(base+altura);
}

float Retangulo::getBase() { return base; }
void Retangulo::setBase(float base_) { base = base_; }
float Retangulo::getAltura() { return altura; }
void Retangulo::setAltura(float altura_) { altura = altura_; }

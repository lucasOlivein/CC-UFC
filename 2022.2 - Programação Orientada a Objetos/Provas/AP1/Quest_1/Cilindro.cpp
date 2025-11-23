#include "Cilindro.h"


float Cilindro::Area(){
    float areaCir = 2*c.calcuArea();
    float areaRec = c.calcPerimetro()*r.getAltura();
    return areaCir + areaRec;
}

float Cilindro::Volume(){
  return (c.calcuArea() * r.getAltura());
}

Cilindro::Cilindro(float base, float altura, float raio){
  c.setRaio(raio);
  r.setAltura(altura);
  r.setBase(base);
}
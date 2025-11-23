#include "../bidimencional.h"

void Bidimencional::setArea(float area_){
  area = area_;
}

float Bidimencional::getArea(){
  return area;
}

Bidimencional::Bidimencional(){
  setTipo("Bidimencional");
}

void Bidimencional::imprimir(){
  
    cout << "Area: " << area << ";\n";
}
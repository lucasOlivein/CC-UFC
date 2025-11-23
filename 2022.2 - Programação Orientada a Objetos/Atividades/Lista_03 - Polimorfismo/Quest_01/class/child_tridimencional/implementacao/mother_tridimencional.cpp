#include "../tridimencional.h"

void Tridimencional::setArea(float area_){area = area_;}
float Tridimencional::getArea(){return area;}

void Tridimencional::setVolume(float volume_){volume= volume_;}
float Tridimencional::getVolume(){return volume;}

void Tridimencional::imprimir(){
  cout << "Area total: " << getArea() << "\nO volume: " << getVolume() <<'\n';
}




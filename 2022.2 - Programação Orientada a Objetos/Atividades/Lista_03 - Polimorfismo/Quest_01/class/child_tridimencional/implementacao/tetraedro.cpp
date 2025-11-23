#include "../tetraedro.h"
#include <cmath>

void Tetraedro::construir(){
    setNome("Tetraedro Regular");
    setTipo("Tridimencional");

    apresentar();
    cout << "Digite a aresta do tetraedro: "; cin >> aresta;

    setAltura((aresta/3) * sqrt(6));
    setAreaDaBase(((aresta * aresta)/4) * sqrt(3));

    setArea((aresta * aresta) * sqrt(3));

    setVolume(((1/3) * areaDaBase) * altura);
}

void Tetraedro::setAreaDaBase(float area_){areaDaBase = area_;}

void Tetraedro::setAltura(float altura_){altura = altura_;}

void Tetraedro::setAreaTotal(float area_){areaTotal = area_;}

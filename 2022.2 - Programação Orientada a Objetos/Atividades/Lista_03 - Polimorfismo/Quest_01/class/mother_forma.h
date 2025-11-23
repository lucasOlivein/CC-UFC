#pragma once
#include <iostream>
using namespace std;

class Forma{
  private:
    string nome; //Triangulo, quadrado, esfera, etc
    string tipo; //Bidimencional ou Tridimencional
    float area;
    float volume;

    public:
      virtual ~Forma();
      void setNome(string);
      void setTipo(string);

      string getNome();
      string getTipo();
      void apresentar();

      virtual void imprimir() = 0;
      virtual void construir() = 0;
      /* virtual void setArea(float);
      virtual float getArea();

      virtual void setVolume(float);
      virtual float getVolume(); */


};


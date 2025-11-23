#pragma once
#include "../mother_forma.h"

class Tridimencional: public Forma{
  private:
    float area;
    float volume;

  public:
    /* Tridimencional();
    ~Tridimencional(); */
    void contruir();

    void setArea(float);
    float getArea();

    void setVolume(float);
    float getVolume();

    void imprimir();
    //void construir() = 0;
};
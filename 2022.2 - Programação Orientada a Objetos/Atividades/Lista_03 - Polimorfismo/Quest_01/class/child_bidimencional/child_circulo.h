#include "bidimencional.h"

class Circulo:public Bidimencional{
  private:
    float raio;
    float area;
  public:

    //Circulo();
    void construir();
    float getArea();
    void setRaio();
    float getRaio();
};
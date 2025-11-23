#include "bidimencional.h"

class Quadrado:public Bidimencional{
  private:
    float lado;

  public:
    //Quadrado();
    void construir();
    void dimencoes(float);
    float getArea();
    void setLado();
    float getLado();
};
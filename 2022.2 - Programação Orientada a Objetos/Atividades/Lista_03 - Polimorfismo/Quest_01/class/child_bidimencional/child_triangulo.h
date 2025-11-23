#include "bidimencional.h"


class Triangulo:public Bidimencional{
    private:
      float base;
      float altura;

    public:
      //Triangulo();
      void construir();
      float getArea();
      void setBase(float);
      void setAltura(float);
      float getBase();
      float getAltura();
};
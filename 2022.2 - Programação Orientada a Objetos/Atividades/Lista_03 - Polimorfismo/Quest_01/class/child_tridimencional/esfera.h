#include "tridimencional.h"

class Esfera: public Tridimencional{
  private:
    float raio;
  
  public:
    //Esfera();
    void setRaio();
    float getRaio();
    void construir();
};
#include "tridimencional.h"

class Cubo: public Tridimencional{
    private:
        float lado;

    public:
        //Cubo();
        void setLado();
        float getLado();
        void construir();
};
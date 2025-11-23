#include "tridimencional.h"

class Tetraedro: public Tridimencional{
    private:
        float aresta;
        float areaTotal;
        float areaDaBase;
        float altura;


    public:
        //Tetraedro();
        void setAreaTotal(float);
        void setAltura(float);
        void setAreaDaBase(float);
        void setAresta(float);
        float getLado();
        void construir();
};
#pragma once
#include "../mother_forma.h"


class Bidimencional:public Forma{
    private:
        float area;
    public:

        void dimencoes();
        void setDimencao_1();
        void setDimencao_2();

        float getDimencao_1();
        float getDimencao_2();

        void setArea(float);
        float getArea();

        Bidimencional();
        //~Bidimencional();
        virtual void imprimir();

        /* virtual setVolume();
        virtual getVolume(); */

};

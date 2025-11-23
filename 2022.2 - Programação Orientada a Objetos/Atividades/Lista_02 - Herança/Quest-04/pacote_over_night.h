#include "pacote_class.h"
class PacoteOverNight:protected Pacote{
    protected:
        float taxaAdicional;
    public:
        PacoteOverNight(string, string,string,string,string,string,string,string,string,string,float , float);

        double calcularCusto();
        void setTaxaAdicional(float, float);
        double getTaxaAdicional();
};
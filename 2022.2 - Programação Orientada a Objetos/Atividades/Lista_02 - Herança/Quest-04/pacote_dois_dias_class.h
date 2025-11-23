#include "pacote_class.h"
class PacoteDoisDias:protected Pacote{
    protected:
        float taxaAdicional;
    public:
        PacoteDoisDias(string, string,string,string,string,string,string,string,string,string,float , float);
        double calcularCusto();
        void setTaxaAdicional(float, float);
        double getTaxaAdicional();
};
#include"conta_class.h"

class Corrente:public Conta{
    private:
        float movi_taxis; //  taxa de movimentacao;
    
    public:
        Corrente(float);

        void credito(float); /// redefinicao dos metodos de movimentacao;
        void debito(float); ///

        float getMoviTaxis() const { return movi_taxis; }
        void setMoviTaxis(float moviTaxis) { movi_taxis = moviTaxis; }

        
};
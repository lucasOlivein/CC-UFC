#include "conta_class.h"

class Poupanca:public Conta{
    private:
        float rendimento; // rendimento atual da conta ao mes; 
    public:
        Poupanca(float);
        float calcula_rendimento(int); // calcula o rendimento do valor dado em 6 meses - 1 ano

        float getRendimento();
        void setRendimento(float);         

};
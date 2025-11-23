#include "veiculo_class.h"
#include<iostream>
using namespace std;

class VeiculoTerrestre: virtual public Veiculo{
    private:
        int rodas;
        bool estepe;
        string num_placa;
        int ano;
    public:
        VeiculoTerrestre();
        VeiculoTerrestre(string, string, string, float, int, int, int, bool, string, int);

        void print();

        /// @brief ////
        /// @return /////
        int getRodas() const { return rodas; }
        void setRodas(int rodas_) { rodas = rodas_; }

        bool getEstepe() const { return estepe; }
        void setEstepe(bool estepe_) { estepe = estepe_; }

        string getNumPlaca() const { return num_placa; }
        void setNumPlaca(const string &numPlaca) { num_placa = numPlaca; }

        int getAno() const { return ano; }
        void setAno(int ano_) { ano = ano_; }

        

        
};
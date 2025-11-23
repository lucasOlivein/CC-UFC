#include <iostream>
#include "veiculo_class.h"
#include "motor_class.h"

class CarroPasseio: Veiculo, Motor{
    private:
        std::string modelo;
        std::string cor;

    public:
        CarroPasseio();
        CarroPasseio(float, float, float, int, int, std::string, std::string);

        void setModelo(std::string);
        void setCor(std::string);

        std::string getModelo();
        std::string getCor();

        void print();

};
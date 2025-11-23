#include "Tempo.h"
#include <iostream>
using namespace std;
class Estacionamento{
    private:
        string placa;
        string modelo;
        Tempo entrada;
        Tempo saida;
        Tempo permanecido;

    public:
    Estacionamento();
    string getPlaca();
    string getModelo();
    Tempo getEntrada();
    Tempo getSaida();


    void setPlaca(string);
    void setModelo(string);
    void setEntrada(int, int, int);
    void setSaida(int, int, int);

    void report();

    float taxa();

};
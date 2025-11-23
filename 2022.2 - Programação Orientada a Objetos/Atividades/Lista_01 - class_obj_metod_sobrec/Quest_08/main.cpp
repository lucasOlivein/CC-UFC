#include <iostream>
using namespace std;

#include "Estacionamento.h"


int main(){
    Estacionamento c;
    c.setPlaca("BR-4160");
    c.setModelo("Toyota Corola");
    c.setEntrada(3, 15, 0);
    c.setSaida(5, 50, 30);

    c.report();
}
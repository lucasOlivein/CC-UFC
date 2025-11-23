#include <iostream>
using namespace std;
#include "carro_passeio_class.h"
/* #include "motor_class.h"
#include "veiculo_class.h" */

CarroPasseio::CarroPasseio(float peso, float max_velocidade, float preco, int cilindros, int potencia, string cor, string modelo ):Veiculo( peso, max_velocidade, peso),Motor(cilindros, potencia){
    setCor(cor);
    setModelo(modelo);
}

void CarroPasseio::print(){
    Veiculo::print();
    Motor::print();
    cout << "Cor: " << getCor() << '\n';
    cout << "Modelo: " << getModelo() << '\n';
    
}

void CarroPasseio::setCor(string cor){
    this->cor = cor;
}

void CarroPasseio::setModelo(string modelo){
    this->modelo = modelo;
}

string CarroPasseio::getModelo(){
    return modelo;
}

string CarroPasseio::getCor(){
    return cor;
}
#include <iostream>
using namespace std;
#include "motor_class.h"

Motor::Motor(int cilindros, int potencia){
    setCilindros(cilindros);
    setPotencia(potencia);
}

void Motor::print(){
    cout<<"Cilindros: "<< getCilindros() << '\n';
    cout <<"Potencia: " <<  getPotencia() << " Cv\n";

}

void Motor::setCilindros(int cilindros){
    this->cilindros = cilindros;
}

void Motor::setPotencia(int potencia){
    this->potencia = potencia;
}

int Motor::getCilindros(){
    return cilindros;
}

int Motor::getPotencia(){
    return potencia;
}
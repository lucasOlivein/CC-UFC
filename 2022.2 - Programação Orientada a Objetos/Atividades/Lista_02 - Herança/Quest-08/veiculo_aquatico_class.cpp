#include "veiculo_aquatico_class.h"
#include<iostream>
using namespace std;

VeiculoAquatico::VeiculoAquatico(string marca, string modelo, string cor, float potencia, int portas, int assentos, string tipo, string meio, bool proa, bool mastro, bool motor, string motor_tipo): Veiculo(marca, modelo, cor, potencia, portas, assentos){
    
    setMeio(meio);
    setProa(proa);
    setMastro(mastro);
    setMotor(motor);
    setMotorTipo(motor_tipo);

};
VeiculoAquatico::VeiculoAquatico(){

};

void VeiculoAquatico::print(){
  cout << "Meio: " << getMeio() << '\n';
  cout << "Possui uma Proa: " << getProa() << '\n';
  cout << "Possui um Mastro: " << getMastro() <<'\n';
  cout << "Possui Motor: " << getMotor() << '\n';
  cout << "Tipo do Motor: " << getMotorTipo() << '\n';
}
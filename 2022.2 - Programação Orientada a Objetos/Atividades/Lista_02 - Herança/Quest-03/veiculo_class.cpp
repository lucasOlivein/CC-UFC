#include <iostream>
using namespace std;
#include "veiculo_class.h"

Veiculo::Veiculo(){

}

Veiculo::Veiculo(float peso, float max_velocidade, float preco){
    setPeso(peso);
    setMaxVelocidade(max_velocidade);
    setPreco(preco);
}
void Veiculo::print(){
    cout <<"Preco: " << getPreco() << "$\n";
    cout <<"Velocidade Maxima: " << getMaxVelocidade() << " Km/h\n";
    cout <<"Peso: " << getPeso() << " Kg\n";

}

void Veiculo::setPeso(float peso){
    this->peso=peso;
}

void Veiculo::setMaxVelocidade(float maxVelocidade){
    this->max_velocidade = maxVelocidade;
}

void Veiculo::setPreco(float preco){
    this->preco = preco;
}


float Veiculo::getPeso(){
    return peso;
}

float Veiculo::getMaxVelocidade(){
    return max_velocidade;
}

float Veiculo::getPreco(){
    return preco;
}
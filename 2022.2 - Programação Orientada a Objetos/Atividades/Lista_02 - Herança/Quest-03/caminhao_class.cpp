#include "caminhao_class.h"
#include <iostream>
Caminhao::Caminhao(float peso, float max_velocidade , float preco, int cilindros, int potencia, float altura, float comprimento):Motor(cilindros, potencia), Veiculo(peso, max_velocidade, preco){
        setAltura(altura);
        setComprimento(comprimento);
        setToneladas(peso);

        
}
/* void Veiculo::print(){
    std::cout <<"Preco: " << getPreco() << "$\n";
    std::cout <<"Velocidade Maxima: " << getMaxVelocidade() << " Km/h\n";
    std::cout <<"Peso: " << getPeso() << " Toneladas\n";
    } */


void Caminhao::print(){
    Motor::print();
    Veiculo::print();
    std::cout<< "Altura: " << getAltura() << " m\n";
    std::cout << "Comprimento: " << getComprimento() << " m\n";

}

void Caminhao::setAltura(float altura){
    this->altura = altura;
}

void Caminhao::setToneladas(float){
    this->toneladas = Veiculo::getPeso();
}

void Caminhao::setComprimento(float comprimento){
    this->comprimento = comprimento;
}


float Caminhao::getAltura(){
    return altura;
}
float Caminhao::getComprimento(){
    return comprimento;
}
float Caminhao::getToneldas(){
    return toneladas;
}
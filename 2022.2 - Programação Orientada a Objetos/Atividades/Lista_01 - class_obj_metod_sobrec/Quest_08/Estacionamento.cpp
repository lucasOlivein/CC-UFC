#include "Estacionamento.h"
#include <iostream>
using namespace std;

Estacionamento::Estacionamento(){
        placa = "";
        modelo = "";
        entrada = Tempo(0,0,0);
        saida = Tempo(0,0,0);
}

    string Estacionamento::getPlaca(){
        return placa;
    };
    string Estacionamento::getModelo(){
        return modelo;
    };
    Tempo Estacionamento::getEntrada(){
        return entrada;
    };
    Tempo Estacionamento::getSaida(){
        return saida;
    };

    void Estacionamento::setPlaca(string placa_){
        placa = placa_;
    };
    void Estacionamento::setModelo(string modelo_){
        modelo = modelo_;
    };
    void Estacionamento::setEntrada(int h, int m, int s){
        entrada = Tempo(h,m,s);
    };
    void Estacionamento::setSaida(int h,int m ,int s){
        saida = Tempo(h,m,s);
    };

    float Estacionamento::taxa(){
        permanecido.subtrair(saida, entrada);
        return permanecido.getHora() *1.5;
    }


    void Estacionamento::report(){
        cout << "Veiculo: " << modelo << '\n';
        cout << "Placa: " << placa << '\n';
        cout << "Horario de entrada: "; entrada.print(); cout << '\n';
        cout << "Horario de saida: "; saida.print(); cout << '\n';
        cout << "Valor a pagar: R$" << taxa() << ", por R$1,50 a hora.";
    }
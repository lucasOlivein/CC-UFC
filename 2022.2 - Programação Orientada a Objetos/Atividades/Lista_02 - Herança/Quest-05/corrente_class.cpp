#include"corrente_class.h"
#include <iostream>
Corrente::Corrente(float saldo):Conta(saldo){
    setMoviTaxis(10); // taxa padrao iniciada no contrutor
};

void Corrente::credito(float deposito){
    if(deposito <= getMoviTaxis())
        std::cout << "Erro! Abaixo do valor minimo\nValor minimo para transacao de deposito: " << getMoviTaxis()+1 << '\n';
    else 
        Conta::setSaldo(deposito - getMoviTaxis());
}

void Corrente::debito(float retirada){
    if(Conta::getSaldo() < (retirada + getMoviTaxis()))
        std::cout <<"Erro!\nSaldo insuficiente para a transacao\n";
    else
        Conta::setSaldo(Conta::getSaldo() - (retirada + getMoviTaxis()));
}
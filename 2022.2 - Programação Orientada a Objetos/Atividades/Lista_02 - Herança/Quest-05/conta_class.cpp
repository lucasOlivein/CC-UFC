#include<iostream>
#include"conta_class.h"

Conta::Conta(float saldo){
    setSaldo(saldo);
}

void Conta::mostrar_saldo(){
    std::cout <<"O saldo é : " << getSaldo() << '\n';
}

void Conta::credito(float deposito){
    setSaldo(getSaldo()+deposito);
}

void Conta::debito(float retirada){
    if(retirada > getSaldo())
        std::cout << "Saldo insuficiente!\nO saldo disponivel é: " << getSaldo()<<'\n';
    else    
        setSaldo(getSaldo() - retirada);
}

float Conta::getSaldo() { return saldo; }
void Conta::setSaldo(float saldo) { this->saldo = saldo; }
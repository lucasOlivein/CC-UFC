#include "conta_class.h"
#include <iostream>
using namespace std;

Conta::Conta(float saldo_){
  if(saldo_ < 0){
    cout << "Erro!\nSaldo negativo\n";
    saldo = 0;
  }else  
    saldo = saldo_;
};

void Conta::credito(float deposito){
  saldo += deposito;
}

void Conta::debito(float saque){
  if(saque > getSaldo())
    cout << "Waning!!\nSaldo insuficiente\nOperacao cancelada!! \n";
  else 
    saldo -= saque;
}

float Conta::getSaldo(){
    return saldo;
}
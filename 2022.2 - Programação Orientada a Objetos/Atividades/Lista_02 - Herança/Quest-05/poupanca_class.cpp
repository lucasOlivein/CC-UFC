#include "poupanca_class.h"
#include<math.h>

Poupanca::Poupanca(float saldo):Conta(saldo){
    setRendimento(1/100); // rendimento padrao de 1% ao mes;
}

float Poupanca::getRendimento(){ return rendimento; }
void Poupanca::setRendimento(float rendimento_){rendimento = rendimento_;}

float Poupanca::calcula_rendimento(int meses){ // tem como entrada a quantidade de tempo em meses
    return (getSaldo() * pow(1+getRendimento(), meses));
}

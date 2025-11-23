#include<iostream>
using namespace std;
#include"corrente_class.h"
#include"poupanca_class.h"



int main(){
    Corrente c = Corrente(30);

    cout << "saldo: " << c.getSaldo() <<'\n';
    cout <<"deposito: 10\n";
    c.credito(10);

    cout << "saldo atualizado: " << c.getSaldo() <<'\n';

}
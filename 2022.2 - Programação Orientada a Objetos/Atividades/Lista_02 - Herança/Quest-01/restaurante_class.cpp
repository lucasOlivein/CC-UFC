
#include<iostream>
using namespace std;

#include "restaurante_class.h"


Restaurante::Restaurante(string nome, string endereco, string cidade, string estado, string cep, string telefone):Empresa(nome, endereco, cidade, estado, cep, telefone){
        
    }

    void Restaurante::print(){
            Empresa::print();
        }
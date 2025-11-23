#include "class/mother_forma.h"

#include <iostream>
using namespace std;

void Forma::setNome(string nome_){
    nome = nome_;
}
void Forma::setTipo(string tipo_){
    tipo = tipo_;
}

Forma::~Forma(){
    cout << "Forma deletada: " + nome + "\n\n";
}

string Forma::getNome(){
    return nome;
}

string Forma::getTipo(){
    return tipo;
}

void Forma::apresentar(){
  cout << "Forma Selecionada: " + getNome() +", Tipo: " + getTipo() + '\n';
}




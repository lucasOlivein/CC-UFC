#include "empregado_class.h"
#include <iostream>
using namespace std;

Empregado::Empregado(string nome, string sobrenome, float salario){
  setNome(nome);
  setSobrenome(sobrenome);
  setSalario(salario);
};

void Empregado::setNome(const string &nome_) { nome = nome_; }
void Empregado::setSobrenome(const string &sobrenome_) { sobrenome = sobrenome_; }
void Empregado::setSalario(float salario_) { salario = salario_; }

string Empregado::getNome() const { return nome; }
string Empregado::getSobrenome() const { return sobrenome; }
float Empregado::getSalario() const { return salario; }

float Empregado::salarioAnual(){
  return (getSalario() * 12);
}

void Empregado::aumentarSalario(int porcento){
    setSalario(getSalario() + (getSalario()*porcento)/100);
}
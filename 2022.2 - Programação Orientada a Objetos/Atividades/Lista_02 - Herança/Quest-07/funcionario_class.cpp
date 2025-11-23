#include "funcionario_class.h"
#include<iostream>
using namespace std;

Funcionario::Funcionario(string nome, float salario, string turno, string disciplina, int carga_horaria):Monitor(disciplina, carga_horaria){
    setNome(nome);
    setSalario(salario);
    setTurno(turno);
};

void Funcionario::print(){
    cout << "Nome: " << getNome() <<'\n';
    cout << "Salario: R$" << getSalario() <<"\n";
    cout << "Turno: " << getTurno() << '\n';
    Monitor::print();

}


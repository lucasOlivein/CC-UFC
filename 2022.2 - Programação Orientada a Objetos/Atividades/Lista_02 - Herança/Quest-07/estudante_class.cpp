#include"estudante_class.h"
#include "monitor_class.h"
#include <iostream>
using namespace std;

Estudante::Estudante(string nome, string matricula, string curso,string disciplina, int carga_horaria):Monitor(disciplina, carga_horaria){
    setNome(nome);
    setMatricula(matricula);
    setCurso(curso);
    setDisciplina(disciplina);
};

void Estudante::print(){
    cout << "Nome: " << getNome() <<'\n';
    cout <<"Matricula: " << getMatricula() << '\n';
    cout <<"Curso: " << getCurso() << '\n';
    Monitor::print(); 
}




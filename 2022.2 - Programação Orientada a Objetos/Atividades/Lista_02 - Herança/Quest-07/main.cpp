
#include <iostream>
using namespace std;

#include "estudante_class.h" // construtor - str Nome, str Matricula, str Curso, str diciplina, int carga horaria
#include "funcionario_class.h" // construtor - str Nome, float salario, string turno, std displina, int carga_horaria


int main(){
    Estudante e = Estudante("Lucas", "475597", "CC", "POO", 64);
    //e.print();

    Funcionario f = Funcionario("Lucas", 1245.59, "Manha","POO", 64);
    f.print();
}
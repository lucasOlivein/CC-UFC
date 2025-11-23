#include<iostream>
using namespace std;
#include "monitor_class.h"


Monitor::Monitor(string disciplina, int carga_horaria){ ////ainda nao sei oq colocar ai
    setCargaHoraria(carga_horaria);
    setDisciplina(disciplina);
}

void Monitor::print(){
  cout << "Disciplina: " << getDisciplina() << '\n';
  cout << "Carga Horaria: " << getCargaHoraria() << "h\n";
}
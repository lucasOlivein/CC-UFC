#ifndef MONITOR_CLASS_H
#define MONITOR_CLASS_H



#include "monitor_class.h"
#include<iostream>
using namespace std;

class Monitor{
    private:
        string disciplina;
        int carga_horaria;
    public:
        Monitor(string, int);


        void print();

        string getDisciplina() const { return disciplina; }
        void setDisciplina(const string &disciplina_) { disciplina = disciplina_; }

        int getCargaHoraria() const { return carga_horaria; }
        void setCargaHoraria(int cargaHoraria) { carga_horaria = cargaHoraria; }
};

#endif // MONITOR_CLASS_H

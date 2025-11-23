#include<iostream>
using namespace std;
#include"monitor_class.h"

class Funcionario:Monitor{
    private:
        string nome;
        float salario;
        string turno;
        string RG;
    
    public:
        Funcionario(string,float,string, string,int);

        string getNome() const { return nome; }
        void setNome(const string &nome_) { nome = nome_; }

        float getSalario() const { return salario; }
        void setSalario(float salario_) { salario = salario_; }

        string getTurno() const { return turno; }
        void setTurno(const string &turno_) { turno = turno_; }

        void print();
        

};
#include <iostream>
using namespace std;

#include "monitor_class.h"

class Estudante:Monitor{
    private:
        string nome;
        string matricula;
        string curso;

        public:
            Estudante(string, string, string,string, int);

            string getNome() const { return nome; }
            void setNome(const string &nome_) { nome = nome_; }

            string getMatricula() const { return matricula; }
            void setMatricula(string matricula_) { matricula = matricula_; }

            string getCurso() const { return curso; }
            void setCurso(const string &curso_) { curso = curso_; }

            void print();
            

};
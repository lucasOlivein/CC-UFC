#include <iostream>
using namespace std;

#include "aluno_class.h"


Aluno::Aluno(string nome_, string serie_, string grau_){
  setNumeroDeAlunos(getNumeroDeAlunos() + 1);
  nome = nome_;
  serie = serie_;
  grau = grau_;
};


Aluno::~Aluno(){
}

/* int Aluno::getN(){
  return n;
} */
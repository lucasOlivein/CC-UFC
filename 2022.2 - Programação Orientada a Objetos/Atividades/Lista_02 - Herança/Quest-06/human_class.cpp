#include "human_class.h"
#include <iostream>
using namespace std;

Human::Human(string nome, string sexo, int idade, string lingua, string etinia){
    setNome(nome);
    setSexo(sexo);
    setIdade(idade);
    setLingua(lingua);
    setEtinia(etinia);
};

void Human::print(){
    cout <<"Nome: "<< getNome() << '\n';
    cout <<"Sexo: " <<  getSexo() << '\n';
    cout << "Idade: " << getIdade() << '\n';
    cout << "Lingua: " <<getLingua() << '\n';
    cout << "Etinia: "<< getEtinia() << '\n';
}


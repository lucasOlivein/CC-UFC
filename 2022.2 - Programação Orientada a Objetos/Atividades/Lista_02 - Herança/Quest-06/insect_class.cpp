
#include <iostream>
using namespace std;
#include"insect_class.h"

Insect::Insect(std::string nome, bool venenoso, bool alado, bool ferrao){
    setNome(nome);
    setVenenoso(venenoso);
    setAlado(alado);
    setFerrao(ferrao);
};

void Insect::print(){
    cout << getNome() <<'\n';
    cout <<"Venenoso: " << getVenenoso() << '\n';
    cout <<"Alado: " << getAlado()<< '\n';
    cout << "Ferrao: " << getFerrao()<< '\n';
}
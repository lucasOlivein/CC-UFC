#include <iostream>
using namespace std;
#include"super_hero_class.h"


SHero::SHero(string nome_human, string sexo, int idade, string lingua, string etinia, string nome_insect, bool venenoso, bool alado, bool ferrao, string codinome, string trauma, string poderes):Human(nome_human, sexo, idade, lingua, etinia), Insect(nome_insect,venenoso, alado, ferrao){
    setCodinome(codinome);
    setTrauma(trauma);
    setPoderes(poderes);
};

void SHero::print(){
    Human::print();
    Insect::print();

    cout<< "Codinome: " << getCodinome() << '\n';
    cout << "Trauma: " << getTrauma() << '\n';
    cout << "Poderes: " << getPoderes();
}
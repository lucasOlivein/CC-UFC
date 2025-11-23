#include <iostream>
using namespace std;

#include "super_hero_class.h"

int main(){
    SHero h = SHero("SuperA", "Masculino", 25, "English", "Pardo", "Abelha", true, true, false, "SuperA", "Urso", "Comeia");
    cout << "'''''''''''''INICIO''''''''''\n";
    h.print();
    cout << "\n'''''''''''FIM'''''''''''''''\n";
}
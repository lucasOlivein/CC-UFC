#include "human_class.h"
#include "insect_class.h"
#include <iostream>

class SHero: protected Human, Insect{
    protected:
        string codinome;
        string trauma;
        string poderes;

    public:
        SHero(string, string,int, string, string, string, bool, bool, bool, string, string, string);

        void print();

        string getCodinome() const { return codinome; }
        void setCodinome(const string &codinome_) { codinome = codinome_; }

        string getTrauma() const { return trauma; }
        void setTrauma(const string &trauma_) { trauma = trauma_; }

        string getPoderes() const { return poderes; }
        void setPoderes(const string &poderes_) { poderes = poderes_; }

};
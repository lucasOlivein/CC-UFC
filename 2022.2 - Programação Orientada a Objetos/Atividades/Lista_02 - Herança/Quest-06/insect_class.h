#include <iostream>
using namespace std;
class Insect{
    protected:
        string nome;
        bool venenoso;
        bool alado;
        bool ferrao;

    public:
        Insect(string, bool, bool, bool);
        void print();

        bool getVenenoso() const { return venenoso; }
        void setVenenoso(bool venenoso_) { venenoso = venenoso_; }

        string getNome() const { return nome; }
        void setNome(const string &nome_) { nome = nome_; }

        bool getAlado() const { return alado; }
        void setAlado(bool alado_) { alado = alado_; }

        bool getFerrao() const { return ferrao; }
        void setFerrao(bool ferrao_) { ferrao = ferrao_;}
};
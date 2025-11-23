#pragma once
#include <iostream>
#include <set>
#include <list>
#include <map>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>

using namespace std;

class Midia
{
private:
    string artista;
    string titulo;
    vector<string> faixas;
    int lancamento;
    string genero;
    vector<string> keyords;

public:
    string getArtista();
    void setArtista(string artista_);

    string getTitulo();
    void setTitulo(string titulo_);

    vector<string> getFaixas();
    void setFaixas(vector<string> faixa_);
    /* bool getFaixa(string faixa_)
    {
        set<string>::iterator it = faixas.find(faixa_);
        return it != faixas.end();
    } */

    int getLancamento();
    void setLancamento(int lancamento_);

    string getGenero();
    void setGenero(string genero_);

    vector<string> getKeywords();
    void setKeywords(vector<string> Keyword_);
};

class CD : public Midia
{
private:
    int duracao;
    float volume;
    bool coletania;

public:
    void setDuracao(int duracao_);
    int getDuracao();

    void setVolume(float volume_);
    float getVolume();

    void setColetania(bool coletania_);
    bool getColetania();
    void setKeywords();
};

class DVD : public Midia
{
private:
    set<string> formatoAudio;
    set<string> formatoTela;
    list<string> legendas;

public:
    set<string> getFormatAudio();
    void setFormatAudio(set<string> formAud);

    set<string> getFormatTela();
    void setFormatTela(set<string> formTela);

    list<string> getLegendas();
    void setLegendas(list<string> legen);
    void setKeywords();
};
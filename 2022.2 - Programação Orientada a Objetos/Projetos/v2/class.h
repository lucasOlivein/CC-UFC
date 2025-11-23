#pragma once
#include <iostream>
#include <set>
#include <list>
#include <map>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <fstream>
#include <dirent.h>
using namespace std;

class Midia
{
private:
    string coletania;
    string artista;
    string titulo;
    vector<string> faixas;
    int lancamento;
    string genero;
    vector<string> keyords;

public:
    virtual int getDuracao(){
        return 0;
    }
    virtual void setDuracao(int duracao_){
        return;
    }
    void setMidia()
    {
        string nome;
        int numeros;

        cout << "Nome do artista: ";
        getline(cin, nome, '\n');
        if (nome.empty())
        {
            setArtista("<< nao informado >>");
            cout << "\b<< nao informado >>\n"
                 << "artista: " << getArtista() << "\n";
        }
        else
        {
            setArtista(nome);
        }
        cout << "Titulo: ";
        getline(cin, nome, '\n');
        if (nome.empty())
        {
            cout << "\b<< nao informado >>\n";
            setTitulo("<< nao informado >>");
            cout << "titulo: " << getTitulo() << "\n";
        }
        else
        {
            setTitulo(nome);
        }

        cout << "\n[ Adicionando faixas ]\n<< digite 0 para sair >>\n";
        int i = 0; /////////////////////////// i = 0 deletar
        while (1)
        {
            cout << "Nome da faixa:: ";
            getline(cin, nome, '\n');
            if (nome == "0")
            {
                if (faixas.empty())
                {
                    cout << "Nenhuma faixa adicionada\n";
                    cout << "Adicionar faixa? (s/n): ";
                    getline(cin, nome, '\n');
                    if (nome == "n" || nome == "0")
                    {
                        cout << "Nenhuma faixa adicionada..\n";
                        adicionarFaixa("<< sem faixas >>");
                        system("pause");
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (nome.empty())
                    cout << "<< nao informado >>\n";
                else
                {

                    adicionarFaixa(nome);
                    cout << "Faixa << " << faixas[i] << " >> adicionada\n";
                    i++;
                }
            }
        }
        while (1)
        {
            cout << "Ano de lancamento:: ";
            cin >> numeros;
            if (!cin || numeros < 1900 || numeros > 2022)
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "<< entrada invalida >>\nInformar novamente ou Digite 0 para sair:: ";
            }
            if(numeros == 0)
                setLancamento(0);
            else
            {
                setLancamento(numeros);
                break;
            }
        }
        while (1)
        {
            cin.ignore();
            cout << "Genero:: ";
            getline(cin, nome, '\n');
            if (nome.empty())
            {
                cout << "<< nao informado >>\nTentar novamente? (s/n)";
                getline(cin, nome, '\n');
                if (nome == "n")
                {
                    setGenero("Nao informado");
                    break;
                }
            }
            else
            {
                setGenero(nome);
                break;
            }
        }
    }
    string getNomeColetania()
    {
        return coletania;
    }
    void setNomeColetania(string coletania_)
    {
        coletania = coletania_;
    }
    string getArtista();
    void setArtista(string artista_);

    string getTitulo();
    void setTitulo(string titulo_);

    vector<string> getFaixas();
    void adicionarFaixa(string faixa_)
    {
        faixas.push_back(faixa_);
    }
    void removerFaixa(string faixa_)
    {
        vector<string>::iterator it = find(faixas.begin(), faixas.end(), faixa_);
        if (it != faixas.end())
        {
            faixas.erase(it);
        }
    }
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
void Op1(vector<Midia> &midia, string ope);

class CD : public Midia
{
private:
    int duracao;
    float volume;
    bool coletania;

public:
    int getDuracao()
    {
        return duracao;
    }
    void setDuracao(int duracao_);

    void setVolume(float volume_);
    float getVolume();

    void setColetania(bool coletania_);
    bool getColetania();
    void setKeywords();


    void set_midia(vector<Midia> &midia)
    {

        this->setMidia();

        int numeros;
        float numeros2;
        string nome;
        while (1)
        {
            cout << "Duracao: ";
            cin >> numeros;
            if (!cin || numeros < 0 || numeros > 1000)
            {
                cout << "<< entrada invalida >>\nTente novamente\n";
            }
            else
            {
                setDuracao(numeros);
                break;
            }
        }
        while (1)
        {
            cout << "Volume: ";
            cin >> numeros2;
            if (!cin || numeros2 < 0 || numeros2 > 1000)
            {
                cout << "Entrada invalida\n";
            }
            else
            {
                setVolume(numeros2);
                break;
            }
        }
        cin.ignore();
        cout << "Coletania? (s/n): ";
        getline(cin, nome, '\n');
        if (nome == "s")
        {
            setColetania(true);
        }
        else
        {
            setColetania(false);
        }

        this->setKeywords();
        midia.push_back(*this);
    }
};

class DVD : public Midia
{
private:
    vector<string> formatoAudio;
    vector<string> formatoTela;
    vector<string> legendas;

public:
    int getDuracao()
    {
        return 0;
    }
    vector<string> getFormatAudio();
    void setFormatAudio(vector<string> formAud);

    vector<string> getFormatTela();
    void setFormatTela(vector<string> formTela);

    vector<string> getLegendas();
    void setLegendas(vector<string> legen);
    void setKeywords();

    void set_midia(vector<Midia> &midia)
    {
        this->setMidia();
        string nome;
        cout << "[ Adicionando formatos de audios ]\n<< digite 0 para sair >>\n\n";
        while (1)
        {
            cout << "Formato de audio: ";
            getline(cin, nome, '\n');

            if (nome == "0")
            {
                if (formatoAudio.empty())
                {
                    cout << "Nenhum formato de audio adicionado\n";
                    cout << "Adicionar formato de audio? (s/n): ";
                    getline(cin, nome, '\n');
                    if (nome == "n" || nome == "0")
                    {
                        cout << "<< Nenhum formato de audio adicionado >>\n\n";
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (nome.empty())
                    cout << "Nome nao informado\n";
                else
                    formatoAudio.push_back(nome);
            }
        }
        cout << "[ Adicionando formatos de tela ]\n<< digite 0 para sair >>\n\n";
        while (1)
        {
            cout << "Formato de tela: ";
            getline(cin, nome, '\n');
            if (nome == "0")
            {
                if (formatoTela.empty())
                {
                    cout << "Nenhum formato de tela adicionado\n";
                    cout << "Adicionar formato de tela? (s/n): ";
                    getline(cin, nome, '\n');
                    if (nome == "n" || nome == "0")
                    {
                        cout << "<< Nenhum formato de tela adicionado >>\n\n";
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (nome.empty())
                    cout << "Nome nao informado\n";
                else
                    formatoTela.push_back(nome);
            }
        }
        cout << "[ Adicionando legendas ]\n<< digite 0 para sair >>\n";
        while (1)
        {
            cout << "Nome da legenda:: ";
            getline(cin, nome, '\n');
            if (nome == "0")
            {
                if (legendas.empty())
                {
                    cout << "Nenhuma legenda adicionada\n";
                    cout << "Adicionar legenda? (s/n): ";
                    getline(cin, nome, '\n');
                    if (nome == "n" || nome == "0")
                    {
                        cout << "<< Nenhuma legenda adicionada >>\n\n";
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (nome.empty())
                    cout << "Nome nao informado\n";
                else
                    legendas.push_back(nome);
            }
        }
        this->setKeywords();
        midia.push_back(*this);
    }
};
#include "notaFiscal_class.h"
#include<iostream>
using namespace std;

NotaFiscal::NotaFiscal(){};
NotaFiscal::NotaFiscal(string nume_peca, string descricao, int quant, float preco){
    setNumeroPecas(nume_peca);
    setDescriPecas(descricao);
    setQuantComprada(quant);
    setPreco(preco);
};


    void NotaFiscal::setNumeroPecas(const string &numeroPecas_) { numeroPecas = numeroPecas_; }
    void NotaFiscal::setDescriPecas(const string &descriPecas_) { descriPecas = descriPecas_; }
    void NotaFiscal::setQuantComprada(int quantComprada_) { quantComprada = quantComprada_; }
    void NotaFiscal::setPreco(float preco_) { preco = preco_; }


    string NotaFiscal::getNumeroPecas() const { return numeroPecas; }
    string NotaFiscal::getDescriPecas() const { return descriPecas; }
    int NotaFiscal::getQuantComprada() const { return quantComprada; }
    float NotaFiscal::getPreco() const { return preco; }


    float NotaFiscal::getTotalNota(NotaFiscal total[], int i){
      float valor={};
        for(int j =0; j < i; j++){
          valor =+ (total[j].getPreco() * total[j].getQuantComprada());       
        }
        return valor;
}


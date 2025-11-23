#include<iostream>
using namespace std;

#include "pacote_over_night.h"

PacoteOverNight::PacoteOverNight(string nome_destinatario,string endereco_destinatario,string cidade_destinatario,string estado_destinatario,string cep_destinatario,string nome_remetente,string endereco_remetente,string cidade_remetente,string estado_remetente,string cep_rementente,float peso,
float precoKG):Pacote(nome_destinatario,endereco_destinatario,cidade_destinatario,estado_destinatario,cep_destinatario,nome_remetente,endereco_remetente,cidade_remetente,estado_remetente,cep_rementente, peso, precoKG){
    setTaxaAdicional(peso, precoKG);

};



double PacoteOverNight::calcularCusto(){
    return (Pacote::calculaCusto(peso,precoKG) + getTaxaAdicional()*peso );
}

void PacoteOverNight::setTaxaAdicional(float peso, float precoKG){
    if(peso <= 0 || precoKG <= 0)
        taxaAdicional = 0;
    else
        taxaAdicional = (peso*precoKG)/4;
}

double PacoteOverNight::getTaxaAdicional(){
    return taxaAdicional;
}


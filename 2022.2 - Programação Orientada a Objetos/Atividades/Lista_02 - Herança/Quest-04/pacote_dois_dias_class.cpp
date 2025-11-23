#include"pacote_dois_dias_class.h"
#include<iostream>
using namespace std;
PacoteDoisDias::PacoteDoisDias(string nome_destinatario,string endereco_destinatario,string cidade_destinatario,string estado_destinatario,string cep_destinatario,string nome_remetente,string endereco_remetente,string cidade_remetente,string estado_remetente,string cep_rementente,float peso,
float precoKG):Pacote(nome_destinatario,endereco_destinatario,cidade_destinatario,estado_destinatario,cep_destinatario,nome_remetente,endereco_remetente,cidade_remetente,estado_remetente,cep_rementente, peso, precoKG){
    if(peso <= 0 || precoKG <= 0){
        cout << "Peso ou Preco/kg meno ou igual a zero\n";
        peso = 0;
        precoKG = 0;
    }
    setTaxaAdicional(peso, precoKG);

};



double PacoteDoisDias::calcularCusto(){
    return (Pacote::calculaCusto(peso,precoKG) + getTaxaAdicional() );
}

void PacoteDoisDias::setTaxaAdicional(float peso, float precoKg){
    taxaAdicional = (precoKG*peso)/4;
}

double PacoteDoisDias::getTaxaAdicional(){
    return taxaAdicional;
}

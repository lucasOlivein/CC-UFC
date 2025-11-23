#include "pacote_class.h"
#include<iostream>

Pacote::Pacote(string nome_destinatario,string endereco_destinatario,string cidade_destinatario,string estado_destinatario,    string cep_destinatario,string nome_remetente,string endereco_remetente,string cidade_remetente,string estado_remetente,string cep_rementente,float peso,float precoKG){

        setNomeDestinatario( nome_destinatario);

        setEnderecoDestinatario( endereco_destinatario);

        setCidadeDestinatario( cidade_destinatario);

        setEstadoDestinatario( estado_destinatario);

        setCepDestinatario(cep_destinatario);

        setNomeRemetente(nome_remetente);

        setEnderecoRemetente( endereco_remetente);

        setCidadeRemetente( cidade_remetente);

        setEstadoRemetente( estado_remetente);

        setCepRementente( cep_rementente);

        setPeso(peso);

        setPrecoKG(precoKG);


};


        void Pacote::setNomeDestinatario( string nomeDestinatario) {this->nome_destinatario = nomeDestinatario; }

        void Pacote::setEnderecoDestinatario( string enderecoDestinatario) {this->endereco_destinatario = enderecoDestinatario; }

        void Pacote::setCidadeDestinatario( string cidadeDestinatario) {this->cidade_destinatario = cidadeDestinatario; }

        void Pacote::setEstadoDestinatario( string estadoDestinatario) {this->estado_destinatario = estadoDestinatario; }

        void Pacote::setCepDestinatario( string cepDestinatario) {this->cep_destinatario = cepDestinatario; }

        void Pacote::setNomeRemetente( string nomeRemetente) {this->nome_remetente = nomeRemetente; }

        void Pacote::setEnderecoRemetente( string enderecoRemetente) {this->endereco_remetente = enderecoRemetente; }

        void Pacote::setCidadeRemetente( string cidadeRemetente) {this->cidade_remetente = cidadeRemetente; }

        void Pacote::setEstadoRemetente( string estadoRemetente) {this->estado_remetente = estadoRemetente; }

        void Pacote::setCepRementente( string cepRementente) {this->cep_rementente = cepRementente; }

        void Pacote::setPeso(float peso){this->peso = peso;}

        void Pacote::setPrecoKG(float precoKg){this->precoKG = precoKg; }

        double Pacote::calculaCusto(float peso, float precoKg){
                if(peso <= 0 || precoKg <= 0)
                        return 0;
                else
                        return (peso * precoKg);
        }

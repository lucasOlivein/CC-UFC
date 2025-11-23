#pragma once
#include <iostream>
using namespace std;

class Pacote{

    protected:
        string nome_destinatario;
        string endereco_destinatario;
        string cidade_destinatario;
        string estado_destinatario;
        string cep_destinatario;

        string nome_remetente;
        string endereco_remetente;
        string cidade_remetente;
        string estado_remetente;
        string cep_rementente;

        float peso;
        float precoKG;

    public:
        Pacote(string,string,string,string,string,string,string,string,string,string, float, float);

        double calculaCusto(float, float);

        void setNomeDestinatario( string);

        void setEnderecoDestinatario( string);
        void setCidadeDestinatario( string);
        void setEstadoDestinatario( string);
        void setCepDestinatario( string);
        void setNomeRemetente( string);
        void setEnderecoRemetente( string); 
        void setCidadeRemetente( string );       
        void setEstadoRemetente( string);       
        void setCepRementente( string);

        void setPeso(float);
        void setPrecoKG(float);

};
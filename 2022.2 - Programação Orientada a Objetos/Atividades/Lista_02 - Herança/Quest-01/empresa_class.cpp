#include <iostream>
using namespace std;
#include "empresa_class.h"


///////////////Construtores///////////////////////////////
Empresa::Empresa(string nome = "Defalt" , string endereco = "Defalt" , string cidade= "Defalt" , string estado= "Defalt", string cep= "Defalt",string telefone= "Defalt"){
    setNome(nome);
    setEndereco(endereco);
    setCidade(cidade);
    setEstado(estado);
    setCep(cep);
    setTelefone(telefone);
};
    Empresa::Empresa(){
}
//////////////End_Construtores///////////////

///////////Metodos////////////
void Empresa::print(){
    cout<< getNome() << '\n';
    cout << getEndereco() << '\n';
    cout << getCidade() << '\n';
    cout << getEstado() << '\n';
    cout << getCep()<< '\n';
    cout << getTelefone();
}

    /////////////Gets/////////////////
string Empresa::getNome(){
    return nome;
}
string Empresa::getEndereco(){
    return endereco;
}
string Empresa::getCidade(){
    return cidade;
}
string Empresa::getEstado(){
    return estado;
}
string Empresa::getCep(){
    return cep;
}
string Empresa::getTelefone(){
    return telefone;
}/////////////end_Gets/////////////////


/////////Sets///////////////////////
void Empresa::setNome(string nome){
    this->nome = nome;
}
void Empresa::setEndereco(string endereco){
    this->endereco = endereco;
}
void Empresa::setCidade(string cidade){
    this->cidade = cidade;
}
void Empresa::setEstado(string estado){
    this->estado = estado;
}
void Empresa::setCep(string cep){
    this->cep = cep;
}
void Empresa::setTelefone(string telefone){
    this->telefone = telefone;
}

///////End_Sets//////////////////



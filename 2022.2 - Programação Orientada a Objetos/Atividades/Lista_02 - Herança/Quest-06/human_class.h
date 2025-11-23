#include <iostream>
class Human{
    protected:
        std::string nome;
        std::string sexo;
        int idade;
        std::string lingua;
        std::string etinia;

    public:
        Human(std::string, std::string, int, std::string, std::string);

        void print();

        std::string getNome() const { return nome; }
        void setNome(const std::string &nome_) { nome = nome_; }

        std::string getSexo() const { return sexo; }
        void setSexo(const std::string &sexo_) { sexo = sexo_; }

        int getIdade() const { return idade; }
        void setIdade(int idade_) { idade = idade_; }

        std::string getLingua() const { return lingua; }
        void setLingua(const std::string &lingua_) { lingua = lingua_; }

        std::string getEtinia() const { return etinia; }
        void setEtinia(const std::string &etinia_) { etinia = etinia_; }
};
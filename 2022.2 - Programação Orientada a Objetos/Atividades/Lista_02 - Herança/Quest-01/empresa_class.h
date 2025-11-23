class Empresa{
    private:
        float rendimeto;
        string nome;
        string endereco;
        string cidade;
        string estado;
        string cep;
        string telefone;
    
    public:
        
        Empresa(string, string, string, string, string, string);
        Empresa();
        
        void setNome(string);
        void setEndereco(string);
        void setCidade(string);
        void setEstado(string);
        void setCep(string);
        void setTelefone(string);

        string getNome();
        string getEndereco();
        string getCidade();
        string getEstado();
        string getCep();
        string getTelefone();

        void print();
              
};

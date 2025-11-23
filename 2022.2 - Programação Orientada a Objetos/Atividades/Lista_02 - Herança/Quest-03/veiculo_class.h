class Veiculo{
    private:
        float peso;
        float max_velocidade;
        float preco;
    public:
        Veiculo();
        Veiculo(float, float, float);

        void print();

        void setPeso(float);
        void setMaxVelocidade(float);
        void setPreco(float);

        float getPeso();
        float getMaxVelocidade();
        float getPreco();


};
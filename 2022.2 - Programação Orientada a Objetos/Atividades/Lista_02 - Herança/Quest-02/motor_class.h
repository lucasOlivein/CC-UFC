class Motor{
    private:
        int cilindros;
        int potencia;
    public:
        Motor();
        Motor(int, int);

        void setCilindros(int);
        void setPotencia(int);

        int getCilindros();
        int getPotencia();

        void print();


};
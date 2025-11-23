class Tempo{
    private:
        int hora;
        int min;
        int sec;
    public:
        Tempo();
        Tempo(int, int, int);

        void print();

        void subtrair(Tempo, Tempo);
        void somar(Tempo, Tempo);
        /* Tempo somar(Tempo, Tempo); */
};
#pragma once
class Conta{
    private:
        float saldo;

    public:
        Conta(float); // saldo da conta por parametro no construtor

        void mostrar_saldo();
        void credito(float);
        void debito(float); // caso o valor deja maior que o saldo deve se mostrar um erro

        float getSaldo();
        void setSaldo(float);
};



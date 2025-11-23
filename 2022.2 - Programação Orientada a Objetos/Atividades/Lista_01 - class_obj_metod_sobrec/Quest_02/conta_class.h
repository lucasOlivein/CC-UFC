class Conta{
  private:
    float saldo;
  public:
    Conta(float);

    void credito(float);
    void debito(float);

    float getSaldo();
};
class Data{
  private:
    int dia;
    int mes;
    int ano;

  public:
    Data(int, int, int);


    void imprimir();
    static int quantosDiasAte(int);
    static int quantosDiasAte(int);
    static int quantosDiasAte(string);

    void setDia(int dia_); 
    void setMes(int mes_);
    void setAno(int ano_);

    int getAno() const ;
    int getMes() ;
    int getDia() const ;

    int quantosDiasAte(int );

    
    

      
}
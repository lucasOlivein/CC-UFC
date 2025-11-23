class Aluno{
  private:
    string nome;
    string serie;
    string grau;
    static int numeroDeAlunos;

    public:
    
    

      Aluno(string, string, string);
      ~Aluno();

      string getNome() const { return nome; }
      void setNome(const string &nome_) { nome = nome_; }

      string getSerie() const { return serie; }
      void setSerie(const string &serie_) { serie = serie_; }

      string getGrau() const { return grau; }
      void setGrau(const string &grau_) { grau = grau_; }

      static int getNumeroDeAlunos() { return Aluno::numeroDeAlunos; }
      static void setNumeroDeAlunos(int numeroDeAlunos_) { numeroDeAlunos = numeroDeAlunos_; }


      
      
        
};
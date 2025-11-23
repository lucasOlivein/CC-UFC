#include"veiculo_class.h"
class VeiculoAquatico:virtual public Veiculo{
    private:
        string tipo;
        string meio; // mar ou rio 
        bool proa;
        bool mastro;
        bool motor;
        string motor_tipo; // diesel ou gasolina

    public:
        VeiculoAquatico();
        VeiculoAquatico(string, string, string, float, int, int, string, string, bool, bool, bool, string);
        void print();
        /// @brief ////////////
        /// @return ////
        string getTipo() const { return tipo; }
        void setTipo(const string &tipo_) { tipo = tipo_; }

        string getMeio() const { return meio; }
        void setMeio(const string &meio_) { meio = meio_; }

        bool getProa() const { return proa; }
        void setProa(bool proa_) { proa = proa_; }

        bool getMastro() const { return mastro; }
        void setMastro(bool mastro_) { mastro = mastro_; }

        bool getMotor() const { return motor; }
        void setMotor(bool motor_) { motor = motor_; }

        string getMotorTipo() const { return motor_tipo; }
        void setMotorTipo(const string &motorTipo) { motor_tipo = motorTipo; }
        

};
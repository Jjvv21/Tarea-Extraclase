#include <iostream>
using namespace std;

struct Alarma {
    void alarma_encendida()    { cout << "Alarma encendida, casa segura"<<endl; }
    void alarma_apagada() { cout << "Alarma apagada, puedes entrar a casa"<<endl; }
};
struct AireAcondicionado {
    void AireAcondicionado_encendida()    { cout << "Aire encendido"<<endl; }
    void AireAcondicionado_apagada()    { cout << "Aire apagado"<<endl; }
};


struct Tele {
    void Tele_encendida()    { cout << "Tele encendida"<<endl; }
    void Tele_apagada()    { cout << "Tele apagada"<<endl; }
};

struct FachadaDeCasa {

    void ir_al_trabajo() {

        Al.alarma_apagada();
        AA.AireAcondicionado_apagada();
        TV.Tele_apagada();

    }

    void IrCasa() {
        Al.alarma_encendida();
        AA.AireAcondicionado_encendida();
        TV.Tele_encendida();
    }

private:
    Alarma  Al;
    AireAcondicionado      AA;
    Tele      TV;

};

int main() {

    FachadaDeCasa FC;
    // En lugar de llamar a 100 funciones diferentes de encendido y apagado gracias a la fachada, solo tengo 2 funciones
    FC.ir_al_trabajo();
    FC.IrCasa();

    return 0;
}




#include <iostream>
using namespace std;

typedef int Coordinar;
typedef int Dimension;

// Desired interface
class Rectangulo
{
public:
    virtual void dibujar() = 0;
};

// Legacy component
class RectanguloHeredado
{
public:
    RectanguloHeredado(Coordinar x1, Coordinar y1, Coordinar x2, Coordinar y2)
    {
        x1_ = x1;
        y1_ = y1;
        x2_ = x2;
        y2_ = y2;
        cout << "Rectangulo Heredado:  crear.  (" << x1_ << "," << y1_ << ") => ("
             << x2_ << "," << y2_ << ")" << endl;
    }
    void DibujoAntiguo()
    {
        cout << "Rectangulo Heredado:  DibujoAntiguo.  (" << x1_ << "," << y1_ <<
             ") => (" << x2_ << "," << y2_ << ")" << endl;
    }
private:
    Coordinar x1_;
    Coordinar y1_;
    Coordinar x2_;
    Coordinar y2_;
};

// Adapter wrapper
class AdaptadorDeRectangulo: public Rectangulo, private RectanguloHeredado
{
public:
    AdaptadorDeRectangulo(Coordinar x, Coordinar y, Dimension w, Dimension h):
            RectanguloHeredado(x, y, x + w, y + h)
    {
        cout << "Rectangulo Heredado: crear.  (" << x << "," << y <<
             "), ancho = " << w << ", alto = " << h << endl;
    }
    virtual void dibujar()
    {
        cout << "Adaptador De Rectangulo: Dibujar." << endl;
        DibujoAntiguo();
    }
};

int main()
{
    Rectangulo *r = new AdaptadorDeRectangulo(120, 200, 60, 40);
    r->dibujar();
}

#ifndef CREDITO_H
#define CREDITO_H
#include <string>
using std::string;

class Credito
{
public:
    Credito(string = "", string = "",int = 0 );
private:
    string nombre;
    string apellido;
    int codAfiliacion;
};

#endif // CREDITO_H

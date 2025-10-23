#include "Usuario.h"

Usuario::Usuario( string N, string T, string C, string P, string F) {
    nickName = N;
    tipoMembresia = T;
    ciudad = C;
    pais = P;
    fechaInscripcion = F;
}
string Usuario::getNombre(){return nickName;}
string Usuario::getTipo(){return tipoMembresia;}
string Usuario::getCiudad(){return ciudad;}
string Usuario::getPais(){return pais;}
string Usuario::getFecha(){return fechaInscripcion;}

void Usuario::setNombre(string Nom){nickName = Nom;}
void Usuario::setTipo(string Tip){tipoMembresia = Tip;}
void Usuario::setCiudad()(string Ciu){ciudad = Ciu;}
void Usuario::setPais()(string Pa){pais = Pa;}
void Usuario::setFecha()(string Ins){fechaInscripcion = Ins;}

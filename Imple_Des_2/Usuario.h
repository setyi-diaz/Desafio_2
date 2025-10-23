#ifndef USUARIO_H
#define USUARIO_H
#include <string>;
using std::string;
class Usuario
{
public:
    usuario(string = "", string = "", string = "", string = "", string = "");  //constructor predeterminado

    string getNombre();
    string getTipo();
    string getCiudad();
    string getPais();
    string getFecha();
    void setNombre(string);
    void setTipo(string );
    void setCiudad()(string );
    void setPais()(string );
    void setFecha()(string );
private:
    string nickName;
    string tipoMembresia;
    string ciudad;
    string pais;
    string fechaInscripcion;
};

#endif // USUARIO_H

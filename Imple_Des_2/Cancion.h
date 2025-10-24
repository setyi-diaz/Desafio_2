#ifndef CANCION_H
#define CANCION_H

#include <string>
using std::string;

class Credito;  //declaracion anticipada

class Cancion
{
public:
    Cancion(unsigned short = 0, string = "", float  = 0.0, string  = "",
            string  = "", string  = "", Credito& = nullptr,
            Credito& = nullptr, Credito& = nullptr, int = 0);
    unsigned short getIdCancion() const;
    string getNombre()const;
    string getRuta128()const;
    string getRuta320()const;
    float getDuracion()const;
private:
    unsigned short idCancion;
    string nombre;
    float  duracion;
    string rutaAudio128;
    string rutaAudio320;
    string rutaPortadaAlbum;
    Credito& productores;
    Credito& musicos;
    Credito& compositores;
    int vecesReproducida;
};

#endif // CANCION_H

#ifndef CANCION_H
#define CANCION_H

#include <string>
using std::string;

class Credito;  //declaracion anticipada
class Album;

class Cancion
{
public:
    Cancion(unsigned short = 0,
            string = "",
            float  duracion = 0,
            string rutaAudio128 = "",
            string rutaAudio320 = "",
            Credito* = nullptr,
            int = 0,
            Album* = nullptr);
    unsigned short getIdCancion();

private:
    unsigned short idCancion;
    string nombre;
    float  duracion;
    string rutaAudio128;
    string rutaAudio320;
    Credito *creditos;
    int vecesReproducida;
    Album *suAlbum;
};

#endif // CANCION_H

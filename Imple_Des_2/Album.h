#ifndef ALBUM_H
#define ALBUM_H
#include <Cancion.h>
#include <string>
using std::string;

class Album
{
public:
    Album(string [4]= {"","","",""},string = "",string = "",string = "",string = "",
          unsigned short = 0,unsigned short = 0,unsigned short = 0);
    unsigned short getIdAlbum();
private:
    string generos[4];
    string fechaLanzamiento;
    string nombre;
    string sello;
    string portada;
    unsigned short puntuacion;
    unsigned short duracion;
    unsigned short idAlbum;
    Cancion* cancionesAlbum;


};

#endif // ALBUM_H

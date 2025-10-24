#ifndef ALBUM_H
#define ALBUM_H
#include <Cancion.h>
#include <string>
using std::string;

class Album
{
public:
    Album(unsigned short = 0,string = "",string = "" ,
          string = "" ,string = "",unsigned short = 0,unsigned short = 0,string [4] ={"","","",""} ,const Cancion & = nullptr);
    unsigned short getIdAlbum()const;
    string getNombre()const;
    string getPortada()const;
private:
    unsigned short idAlbum;
    string fechaLanzamiento;
    string nombre;
    string selloDisco;
    string portada;
    unsigned short puntuacion;
    unsigned short duracion;
    string generos[4];
    Cancion& cancionesRef;
};

#endif // ALBUM_H

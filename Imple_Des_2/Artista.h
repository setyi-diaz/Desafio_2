#ifndef ARTISTA_H
#define ARTISTA_H
#include <Album.h>
#include <string>
using std::string;

class Artista
{

public:
    Artista(short int = 0,short int = 0,short int = 0,short int = 0,string = "", Album* = nullptr);
    Album* getAlbumes();
    short int getIdArtista();
private:
    short int idArtista;
    short int edad;
    short int cantSeguidores;
    short int posTendencia;
    string pais;
    Album* albumes;

};

#endif // ARTISTA_H

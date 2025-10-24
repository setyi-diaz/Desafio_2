#ifndef ARTISTA_H
#define ARTISTA_H

#include <string>
using std::string;
class Album;

class Artista
{

public:
    Artista(int = 0,unsigned short = 0,string = "",int = 0,unsigned short = 0, Album** = nullptr,int = 0);
    const Album* const* getAlbumesPtr() const;
    short int getIdArtista() const;
    int getCantAlbumes()const;
    void imprimir()const;
private:
    int idArtista;
    unsigned short edad;
    string paisOrigen;
    int cantSeguidores;
    unsigned short posTendencia;
    Album** albumesPtr;
    int cantAlbumPtr;

};

#endif // ARTISTA_H

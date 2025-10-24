#include "Artista.h"

Artista::Artista(int id,unsigned short ed,string pais,int segui,int pos, Album** album, int cant):albumesPtr(album) {
    idArtista = id;
    edad = ed;
    paisOrigen = pais;
    cantSeguidores = segui;
    posTendencia = pos;
    cantAlbumPtr = cant;
}
const Album* const* Artista::getAlbumesPtr() const {
    return albumesPtr;
}
int Artista::getIdArtista() const{
    return idArtista;
}
int Artista::getCantAlbumes() const{
    return cantAlbumPtr;
}
void Artista::imprimir()const{
    cout<<"Cantante: "<<idArtista
}

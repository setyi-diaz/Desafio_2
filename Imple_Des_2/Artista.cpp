#include "Artista.h"

Artista::Artista(Album* A) {
    albumes = A;
}
Album* Artista::getAlbumes(){
    return albumes;
}
short int Artista::getIdArtista(){
    return idArtista;
}

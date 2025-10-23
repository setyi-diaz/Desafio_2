#include "Cancion.h"

Cancion::Cancion() {
    idCancion = setId();
    nombre;
    duracion;
    rutaAudio128;
    rutaAudio320;
    *creditos;
    vecesReproducida;
    *suAlbum=nullptr;
}
Album* Cancion::getAlbum(){
    return suAlbum;
}
unsigned short Cancion::getIdCancion(){
    return idCancion;
}


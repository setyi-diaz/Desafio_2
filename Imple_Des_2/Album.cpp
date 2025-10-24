#include "Album.h"

Album::Album(unsigned short codId,string gen[4]  ,string fecha,string name ,
             string sello ,string port,unsigned short punt,unsigned short dur, const Cancion & ) {
    idAlbum=codId;
    generos[4]=gen;
    fechaLanzamiento=fecha;
    nombre=name;
    selloDisco=sello;
    portada=port;
    puntuacion=punt;
    duracion=dur;
}
unsigned short Album::getIdAlbum(){
    return idAlbum;
}
string Album::getNombre()const{
    return nombre;
}
string Album::getPortada()const{
    return portada;
}

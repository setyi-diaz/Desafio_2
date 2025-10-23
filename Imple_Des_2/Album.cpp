#include "Album.h"

Album::Album(string g[4],string f,string n,string s,string por,
             unsigned short d,unsigned short id,unsigned short pun) {
    generos[4]=g;
    fechaLanzamiento=f;
    nombre=n;
    sello=s;
    portada=por;
    puntuacion=pun;
    duracion=d;
    idAlbum=id;
}
unsigned short Album::getIdAlbum(){
    return idAlbum;
}

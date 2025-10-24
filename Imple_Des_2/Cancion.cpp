#include "Cancion.h"

Cancion::Cancion(unsigned short id, string nom, float  dura, string  ruta1,
                 string  ruta2, string  ruta3,const Credito &prod,
                 const Credito &mus, const Credito &comp, int cont)
                 : productores(prod),musicos(mus),compositores(comp)
{
    idCancion = id;
    nombre = nom;
    duracion = dura;
    rutaAudio128 = ruta1;
    rutaAudio320 = ruta2;
    rutaPortadaAlbum = ruta3;
    vecesReproducida = cont;
}
unsigned short Cancion::getIdCancion(){
    return idCancion;
}
string Cancion::getNombre()const{
    return nombre;
}
string Cancion::getRuta128()const{
    return rutaAudio128;
}
string Cancion::getRuta320()const{
    return rutaAudio320;
}
float Cancion::getDuracion()const{
    return duracion;
}

#ifndef PLATAFORMA_H
#define PLATAFORMA_H

#include <iostream>
#include <limits>
#include <fstream>
#include <random>
#include <chrono>
#include <string>
#include "Usuario.h"
#include "Artista.h"
#include "Album.h"
#include "Cancion.h"
#include "Anuncio.h"
using namespace std;

class Plataforma
{
private:
    Usuario* usuarios;
    Artista* artistas;
    Album* albumes;
    Cancion* canciones;
    Anuncio* anuncios;

    unsigned int contArtistas,contAlbumes,contCanciones;

    bool cargarUsuarios();
    bool cargarArtistas();
    bool cargarAlbumes();
    bool cargarCanciones();
    bool cargarAnuncios();
    Cancion* seleccionarCancionAleatoria();
    Anuncio* seleccionarAnuncioAleatorio();
    int buscarArtista(Cancion&);
    Album* buscarAlbum(Cancion& , int);
public:
    //constructor predeterminado
    Plataforma(Usuario* = nullptr,Artista* = nullptr,
               Album* = nullptr,Cancion* = nullptr,
               Anuncio* = nullptr);
    ~Plataforma();
    bool cargarDatos();
    bool guardarDatos();
    Usuario* iniciarSesion();
    void reproducirAleatoria(Usuario* user);
    void menuFavoritos(Usuario* user);
    void mostrarEstadisticas();
    void liberarMemoria();
private:

    //sobre cargar operador !
};

#endif // PLATAFORMA_H

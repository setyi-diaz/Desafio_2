#ifndef PLATAFORMA_H
#define PLATAFORMA_H

#include <iostream>
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
    bool cargarUsuarios();
    bool cargarArtistas();
    bool cargarAlbumes();
    bool cargarCanciones();
    bool cargarAnuncios();
    Cancion* seleccionarCancionAleatoria();
    Anuncio* seleccionarAnuncioAleatorio();
    //sobre cargar operador !
};

#endif // PLATAFORMA_H

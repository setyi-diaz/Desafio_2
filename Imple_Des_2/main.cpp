#include <iostream>
#include "Plataforma.h"
using namespace std;

int main()
{
    Plataforma udeaTunes;
    if(!udeaTunes.cargarDatos()){
        cerr<<"No se pudo cargar los archivos";
        exit(1);
    }
    bool continuar1 = true;
    bool verificado = false;
    short int opcion1;
    while (continuar1) {
        cout<<"_______________Bienvenido a UdeaTunes___________\n";
        do{
        Usuario* usuarioActual = udeaTunes.iniciarSesion();
        if(usuarioActual==nullptr){
            cout<<"Usuario no encontrado\n";
            cout<<"Intente de nuevo\n";
        }
        else{verificado = true;}
        }while(!verificado);
        bool continuar2 = true;
        short int opcion2;
        while(continuar2){
            cout<<"Menu principal\n";
            cout<<"1. Reproducir canciones aleatorias de UdeaTunes\n";
            cout<<"0. Cerrar sesion \n";
            cin>>opcion2;
            switch (opcion2) {
            case 1:
                udeaTunes.reproducirAleatoria(usuarioActual);
                break;
            case 0:
                cout<<"Cerrando sesion...\n\n";
                continuar2 = false;
                break;
            default:
                break;
            }
        }
    }
    return 0;
}

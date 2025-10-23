#include "Plataforma.h"

Plataforma::Plataforma() {
    usuarios = nullptr;
    artistas = nullptr;
    albumes = nullptr;
    canciones = nullptr;
    anuncios = nullptr;
}
bool Plataforma::cargarDatos(){
    if (!cargarUsuarios()) return false;
    if (!cargarArtistas()) return false;
    if (!cargarAlbumes()) return false;
    if (!cargarCanciones()) return false;
    if (!cargarAnuncios()) return false;
    return true;
}

bool Plataforma::cargarUsuarios(){
    ifstream archivoUsuariosEntrada("usuarios.txt",ios::in);
    if(!archivoUsuariosEntrada){
        cerr<<"No se pudo abrir archivo de artistas";
        return false;
    }
    int contador = 0;
    string linea;
    while (getline(archivoUsuariosEntrada, linea)) contador++;
    archivoUsuariosEntrada.clear();
    archivoUsuariosEntrada.seekg(0);

    usuarios = new Usuario[contador];
    string nickName;
    string tipoMembresia;
    string ciudad;
    string pais;
    string fechaInscripcion;
    for (int i = 0; i < contador; i++) {
        archivoUsuariosEntrada >> nickName >> tipoMembresia >> ciudad >> pais >> fechaInscripcion;
        usuarios[i] = Usuario(idArtista, edad, cantSeguidores, posTendencia, pais);
    }
    archivoUsuariosEntrada.close();
    return true;
}
bool Plataforma::cargarArtistas(){
    ifstream archivoArtistasEntrada("artistas.txt",ios::in);
    if(!archivoArtistasEntrada){
        cerr<<"No se pudo abrir archivo de artistas";
        return false;
    }
    int contador = 0;
    string linea;
    while (getline(archivoArtistasEntrada, linea)) contador++;
    archivoArtistasEntrada.clear();
    archivoArtistasEntrada.seekg(0);

    artistas = new Artista[contador];
    short int idArtista;
    short int edad;
    short int cantSeguidores;
    short int posTendencia;
    string pais;
    for (int i = 0; i < cantArtistas; i++) {
        archivoArtistasEntrada >> idArtista >> edad >> cantSeguidores >> posTendencia >> pais;
        artistas[i] = new Artista(idArtista, edad, cantSeguidores, posTendencia, pais);
    }
    archivoArtistasEntrada.close();
    return true;
}
Usuario* Plataforma::iniciarSesion(){
    string nombre;
    cout << "Ingrese su nickname: ";
    cin >> nombre;

    for (int i = 0; i < cantUsuarios; i++) {
        if (usuarios[i].getNombre() == nombre) {
            cout << "Bienvenido " << nombre << "!" << endl;
            return usuarios[i];
        }
    }

    cout << "Usuario no encontrado.\n";
    return nullptr;
}

void Plataforma::reproducirAleatoria(Usuario* user){
    short int idArtista = 0;
    do{
        bool detener=false;
        while(detener==false){

            auto inicio = std::chrono::high_resolution_clock::now();
            auto fin = std::chrono::high_resolution_clock::now();
            Cancion* cancionActual = seleccionarCancionAleatoria();
            idArtista =(cancionActual->getIdCancion())/1000;
            for (int i = 0; i < cantArtistas; i++){
                if (artistas[i].getIdArtista()==idArtista){
                    for (int j = 0; j < cantAlbumes; i++){
                        Album* album = artistas[i].getAlbumes();
                        if(album->getIdAlbum()==idAlbum){
                            mostrar();
                        }
                    }
                }
            }
        }
    }while();
}
Cancion* Plataforma::seleccionarCancionAleatoria(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 10000);
    int ind = dist(gen);
    return *Canciones[ind];
}


















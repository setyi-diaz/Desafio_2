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
        usuarios[i] = Usuario(nickName, tipoMembresia, ciudad, pais, fechaInscripcion);
    }
    archivoUsuariosEntrada.close();
    return true;
}
bool Plataforma::cargarArtistas(){
    ifstream archivoArtistasEntrada("artistas.txt",ios::in);
    ifstream archivoAlbumesEntrada("albumes.txt",ios::in);
    ifstream archivoCancionesEntrada("canciones.txt",ios::in);
    if(!archivoArtistasEntrada ||!archivoAlbumesEntrada || !archivoCancionesEntrada ){
        cerr<<"No se pudo abrir archivo de artistas, albumes o canciones";
        return false;
    }

    int contArtistas = 0;
    string linea;
    while (getline(archivoArtistasEntrada, linea)) contArtistas++;
    archivoArtistasEntrada.clear();
    archivoArtistasEntrada.seekg(0);
    artistas = new Artista[contArtistas];

    int contAlbumes = 0;
    linea = "";
    while (getline(archivoAlbumesEntrada, linea)) contAlbumes++;
    archivoAlbumesEntrada.clear();
    archivoAlbumesEntrada.seekg(0);
    albumes = new Album[contAlbumes];

    int contCanciones = 0;
    linea = "";
    while (getline(archivoCancionesEntrada, linea)) contCanciones++;
    archivoCancionesEntrada.clear();
    archivoCancionesEntrada.seekg(0);
    canciones = new Cancion[contCanciones];

    int idCancion;
    string nombre;
    float  duracion;
    string rutaAudio128;
    string rutaAudio320;
    string rutaPortadaAlbum;
    int vecesReproducida;
    short int edad;
    short int cantSeguidores;
    short int posTendencia;
    string pais;

    for (int i = 0; i < contCanciones; i++) {
        archivoCancionesEntrada >> idCancion >> nombre >> duracion >>rutaAudio128 >> rutaAudio320>>rutaPortadaAlbum
            >>vecesReproducida;
        artistas[i] = Cancion(idCancion, nombre, duracion, rutaAudio128,
                              rutaAudio320, rutaPortadaAlbum,nullptr,nullptr,nullptr, vecesReproducida);
        int idArt = idCancion/10000;
        unsigned short idAlbum = (idCancion/100)%100;
        for(int j = 0; j<contAlbumes;j++){
            archivoAlbumesEntrada >> idAlbum >> edad >> cantSeguidores >>posTendencia >> pais;
        }
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
    Cancion* historial[4] = {nullptr, nullptr, nullptr, nullptr};
    short totalHistorial = 0;
    short indiceActual = -1;
    bool salir=false;
    bool previa=false;
    char tecla='';
    char opcion;
    Cancion* cancionActual=nullptr;

    while(salir==false){
        if(previa==true){
            cancionActual = historial[indiceActual];
            previa = false;
        }
        else{
            cancionActual = seleccionarCancionAleatoria();
        }
        unsigned int idArt = buscarArtista(*cancionActual);
        if(idArt != 99999)
            cout<<"Cantante: "<<idArt<<endl;
        else if (idArt == 99999){
            cout<<"Cantante: No encontrado"<<endl;
        }
        const Album* albumPtr = buscarAlbum(*cancionActual,idArt);
        if (albumPtr != nullptr){
            cout<<"Album: "<<albumPtr->getNombre()<<endl;
            cout<<"Ruta a la portada del album: "<<albumPtr->getPortada()<<endl;
            cout<<"Nombre Cancion: "<<cancionActual->getNombre()<<endl;
        }
        else if(albumPtr == nullptr){
            cout<<"Album: "<<"No encontrado"<<endl;
            cout<<"Ruta a la portada del album: "<<"No encotrada"<<endl;
            cout<<"Nombre Cancion: "<<cancionActual->getNombre()<<endl;
        }
        if (user->getTipo()=="estandar"){
            cout<<"Ruta archivo de audio: "<<cancionActual.getRuta128()<<endl;
            cout<<"Duracion "<<cancionActual.getDuracion()<<endl;
        }
        else if (user->getTipo()=="premium"){
            cout<<"Ruta archivo de audio: "<<cancionActual.getRuta320()<<endl;
            cout<<"Duracion "<<cancionActual.getDuracion()<<endl;
        }
        if(user->getTipo()=="premium"){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"\n1.Detener    2.Continuar   3.Siguiente   4.Previa"<<endl;

            if (_kbhit()) {
                tecla = _getch();
                if (tecla == '1') {
                    cout<<"\n\n\n============================================================";
                    cout<<"\n                   Reproduccion detenida";
                    cout<<"\n============================================================";
                    cout<<"\n2.Continuar    3.Siguiente   4.Previa    0.Salir del reproductor";
                    cin>>opcion;
                    if (opcion=='0'){
                        salir=true;
                    }
                    else if (opcion=='4'){
                        if (indiceActual > 0)
                            indiceActual--;
                        else
                            cout << "Ya estás en la primera canción del historial.\n";
                        previa=true;
                    }
                }
            }
        }
        else if(user->getTipo()=="estandar"){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"\n1.Detener    2.Continuar   0.Salir del reproductor";
            if (_kbhit()) {
                tecla = _getch();
                if (tecla == '1') {
                    cout<<"============================================================";
                    cout<<"                   Reproduccion detenida";
                    cout<<"============================================================";
                    cout<<"2.Continuar    0.Salir del reproductor";
                    cin>>opcion;
                    if (opcion=='0'){
                        salir=true;
                    }
                }
            }
        }
        if(opcion=='2'){std::this_thread::sleep_for(std::chrono::seconds(5));}
        if (!previa) {
            if (totalHistorial == 4) {
                for (int i = 0; i < 3; i++)
                    historial[i] = historial[i + 1];
                historial[3] = cancionActual;
            } else {
                historial[totalHistorial] = cancionActual;
                totalHistorial++;
            }
            indiceActual = totalHistorial - 1;
        }
    }

}
unsigned int Plataforma::buscarArtista(Cancion* play ){
    int idArtista = (play->getIdCancion())/1000;

    for (int i = 0; i < contArtistas; i++){
        if (artistas[i].getIdArtista()==idArtista){
            return artistas[i].getIdArtista();
        }
    }
    return 99999;
}
const Album* Plataforma::buscarAlbum(Cancion* play, int id){
    unsigned short idAlbum = (play->getIdCancion()/100)%100;;
    const Album* const* albums = artistas[id].getAlbumesPtr();
    int cantAlbums=artistas[id].getCantAlbumes();
    for (int j = 0; j < cantAlbums; j++){
        if(albums[j]->getIdAlbum()==idAlbum){
            return albums[j];
        }
    }
    return nullptr;
}
const Cancion* Plataforma::seleccionarCancionAleatoria(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, contCanciones);
    int ind = dist(gen);
    return &Canciones[ind];
}


















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
    short int opcion1=2;
    short int opcion2=3;
    do{
        Cancion* cancionActual=nullptr;
        while(opcion1==2 || opcion2==3){

            cancionActual = &seleccionarCancionAleatoria();
            unsigned int idArt = buscarArtista(*cancionActual);
            if(idArt != 99999)
                cout<<"Cantante: "<<idArt<<endl;
            else if (idArt == 99999){
                cout<<"Cantante: "<<"No encontrado";<<endl;
            }
            const Album* albumPtr = buscarAlbum(*cancionActual,idArt);
            if (albumPtr != nullptr){
                cout<<"Album: "<<albumPtr->getNombre()<<endl;
                cout<<"Ruta a la portada del album: "<<albumPtr->getPortada()<<endl;
                cout<<"Nombre Cancion: "<<cancionActual.getNombre()<<endl;
            }
            else if(albumPtr == nullptr){
                cout<<"Album: "<<"No encontrado"<<endl;
                cout<<"Ruta a la portada del album: "<<"No encotrada"<<endl;
                cout<<"Nombre Cancion: "<<cancionActual.getNombre()<<endl;
            }
            if (user->getTipo()=="estandar"){
                cout<<"Ruta archivo de audio: "<<cancionActual.getRuta128()<<endl;
                cout<<"Duracion "<<cancionActual.getDuracion()<<endl;
            }
            else if (user->getTipo()=="premium"){
                cout<<"Ruta archivo de audio: "<<cancionActual.getRuta320()<<endl;
                cout<<"Duracion "<<cancionActual.getDuracion()<<endl;
            }
            if(user->getTipo()=="estandar"){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"1.Detener"<<"     "<<"2.Reproducir"<<"      "<<"3.Siguiente"<<endl;
                cout<<"4.Previa";
                cin>>opcion2;
            }
            else if(user->getTipo()=="premium"){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"1.Detener"<<"     "<<"2.Reproducir"<<"      "<<"0.Salir del reproductor";
                cin>>opcion1;
            }
            if (opcion1 == 2 || opcion2 == 2){std::this_thread::sleep_for(std::chrono::seconds(3));}
        }
        cout<<"Reproduccion detenida";
        cout<<"2.Reproducir"<<"      "<<"0.Salir del reproductor";
        cin>>opcion1;

    }while(opcion1!=0);
}
unsigned int Plataforma::buscarArtista(Cancion* play ){
    int idArtista = (play.getIdCancion())/1000;

    for (int i = 0; i < contArtistas; i++){
        if (artistas[i].getIdArtista()==idArtista){
            return artistas[i].getIdArtista();
        }
    }
    return 99999;
}
const Album* Plataforma::buscarAlbum(const Cancion& play, int id){
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
const Cancion Plataforma::seleccionarCancionAleatoria(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 10000);
    int ind = dist(gen);
    return Canciones[ind];
}


















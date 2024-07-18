#include "Video.h"

class Pelicula : public Video
{
private:
    string getTipoVideo();

public:
    Pelicula();
    Pelicula(string id, string nombre, string duracion, string genero);
};
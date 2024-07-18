#include "Episodio.h"
#include "Video.h"

#include <list>

using namespace std;

class Serie : public Video
{
private:
    list<Episodio> episodios;
    int numEpisodios;

protected:
    void datosToString();

public:
    Serie();
    Serie(string id, string nombre, string genero, list<Episodio> episodios);
    void agregarEpisodio(Episodio aAgregar);
    void mostrarEpisodios();
    string getTipoVideo();
};
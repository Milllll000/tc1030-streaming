#include "Episodio.h"
#include "Video.h"

#include <vector>

using namespace std;

class Serie : public Video
{
private:
    vector<Episodio> episodios;

public:
    Serie();
    Serie(vector<Episodio> episodios);
    void agregarEpisodio();
    void mostrarEpisodios();
};
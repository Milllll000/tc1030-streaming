#include "Video.h"

class Episodio : public Video 
{
private:
    int continuidad;

protected:
    void datosToString();

public:
    Episodio();
    string getTipoVideo();
};
#pragma once
#include "Video.h"

class Episodio : public Video 
{
private:
    int continuidad;

private:
    void datosToString();

public:
    Episodio();
    Episodio(string nombre, string id, string duracion, int continuidad);
    string getTipoVideo();
};
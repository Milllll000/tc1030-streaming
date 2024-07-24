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
    string getTipoVideo();
};
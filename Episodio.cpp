#include "Episodio.h"

#include <iostream>

using namespace std;

void Episodio::datosToString()
{
    // Convierte los datos del video a string para poder mostrarse en pantalla y guardar
    // en un archivo de texto
    datosString = id + "\t" + nombre + "\t" + duracion + "\t" + genero + "\t" + getTipoVideo() + "\t" + to_string(continuidad) + "\t" + to_string(califiacionPromedio);
}

Episodio::Episodio() : Video()
{
    // Valores default del constructor
    continuidad = 0;
    datosToString();
}

string Episodio::getTipoVideo()
{
    return "Episodio";
}

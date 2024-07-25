#include "Serie.h"
#include <iostream>

void Serie::datosToString()
{
    // Convierte los datos del video a string para poder mostrarse en pantalla y guardar
    // en un archivo de texto
    datosString = id + "\t" + nombre + "\t" + genero + "\t" + getTipoVideo() + "\t" + to_string(numEpisodios) + "\t" + to_string(califiacionPromedio);
}

Serie::Serie() : Video()
{
    // Valores default del constructor
    nombre = "Potato";
    numEpisodios = 0;
    datosToString();
}

Serie::Serie(string id, string nombre, string genero) : Video()
{
    this->id = id;
    this->nombre = nombre;
    this->genero = genero;
    califiacionPromedio = calcularPromedio();
    numEpisodios = this->episodios.size();
    datosToString();
}

list<Episodio *> Serie::getEpisodios()
{
    return episodios;
}

void Serie::agregarEpisodio(Episodio agregar)
{
    episodios.push_back(&agregar);
}

void Serie::mostrarEpisodios()
{
    list<Episodio *>::iterator it;
    // while (aux != episodios.end())
    // {
    //     (*aux)->mostrarVideo();
    //     aux++;
    // }
    for (it = episodios.begin(); it != episodios.end(); it++)
    {
        (*it)->mostrarVideo();
    }
}

string Serie::getTipoVideo()
{
    return "Serie";
}

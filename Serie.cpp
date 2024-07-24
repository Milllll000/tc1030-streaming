#include "Serie.h"

void Serie::datosToString()
{
    // Convierte los datos del video a string para poder mostrarse en pantalla y guardar
    // en un archivo de texto
    datosString = id + "\t" + nombre + "\t" + genero + "\t" + getTipoVideo() + "\t" + to_string(numEpisodios) + "\t" + to_string(califiacionPromedio);
}

Serie::Serie() : Video()
{
    // Valores default del constructor
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

void Serie::agregarEpisodio(Episodio agregar)
{
    episodios.push_back(&agregar);
}

void Serie::mostrarEpisodios()
{
    list<Episodio *>::iterator aux = episodios.begin();
    while (*aux != nullptr)
    {
        (*aux)->mostrarVideo();
    }
}

string Serie::getTipoVideo()
{
    return "Serie";
}

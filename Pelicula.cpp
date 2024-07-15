#include "Pelicula.h"
#include "Video.h"

Pelicula::Pelicula() : Video()
{
    id = "0000";
    califiacionPromedio = calcularPromedio();
    nombre = "Provisional";
    duracion = "00:00";
    genero = "Genero";
    datosToString();
}

Pelicula::Pelicula(string id, string nombre, string duracion, string genero)
{
    this->id = id;
    this->nombre = nombre;
    this->duracion = duracion;
    this->genero = genero;
    califiacionPromedio = calcularPromedio();
    datosToString();
}

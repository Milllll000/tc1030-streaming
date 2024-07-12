#include "Video.h"

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

float Video::calcularPromedio()
{
    int numCalif = calificaciones.size();
    float sumaCalif = 0;

    if (numCalif == 0)
    {
        return 0.0f;
    }

    for (int i = 0; i < numCalif; ++i)
    {
        sumaCalif += calificaciones[i];
    }

    return sumaCalif/numCalif;
}

// Constructores
Video::Video()
{
    id = 0000;
    califiacionPromedio = calcularPromedio();
    nombre = "Provisional";
    duracion = "00:00";
    genero = "Genero";
    cout << "Constructor called" << endl;
}

Video::Video(int id, string nombre, string duracion, string genero)
{
    this->id = id;
    this->nombre = nombre;
    this->duracion = duracion;
    this->genero = genero;
    califiacionPromedio = calcularPromedio();
    cout << "Constructor called" << endl;
}

// Getters
int Video::getID()
{
    return id;
}

float Video::getCalificacionPromedio()
{
    return califiacionPromedio;
}

string Video::getNombre()
{
    return nombre;
}

string Video::getDuracion()
{
    return duracion;
}

string Video::getGenero()
{
    return genero;
}

vector<float> Video::getCalificaciones()
{
    return calificaciones;
}

string Video::getTipoVideo()
{
    return "Soy video generico";
}

// Setters
void Video::setID(int id)
{
    this->id = id;
}

void Video::setNombre(string nombre)
{
    this->nombre = nombre;
}

void Video::setDuracion(string duracion)
{
    this->duracion = duracion;
}

void Video::setGenero(string genero)
{
    this->genero = genero;
}

// Métodos especializados
void Video::mostrarVideo()
{
    cout << nombre + "\t" << duracion + "\t" << genero + "\t"<< getTipoVideo() + "\t" << setprecision(3) << califiacionPromedio << endl;
}

void Video::agregarCalificacion(float calificacion)
{
    calificaciones.push_back(calificacion);
    califiacionPromedio = calcularPromedio();
}

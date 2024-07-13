#include "Video.h"

#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

float Video::calcularPromedio()
{
    // Almacena la cantidad de calificaciones almacenadas
    int numCalif = calificaciones.size();
    // Variable para obtener la suma de todas las calificaciones
    float sumaCalif = 0;

    // Si no hay ninguna calificación, el promedio es 0
    if (numCalif == 0)
    {
        return 0.0f;
    }

    // Se almacena el acumulado de todas las calificaciones almacenadas
    for (int i = 0; i < numCalif; ++i)
    {
        sumaCalif += calificaciones[i];
    }

    // Regresa el promedio
    return sumaCalif/numCalif;
}

// Se usa para actualizar los datos almacenados como string
void Video::datosToString()
{
    // Convierte los datos del video a string para poder mostrarse en pantalla y guardar
    // en un archivo de texto
    datosString = id + "\t" + nombre + "\t" + duracion + "\t" + genero + "\t" + getTipoVideo() + "\t" + to_string(califiacionPromedio);
}

// Constructores
Video::Video()
{
    // Valores default del constructor
    id = "0000";
    califiacionPromedio = calcularPromedio();
    nombre = "Provisional";
    duracion = "00:00";
    genero = "Genero";
    datosToString();
}

Video::Video(string id, string nombre, string duracion, string genero)
{
    // Inicializa los miembros de la clase con los datos dados
    this->id = id;
    this->nombre = nombre;
    this->duracion = duracion;
    this->genero = genero;
    califiacionPromedio = calcularPromedio();
    datosToString();
}

// Getters
string Video::getID()
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

string Video::getDatosString()
{
    return datosString;
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
void Video::setID(string id)
{
    this->id = id;
    datosToString();
}

void Video::setNombre(string nombre)
{
    this->nombre = nombre;
    datosToString();
}

void Video::setDuracion(string duracion)
{
    this->duracion = duracion;
    datosToString();
}

void Video::setGenero(string genero)
{
    this->genero = genero;
    datosToString();
}

// Métodos especializados
void Video::mostrarVideo()
{
    // Muestra los datos del video en pantalla
    cout << datosString << endl;
}

void Video::agregarCalificacion(float calificacion)
{
    // Agrega la calificación dada al vector de calificaciones
    calificaciones.push_back(calificacion);
    // Redondea el promedio a dos decimales 
    califiacionPromedio = ceil(calcularPromedio() * 100) / 100;
    // Actualiza los datos en string
    datosToString();
}

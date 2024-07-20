#include "Sistema.h"

#include <fstream>
#include <iostream>

using namespace std;

Sistema::Sistema()
{

}

void Sistema::mostrarPorCalificacion(float calif)
{
    if (peliculas.size() == 0)
    {
        cout << "¡No hay películas!" << endl;
    }
    else
    {
        for (int i=0; i<peliculas.size(); ++i)
        {
            peliculas[i].mostrarVideo();
        }
    }
    
    if (series.size() == 0)
    {
        cout << "¡No hay series!" << endl;
    }
    else
    {
        for (int i=0; i<series.size(); ++i)
        {
            series[i].mostrarVideo();
        }
    }
}

void Sistema::mostrarPorGenero(string genero)
{
}

void Sistema::cargarArchivo(string direccion)
{
    ifstream archivo;
    string linea;
    archivo.open(direccion);

    while(getline(archivo, linea))
    {
        cout << linea << endl;
    }

    archivo.close();    
}

void Sistema::calificar()
{
}

void Sistema::guardarAArchivo(string direccion, string datos)
{
    ofstream archivo;
    string linea;

    archivo.open(direccion, ios::app);
    archivo << datos << endl;
    archivo.close();
}

void Sistema::guardarPelicula(Pelicula &pelicula)
{
    peliculas.push_back(pelicula);
}

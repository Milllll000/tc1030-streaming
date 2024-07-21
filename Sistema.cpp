#include "Sistema.h"

#include <fstream>
#include <iostream>

using namespace std;

vector<Pelicula *> Sistema::getVideoCalif(float calif)
// Busca la película que tiene la calificación solicitada o mayor
// calif debe de ser igual o mayor a 0
{
    cout << "Función se llama" << endl;
    vector<Pelicula *> cumplen;
    for (int i=0; i<peliculas.size(); ++i)
    {
        cout << "Loop inicia" << endl;
        // Si la pelicula cumple la condición, se agrega al vector
        if (peliculas[i].getCalificacionPromedio() >= calif)
        {
            cout << "Cumple condición" << endl;
            cumplen.push_back(&peliculas[i]);
        }
    }
    cout << "Loop finaliza" << endl;
    cout << "Función finaliza" << endl;

    return cumplen;
}

Sistema::Sistema()
{

}

void Sistema::mostrarPorCalificacion(float calif)
{
    vector <Pelicula *> cumplenPel = getVideoCalif(calif);
    vector <Pelicula *> cumplenSer;
    
    if (peliculas.size() > 0 && cumplenPel.size() > 0)
    {
        cout << "Sí hay películas." << endl;
        
        for (int i=0; i<cumplenPel.size(); ++i)
        {
            if (cumplenPel[i]->getCalificacionPromedio() >= calif)
            {
                cumplenPel[i]->mostrarVideo();
            }
        }
    }
    else
    {
        cout << "¡No hay películas!" << endl;
    }
    
    if (series.size() > 0 && cumplenSer.size() > 0)
    {
        cout << "Sí hay series." << endl;
        
        for (int i=0; i<cumplenSer.size(); ++i)
        {
            if (cumplenSer[i]->getCalificacionPromedio() >= calif)
            {
                cumplenSer[i]->mostrarVideo();
            }
        }
    }
    else
    {
        cout << "¡No hay películas!" << endl;
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

void Sistema::guardarASistema(Pelicula &pelicula)
{
    peliculas.push_back(pelicula);
}

void Sistema::guardarASistema(Serie &serie)
{
    series.push_back(serie);
}

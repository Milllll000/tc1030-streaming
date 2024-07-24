#include "Sistema.h"

#include <fstream>
#include <iostream>
#include <stdexcept>

using namespace std;

vector<Video *> Sistema::getVideo(float calif)
// Busca la película que tiene la calificación solicitada o mayor
// calif debe de ser igual o mayor a 0
{
    cout << "Función se llama" << endl;
    vector<Video *> cumplen;
    
    // Para películas
    for (int i=0; i<peliculas.size(); ++i)
    {
        cout << "Loop inicia" << endl;
        // Si el video cumple la condición, se agrega al vector
        if (peliculas[i]->getCalificacionPromedio() >= calif)
        {
            cout << "Cumple condición" << endl;
            cumplen.push_back(peliculas[i]);
        }
    }
    // Para series
    for (int i=0; i<series.size(); ++i)
    {
        cout << "Loop inicia" << endl;
        // Si el video cumple la condición, se agrega al vector
        if (series[i]->getCalificacionPromedio() >= calif)
        {
            cout << "Cumple condición" << endl;
            cumplen.push_back(series[i]);
        }
    }

    cout << "Loop finaliza" << endl;
    cout << "Función finaliza" << endl;

    return cumplen;
}

vector<Video *> Sistema::getVideo(string genero)
// Busca el contenido que coincida con el género solicitado
// genero debe de ser uno de ser o "Acción", o "Comedia", o "Misterio", o "Musical", o "Terror"
{
    cout << "Función se llama" << endl;
    vector<Video *> cumplen;

    // Para películas
    for (int i=0; i<peliculas.size(); ++i)
    {
        cout << "Loop inicia" << endl;
        // Si el video cumple la condición, se agrega al vector
        if (peliculas[i]->getGenero() == genero)
        {
            cout << "Cumple condición" << endl;
            cumplen.push_back(peliculas[i]);
        }
    }
    // Para series
    for (int i=0; i<series.size(); ++i)
    {
        cout << "Loop inicia" << endl;
        // Si el video cumple la condición, se agrega al vector
        if (series[i]->getGenero() == genero)
        {
            cout << "Cumple condición" << endl;
            cumplen.push_back(series[i]);
        }
    }
    cout << "Loop finaliza" << endl;
    cout << "Función finaliza" << endl;

    return cumplen;
}

vector<Pelicula *> Sistema::getPeliculas()
{
    return peliculas;
}

vector<Serie *> Sistema::getSeries()
{
    return series;
}

void Sistema::imprimir(vector<Video *> seleccionado)
{
    if (seleccionado.size() > 0)
    {
        cout << "Sí hay videos." << endl;
        
        for (int i=0; i<seleccionado.size(); ++i)
        {
            seleccionado[i]->mostrarVideo();
        }
    }
    else
    {
        cout << "¡No hay videos!" << endl;
    }
}

void Sistema::imprimir(vector<Pelicula *> seleccionado)
{
    if (seleccionado.size() > 0)
    {
        cout << "Sí hay películas." << endl;
        
        for (int i=0; i<seleccionado.size(); ++i)
        {
            seleccionado[i]->mostrarVideo();
        }
    }
    else
    {
        cout << "¡No hay películas!" << endl;
    }
}

void Sistema::imprimir(vector<Serie *> seleccionado)
{
    if (seleccionado.size() > 0)
    {
        cout << "Sí hay series." << endl;
        
        for (int i=0; i<seleccionado.size(); ++i)
        {
            seleccionado[i]->mostrarVideo();
        }
    }
    else
    {
        cout << "¡No hay series!" << endl;
    }
}

Sistema::Sistema()
{
    
}

void Sistema::mostrarPorCalificacion(float calif)
{
    vector <Video *> cumplen = getVideo(calif);

    
    if (cumplen.size() > 0)
    {
        cout << "Sí hay películas." << endl;
        
        for (int i=0; i<cumplen.size(); ++i)
        {
            if (cumplen[i]->getCalificacionPromedio() >= calif)
            {
                cumplen[i]->mostrarVideo();
            }
        }
    }
    else
    {
        cout << "¡No hay videos!" << endl;
    }
}

void Sistema::mostrarPorGenero(char genero)
// Muestra los videos de acuerdo al género escogido
// genero sólo puede ser o 1, o 2, o 3, o 4, o 5
{
    // Variable para almacenar el género escogido
    string escogido;
    vector <Video *> cumplen;

    switch (genero)
    {
    case '1':
        escogido = "Acción";
        break;
    case '2':
        escogido = "Comedia";
        break;
    case '3':
        escogido = "Misterio";
        break;
    case '4':
        escogido = "Musical";
        break;
    case '5':
        escogido = "Terror";
        break;
    default:
        throw invalid_argument("Sólo se puede escoger entre 1, 2, 3, 4 o 5.");
        break;
    }

    // Donde cumplen son todos los videos que cumplen con la condición
    cumplen = getVideo(escogido);
    imprimir(cumplen);
}

void Sistema::mostrarPorTIpo(char tipo)
{
    // tipo debe de ser o '1' para películas, o '2' para series
    vector<Pelicula *>pelEscogidas;
    vector<Serie *>serEscogidas;

    switch (tipo)
    {
    case '1':
        pelEscogidas = getPeliculas();
        imprimir(pelEscogidas);
        break;
    case '2':
        serEscogidas = getSeries();
        imprimir(serEscogidas);
        break;
    default:
        throw invalid_argument("Sólo se puede escoger entre 1 o 2.");
        break;    
    }
}

void Sistema::mostrarEpisodios(string id)
{
    // Busca todas las series almacenadas
    vector<Serie *> series;
    vector<Serie *>::iterator it;
    series = getSeries();

    for (it = series.begin(); (*it)!=nullptr; it++)
    {
        if ((*it)->getID() == id)
        {
            (*it)->mostrarVideo();
            (*it)->mostrarEpisodios();
            
        }
    }
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
    peliculas.push_back(&pelicula);
}

void Sistema::guardarASistema(Serie &serie)
{
    series.push_back(&serie);
}

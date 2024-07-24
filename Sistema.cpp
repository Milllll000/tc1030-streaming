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
    for (int i=0; i<videos.size(); ++i)
    {
        cout << "Loop inicia" << endl;
        // Si el video cumple la condición, se agrega al vector
        if (videos[i]->getCalificacionPromedio() >= calif)
        {
            cout << "Cumple condición" << endl;
            cumplen.push_back(videos[i]);
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
    for (int i=0; i<videos.size(); ++i)
    {
        cout << "Loop inicia" << endl;
        // Si el video cumple la condición, se agrega al vector
        if (videos[i]->getGenero() == genero)
        {
            cout << "Cumple condición" << endl;
            cumplen.push_back(videos[i]);
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
    vector <Video *> cumplen = getVideo(calif);
    // vector <Video *> cumplenSer;

    
    if (videos.size() > 0 && cumplen.size() > 0)
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
        throw invalid_argument("Sólo se puede escoger entre 1, 2, 3, 4 o 5");
        break;
    }

    cumplen = getVideo(escogido);
    
    if (videos.size() > 0 && cumplen.size() > 0)
    {
        cout << "Sí hay películas." << endl;
        
        for (int i=0; i<cumplen.size(); ++i)
        {
            cumplen[i]->mostrarVideo();
        }
    }
    else
    {
        cout << "¡No hay videos!" << endl;
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

void Sistema::guardarASistema(Video &video)
{
    videos.push_back(&video);
}

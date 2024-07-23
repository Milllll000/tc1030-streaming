#include "Sistema.h"

#include <fstream>
#include <iostream>

using namespace std;

vector<Video *> Sistema::getVideoCalif(float calif)
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

Sistema::Sistema()
{

}

void Sistema::mostrarPorCalificacion(float calif)
{
    vector <Video *> cumplenPel = getVideoCalif(calif);
    vector <Video *> cumplenSer;
    
    if (videos.size() > 0 && cumplenPel.size() > 0)
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
    
    if (videos.size() > 0 && cumplenSer.size() > 0)
    {
        cout << "Sí hay videos." << endl;
        
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

void Sistema::guardarASistema(Video &video)
{
    videos.push_back(&video);
}

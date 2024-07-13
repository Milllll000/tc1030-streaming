#include "Sistema.h"

#include <fstream>
#include <iostream>

using namespace std;

Sistema::Sistema()
{

}

void Sistema::mostrarPorCalificacion(float calif)
{
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

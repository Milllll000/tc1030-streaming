#include "Serie.h"
#include "Pelicula.h"

#include <fstream>
#include <string>
#include <vector>

using namespace std;

#ifndef SISTEMA_H
#define SISTEMA_H

class Sistema
{
    private:
        vector<Video *> videos;

    private:

        vector<Video *> getVideoCalif(float calif);

    public:
        Sistema();

        void calificar();
        void cargarArchivo(string direccion);
        void guardarAArchivo(string direccion, string datos);
        void guardarASistema(Video &video);
        void mostrarPorCalificacion(float calif);
        void mostrarPorGenero(string genero);

};

#endif
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
        // vector<Video *> videos;
        vector<Pelicula *> peliculas;
        vector<Serie *> series;

    private:

        vector<Video *> getVideo(float calif);
        vector<Video *> getVideo(string genero);
        vector<Pelicula *> getPeliculas();
        vector<Serie *> getSeries();
        void imprimir(vector<Video *> seleccionado);
        void imprimir(vector<Pelicula *> seleccionado);
        void imprimir(vector<Serie *> seleccionado);

    public:
        Sistema();

        void calificar();
        void cargarArchivo(string direccion);
        void guardarAArchivo(string direccion, string datos);
        void guardarASistema(Pelicula &pelicula);
        void guardarASistema(Serie &serie);
        void mostrarPorCalificacion(float calif);
        void mostrarPorGenero(char genero);
        void mostrarPorTIpo(char tipo);
        void mostrarEpisodios(string id);

};

#endif
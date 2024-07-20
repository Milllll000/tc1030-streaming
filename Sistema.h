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
        vector<Pelicula>peliculas;
        vector<Serie>series;
    public:
        Sistema();

        void calificar();
        void cargarArchivo(string direccion);
        void guardarAArchivo(string direccion, string datos);
        void guardarPelicula(Pelicula &pelicula);
        // void guardarSerie(Serie serie);
        void mostrarPorCalificacion(float calif);
        void mostrarPorGenero(string genero);

};

#endif
#include <string>
#include <fstream>

using namespace std;

#ifndef SISTEMA_H
#define SISTEMA_H

class Sistema
{
    public:
        Sistema();
        Sistema(fstream peliculas, fstream series);

        void mostrarPorCalificacion(float calif);
        void mostrarPorGenero(string genero);
        void cargarArchivo(string direccion);
        void calificar();
        void guardarAArchivo(string direccion, string datos);

};

#endif
#include "Pelicula.h"
#include "Serie.h"
#include "Sistema.h"

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    Sistema sistema;

    Pelicula p1;
    Pelicula p2;
    Serie s1;
    Serie s2;

    p1.agregarCalificacion(5.0f);
    s1.agregarCalificacion(5.0f);
    p1.setGenero("Acción");
    p2.setGenero("Comedia");
    s1.setGenero("Musical");
    s2.setGenero("Terror");

    sistema.guardarASistema(p1);
    sistema.guardarASistema(p2);
    sistema.guardarASistema(s1);
    sistema.guardarASistema(s2);
    
    while (true)
    {
        int input = 0;
        
        cout << "Sistema de películas y series en la plataforma de streaming Teneiga." << endl;
        cout << "Para mostrar todo el contenido disponible, ingrese 1" << endl;
        cout << "Para mostrar el contenido que tenga una calificación igual o mayor a la ingresada, ingrese 2" << endl;

        cin >> input;

        switch (input)
        {
        case 1:
        {
            sistema.mostrarPorCalificacion(0.0f);
            break;
        }
        case 2:
        {
            float calif;
            calif = 0.0f;
            cout << "Ingrese la calificación mínima: ";
            cin >> calif;
            sistema.mostrarPorCalificacion(calif);
            break;
        }
        case 3:
        {
            char genero;
            cout << "- Acción: 1\n- Comedia: 2\n- Misterio: 3\n- Musical: 4\n- Terror: 5" << endl;
            cin >> genero;
            try
            {
                sistema.mostrarPorGenero(genero);
            }
            catch (const invalid_argument& e)
            {
                cout << e.what() << endl;
            }
            break;
        }
        default:
        {
            return 0;
            break;
        }
        }
        
    }
    

    return 0;
}
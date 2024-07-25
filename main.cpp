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
    
    p1.setGenero("Accion");
    p2.setGenero("Comedia");
    s1.setGenero("Musical");
    s2.setGenero("Terror");

    s1.setID("0001");
    s2.setID("0002");

    sistema.guardarASistema(p1);
    sistema.guardarASistema(p2);

    Episodio e1;
    Episodio e2("Dominica", "0900", "40:00", 1);

    s1.agregarEpisodio(e1);
    s1.agregarEpisodio(e2);
    s1.agregarEpisodio(e1);
    s1.agregarEpisodio(e1);
    s1.agregarEpisodio(e1);
    s1.agregarEpisodio(e1);
    s1.agregarEpisodio(e1);

    
    sistema.guardarASistema(s1);
    sistema.guardarASistema(s2);
    
    while (true)
    {
        int input = 0;
        
        cout << "Sistema de peliculas y series en la plataforma de streaming Teneiga." << endl;
        cout << "Para mostrar todo el contenido disponible, ingrese 1." << endl;
        cout << "Para mostrar el contenido que tenga una calificacion igual o mayor a la ingresada, ingrese 2." << endl;
        cout << "Para mostrar contenido por genero, ingrese 3." << endl;
        cout << "Para mostrar solo peliculas, ingrese 4." << endl;
        cout << "Para mostrar solo series, ingrese 5." << endl;
        cout << "Para mostrar episodios de una serie, ingrese 6." << endl;

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
            cout << "Ingrese la calificacion minima: ";
            cin >> calif;
            sistema.mostrarPorCalificacion(calif);
            break;
        }
        case 3:
        {
            char genero;
            cout << "- Accion: 1\n- Comedia: 2\n- Misterio: 3\n- Musical: 4\n- Terror: 5" << endl;
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
        case 4:
        {
            sistema.mostrarPorTipo('1');
            break;
        }
        case 5:
        {
            sistema.mostrarPorTipo('2');   
            break;
        }
        case 6:
        {
            string id;
            sistema.mostrarPorTipo('2');
            cout << "Ingrese ID de la serie deseada: ";
            cin >> id;
            try
            {
                sistema.mostrarEpisodios(id);
            }
            catch(invalid_argument& e)
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
#include <string>
#include <vector>

using namespace std;

#ifndef VIDEO_H
#define VIDEO_H

class Video
{
protected:
    // Atributos protegidos
    int id;
    float califiacionPromedio;
    string nombre;
    string duracion;
    string genero;
    vector<float> calificaciones;
protected:
    // Método protegido
    float calcularPromedio();

public:
    // Constructores
    Video();
    Video(int id, string nombre, string duracion, string genero);

    // Getters y setters
    int getID();
    float getCalificacionPromedio();
    string getNombre();
    string getDuracion();
    string getGenero();
    vector<float> getCalificaciones();

    void setID(int id);
    void setNombre(string nombre);
    void setDuracion(string duracion);
    void setGenero(string genero);

    // Métodos especializados
    void mostrarVideo();
    void agregarCalificacion();
};

#endif
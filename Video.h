#include <string>
#include <vector>

using namespace std;

#ifndef VIDEO_H
#define VIDEO_H

class Video
{
protected:
    // Atributos protegidos
    string id;
    float califiacionPromedio;
    string nombre;
    string duracion;
    string genero;
    string datosString;
    vector<float> calificaciones;
protected:
    // Métodos protegidos
    float calcularPromedio();
    virtual void datosToString();

public:
    // Constructores
    Video();
    Video(string id, string nombre, string duracion, string genero);

    // Getters y setters
    string getID();
    float getCalificacionPromedio();
    string getNombre();
    string getDuracion();
    string getGenero();
    string getDatosString();
    vector<float> getCalificaciones();
    virtual string getTipoVideo();

    void setID(string id);
    void setNombre(string nombre);
    void setDuracion(string duracion);
    void setGenero(string genero);

    // Métodos especializados
    void mostrarVideo();
    void agregarCalificacion(float calificacion);
};

#endif
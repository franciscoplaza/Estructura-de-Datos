#pragma once
#include <iostream>
using namespace std;

class Asistente{
    private:
        string tipo;
        string nombre;
        int edad;
        string institucion;
    public:
        Asistente(string tipo, string nombre, int edad, string institucion);
        string getTipo();
        string getNombre();
        int getEdad();
        string getInstitucion();
        void setTipo(string tipo);
        void setNombre(string nombre);
        void setEdad(int edad);
        void setInstitucion(string institucion);
        ~Asistente();
}
#pragma once
#include <iostream>
using namespace std;


class Evento{
    private:
        string tipo;
        string ubicacion;
        int duracion;
        string tema:
    public:
        Evento(string tipo, string ubicacion, int duracion, string tema);
        string getTipo();
        string getUbicacion();
        int getDuracion();
        string getTema();
        void setTipo(string tipo);
        void setUbicacion(string ubicacion);
        void setDuracion(int duracion);
        void setTema(string tema);
        ~Evento();
};
#pragma once
#include <iostream>
using namespace std;

class Evento{
    private:
        string ubicacion;
        int duracion;
    public:
        Evento(string ubicacion, int duracion);
        string getUbicacion();
        int getDuracion();
        void setUbicacion(string ubicacion);
        void setDuracion(int duracion);
        ~Evento();
};
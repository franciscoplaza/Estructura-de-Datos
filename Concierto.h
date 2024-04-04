#pragma once
#include <iostream>
#include "Evento.h"
using namespace std;

class Concierto:public Evento{
    private:
        string genero;
        int capacidad;
    public:
        Concierto(string genero, string ubicacion, int duracion, int capacidad);
        string getGenero();
        int getCapacidad();
        void setCapacidad(int capacidad);
        void setGenero(string genero);
};
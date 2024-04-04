#pragma once
#include <iostream>
#include "Evento.h"
using namespace std;

class Seminario:public Evento{
    private:
        string tema;
        int capacidad;
    public:
        Seminario(string tema, string ubicacion, int duracion, int capacidad);
        string getTema();
        int getCapacidad();
        void setCapacidad(int capacidad);
        void setTema(string tema);
};
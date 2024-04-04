#pragma once
#include <iostream>
#include "Evento.h"
using namespace std;

class Conferencia:public Evento{
    private:
        string tema;
    public:
        Conferencia(string tema, string ubicacion, int duracion);
        string getTema();
        void setTema(string tema);
};
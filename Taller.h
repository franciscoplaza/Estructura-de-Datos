#pragma once
#include <iostream>
#include "Taller.h"
using namespace std;

class Taller:public Evento{
    private:
        string tema;
    public:
        Taller(string tema, string ubicacion, int duracion);
        string getTema();
        void setTema(string tema);
};
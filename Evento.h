#pragma once
#include <iostream>
#include <vector>
#include "Asistente.h"
using namespace std;


class Evento{
    private:
        string tipo;
        string ubicacion;
        int duracion;
        string tema;
        vector<Asistente*> asistentes;
    public:
        Evento(string tipo, string ubicacion, int duracion, string tema);
        string getTipo();
        string getUbicacion();
        int getDuracion();
        string getTema();
        vector<Asistente*> getAsistentes();
        void setTipo(string tipo);
        void setUbicacion(string ubicacion);
        void setDuracion(int duracion);
        void setTema(string tema);
        void setAsistente(Asistente* asistente);
        ~Evento();
};
#include <iostream>
#include "Evento.h"
#include "Concierto.h"
using namespace std;

Concierto::Concierto(string genero, string ubicacion, int duracion, int capacidad):Evento(ubicacion, duracion)
{
    this -> genero = genero;
    this -> capacidad = capacidad;
}

string Concierto::getGenero(){return genero;}
void Concierto::setGenero(string genero){this -> genero = genero;}
int Concierto::getCapacidad(){return capacidad;}
void Concierto::setCapacidad(int capacidad){this -> capacidad = capacidad;}
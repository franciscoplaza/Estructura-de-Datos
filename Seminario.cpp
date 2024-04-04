#include <iostream>
#include "Evento.h"
#include "Seminario.h"
using namespace std;

Seminario::Seminario(string tema, string ubicacion, int duracion, int capacidad):Evento(ubicacion, duracion)
{
    this -> tema = tema;
    this -> capacidad = capacidad;
}

string Seminario::getTema(){return tema;}
void Seminario::setTema(string tema){this -> tema = tema;}
int Seminario::getCapacidad(){return capacidad;}
void Seminario::setCapacidad(int capacidad){this -> capacidad = capacidad;}
#include <iostream>
#include "Evento.h"
#include "Taller.h"
using namespace std;

Taller::Taller(string tema, string ubicacion, int duracion):Evento(ubicacion, duracion)
{
    this -> tema = tema;
}

string Taller::getTema(){return tema;}
void Taller::setTema(string tema){this -> tema = tema;}
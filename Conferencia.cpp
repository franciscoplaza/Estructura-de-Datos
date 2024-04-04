#include <iostream>
#include "Evento.h"
#include "Conferencia.h"
using namespace std;

Conferencia::Conferencia(string tema, string ubicacion, int duracion):Evento(ubicacion, duracion)
{
    this -> tema = tema;
}

string Conferencia::getTema(){return tema;}
void Conferencia::setTema(string tema){this -> tema = tema;}
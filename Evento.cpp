#include <iostream>
#include "Evento.h"
using namespace std;

Evento::Evento(string ubicacion, int duracion){
    this -> ubicacion = ubicacion;
    this -> duracion = duracion;
}

string Evento::getUbicacion(){return ubicacion;}
int Evento::getDuracion(){return duracion;}
void Evento::setUbicacion(string ubicacion){this -> ubicacion = ubicacion;}
void Evento::setDuracion(int duracion){this -> duracion = duracion;}
Evento::~Evento(){};
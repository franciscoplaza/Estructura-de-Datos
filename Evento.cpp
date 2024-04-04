#include <iostream>
#include "Evento.h"
using namespace std;

Evento::Evento(string tipo, string ubicacion, int duracion, string tema){
    this -> tipo = tipo;
    this -> ubicacion = ubicacion;
    this -> duracion = duracion;
    this -> tema = tema;
}

string Evento::getTipo(){return tipo;}
string Evento::getUbicacion(){return ubicacion;}
int Evento::getDuracion(){return duracion;}
string Evento::getTema(){return tema;}
vector<Asistente> Evento::getAsistentes(){return asistentes;}
void Evento::setTipo(string tipo){this -> tipo = tipo;}
void Evento::setUbicacion(string ubicacion){this -> ubicacion = ubicacion;}
void Evento::setDuracion(int duracion){this -> duracion = duracion;}
void Evento::setTema(string tema){this -> tema = tema;}
void Evento::setAsistente(Asistente asistente){asistentes.push_back(asistente);}
Evento::~Evento(){};
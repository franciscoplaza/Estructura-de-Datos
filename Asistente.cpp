#include <iostream>
#include "Asistente.h"
using namespace std;

Asistente::Asistente(string tipo, string nombre, int edad, string institucion){
    this -> tipo = tipo;
    this -> nombre = nombre;
    this -> edad = edad;
    this -> institucion = institucion;
}

string Asistente::getTipo(){return tipo;}
string Asistente::getNombre(){return nombre;}
int Asistente::getEdad(){return edad;}
string Asistente::getInstitucion(){return institucion;}
void Asistente::setTipo(string tipo){this -> tipo = tipo;}
void Asistente::setNombre(string nombre){this -> nombre = nombre;}
void Asistente::setEdad(int edad){this -> edad = edad;}
void Asistente::setInstitucion(string institucion){this -> institucion = institucion;}
Asistente::~Asistente(){};
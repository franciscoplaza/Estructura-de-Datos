#include <iostream>
#include <vector>
#include "Evento.h"
using namespace std;

void mostrarMenu(){
    cout<<"1. Crear evento\n2. Registrar asistentes\n3. Lista de asistentes\n4. Generar informe\n5. Salir"<<endl;
}

Evento* crearEvento(){
    string tipo;
    string ubicacion;
    int duracion;
    string tema;

    cout<<"Ingrese el tipo de evento: ";
    cin>>tipo;

    cout<<"Ingrese la ubicación del evento: ";
    cin>>ubicacion;

    cout<<"Ingrese la duración del evento: ";
    cin>>duracion;

    cout<<"Ingrese el tema o género del evento: ";
    cin>>tema;

    Evento* evento = new Evento(tipo, ubicacion, duracion, tema);
    return evento;
}

int main(){
    vector<Evento*> eventos;
    int opcion;

    do{
        mostrarMenu();
        cout<<"Seleccione una opción: ";
        cin>>opcion;

        switch (opcion){
            case 1:
                eventos.push_back(crearEvento());
                cout<<"Se ha creado el evento correctamente!"<<endl;
                break;
            case 2:
                cout<<"2"<<endl;
                break;
            case 3:
                cout<<"3"<<endl;
                break;
            case 4:
                cout<<"4"<<endl;
                break;
            case 5:
                cout<<"Saliendo..."<<endl;
                break;
            default:
                cout<<"Opción inválida. Intente con un número válido."<<endl;
                break;
        }
    } while (opcion != 5);

    return 0;
    
};
#include <iostream>
#include <vector>
#include "Evento.h"
#include "Asistente.h"
using namespace std;

void mostrarMenu(){
    cout<<"\nMENÚ\n1. Crear evento\n2. Registrar asistentes\n3. Lista de asistentes\n4. Generar informe\n5. Salir"<<endl;
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

    cout<<"Ingrese la duración del evento en minutos: ";
    cin>>duracion;

    cout<<"Ingrese el tema o género del evento: ";
    cin>>tema;

    Evento* evento = new Evento(tipo, ubicacion, duracion, tema);
    return evento;
}

Asistente* crearAsistente(){
    string tipo;
    string nombre;
    int edad;
    string institucion;

    cout<<"Ingrese el tipo de asistente: ";
    cin>>tipo;

    cout<<"Ingrese el nombre del asistente: ";
    cin>>nombre;

    cout<<"Ingrese la edad del asistente: ";
    cin>>edad;

    cout<<"Ingrese la empresa o institución del asistente: ";
    cin>>institucion;

    Asistente* asistente = new Asistente(tipo, nombre, edad, institucion);
    return asistente;
}

void mostrarTiposEventos(vector<Evento*> eventos){
    vector<string> tipos;
    for(Evento* evento: eventos){
        string tipo = evento->getTipo();

        bool encontrado = false;
        for (int i = 0; i < tipos.size(); i++){
            if(tipos[i] == tipo){
                encontrado = true;
                break;
            }
        }

        if (!encontrado){
            tipos.push_back(tipo);
        }
        
    }
}

void mostrarEventos(vector<Evento*> eventos){
    int i = 1;
    cout<<"Lista de Eventos:"<<endl;
    for(Evento* evento: eventos){
        cout<<i++<<".Tipo de evento: "<<evento->getTipo()<<" | Tema: "<<evento->getTema()<<" | Ubicación: "<<evento->getUbicacion()<<endl;
    }
}

void mostrarAsistentes(vector<Evento*> eventos){
    int i = 1;
    Asistente* asis;
    cout<<"Lista de Asistentes:"<<endl;
    for(Evento* evento: eventos){
        for (int j = 0; j<evento->getAsistentes().size(); j++){
            asis = evento->getAsistentes()[j];
            cout<<i++<<".Tipo: "<<asis->getTipo()<<" | Nombre: "<<asis->getNombre()<<" | Edad: "<<asis->getEdad()
            <<" | Empresa o institución: "<<asis->getInstitucion()<<" | Evento al que asiste: "<<evento->getTipo()
            <<" en "<<evento->getUbicacion()<<endl;
        }
    }
}

void mostrarAsistentesPorEvento(vector<Evento*> eventos){
    int i;
    Asistente* asis;
    cout<<"\nAsistentes por Evento:"<<endl;
    for(Evento* evento: eventos){
        i=1;
        cout<<"Evento: "<<evento->getTipo()<<" | Tema: "<<evento->getTema()<<" | Ubicación: "<<evento->getUbicacion()<<endl;
        for (int j = 0; j<evento->getAsistentes().size(); j++){
            asis = evento->getAsistentes()[j];
            cout<<i++<<".Tipo: "<<asis->getTipo()<<" | Nombre: "<<asis->getNombre()<<" | Edad: "<<asis->getEdad()
            <<" | Empresa o institución: "<<asis->getInstitucion()<<endl;
        }
    }
}

void generarInforme(vector<Evento*> eventos){
    cout<<"INFORME GENERAL DE EVENTOS"<<endl;
    mostrarEventos(eventos);
    mostrarAsistentesPorEvento(eventos);


}

int main(){
    vector<Evento*> eventos;
    int opcion;
    Asistente* asistente;

    Evento* e1 = new Evento("Concierto", "Coquimbo", 120, "Rock");
    Evento* e2 = new Evento("Conferencia", "Copiapo", 30, "Salud");

    eventos.push_back(e1);
    eventos.push_back(e2);

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
                asistente = crearAsistente();
                mostrarEventos(eventos);
                int numeroEscogido;
                cout<<"Seleccione el número del evento al que desea agregar al asistente: ";
                cin>>numeroEscogido;

                eventos[numeroEscogido-1]->setAsistente(asistente);
                break;
            case 3:
                mostrarAsistentes(eventos);
                break;
            case 4:
                generarInforme(eventos);
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
#include <iostream>
#include <vector>
#include "Evento.h"
#include "Asistente.h"
using namespace std;

/**
 * Descripción:
 *      Desplegar el menú correspondiente a la interfaz de usuario
 * @param
 *      No recibe parámetros de entrada
 * @return
 *      Despliegue del menú
 */
void mostrarMenu(){
    cout<<"\nMENÚ\n1. Crear evento\n2. Registrar asistentes\n3. Lista de asistentes\n4. Generar informe\n5. Salir"<<endl;
}

/**
 * Descripción:
 *      Crear un evento según sus atributos y guardar su dirección en un puntero
 * @param
 *      No recibe parámetros de entrada
 * @return
 *      Puntero de Evento
 */
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

/**
 * Descripción:
 *      Crear un asistente según sus atributos y guardar su dirección en un puntero
 * @param
 *      No recibe parámetros de entrada
 * @return
 *      Puntero de Asistente
 */
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

/**
 * Descripción:
 *      Desplegar los eventos creados y sus atributos
 * @param
 *      vector<Evento*> eventos     Listado de eventos
 * @return
 *      Despliegue de los eventos
 */
void mostrarEventos(vector<Evento*> eventos){
    int i = 1;
    cout<<"Lista de Eventos:"<<endl;
    for(Evento* evento: eventos){
        cout<<i++<<".Tipo de evento: "<<evento->getTipo()<<" | Tema: "<<evento->getTema()<<" | Ubicación: "<<evento->getUbicacion()<<endl;
    }
}

/**
 * Descripción:
 *      Desplegar los asistentes registrados en los eventos y sus atributos
 * @param
 *      vector<Evento*> eventos     Listado de eventos
 * @return
 *      Despliegue de todos los asistentes
 */
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

/**
 * Descripción:
 *      Desplegar los asistentes registrados por cada evento y organizados por el evento 
 *      al que asisten, además de sus atributos
 * @param
 *      vector<Evento*> eventos     Listado de eventos
 * @return
 *      Despliegue de los asistentes por cada evento
 */
void mostrarAsistentesPorEvento(vector<Evento*> eventos){
    int i;
    Asistente* asis;
    cout<<"\nAsistentes por Evento:"<<endl;
    for(Evento* evento: eventos){
        i=1;
        cout<<"Evento: "<<evento->getTipo()<<" | Tema: "<<evento->getTema()<<" | Ubicación: "<<evento->getUbicacion()<<endl;
        if (evento->getAsistentes().size() == 0){
            cout<<"Sin asistentes registrados para este evento"<<endl;
        } else {
            for (int j = 0; j<evento->getAsistentes().size(); j++){
                asis = evento->getAsistentes()[j];
                cout<<i++<<".Tipo: "<<asis->getTipo()<<" | Nombre: "<<asis->getNombre()<<" | Edad: "<<asis->getEdad()
                <<" | Empresa o institución: "<<asis->getInstitucion()<<endl;
            }
        }
    }
}

/**
 * Descripción:
 *      Generar un informe general que muestre todos los eventos y los asistentes de cada uno
 * @param
 *      vector<Evento*> eventos     Listado de eventos
 * @return
 *      Despliegue del informe
 */
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

    for (Evento* evento: eventos){
        for (Asistente* a: evento->getAsistentes()){
            delete a;
            cout<<"Se borró un asistente"<<endl;
        }
        delete evento;
        cout<<"Se borró un evento"<<endl;
    }

    return 0;
    
};
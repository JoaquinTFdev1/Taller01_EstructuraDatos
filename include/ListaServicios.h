#pragma once
#include "Servicio.h"
#include <string>

using namespace std;
class ListaServicios {

private:

    class NodoServicio {
    public:
        Servicio* servicio;
        NodoServicio* next;
        NodoServicio(Servicio* servicio) {
            this->servicio = servicio;
            this->next = nullptr;
        }
    };

    NodoServicio* start;
    int cantidad;

public:

    ListaServicios();

    ~ListaServicios();

    ListaServicios(ListaServicios&) = delete;

    ListaServicios& operator=(ListaServicios&) = delete;

    bool isEmpty();

    int getSize();

    void insertLast(Servicio* servicio);

    Servicio* get(int index);

    Servicio* buscarServicio(string nombre);

    Paciente* buscarPaciente(string id,string& nombreServicio);

    void mostrarServicios();

    int mostrarEstadoGeneral();

    void clear();
};
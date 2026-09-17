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

        NodoServicio(
            Servicio* servicio
        ) {

            this->servicio =
                servicio;

            this->next =
                nullptr;
        }
    };

    NodoServicio* start;

    int cantidad;

public:

    ListaServicios();

    ~ListaServicios();

    ListaServicios(const ListaServicios&) = delete;

    ListaServicios& operator=(const ListaServicios&) = delete;

    bool isEmpty() const;

    int getSize() const;

    void insertLast(
        Servicio* servicio
    );

    Servicio* get(
        int index
    ) const;

    Servicio* buscarServicio(
        string nombre
    ) const;

    void mostrarServicios() const;

    void clear();
};
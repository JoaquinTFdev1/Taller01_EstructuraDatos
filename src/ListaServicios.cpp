#include "ListaServicios.h"
#include <iostream>

using namespace std;
ListaServicios::ListaServicios() {

    this->start =
        nullptr;

    this->cantidad =
        0;
}

ListaServicios::~ListaServicios() {

    this->clear();
}

bool ListaServicios::isEmpty() const {

    return
        this->start == nullptr;
}

int ListaServicios::getSize() const {

    return
        this->cantidad;
}

void ListaServicios::insertLast(
    Servicio* servicio
) {

    if (
        servicio == nullptr
    ) {

        return;
    }

    NodoServicio* nuevo =
        new NodoServicio(
            servicio
        );

    // Caso 1: lista vacia
    if (
        this->start == nullptr
    ) {

        this->start =
            nuevo;

        this->cantidad++;

        return;
    }

    // Caso 2: buscar el ultimo nodo
    NodoServicio* cursor =
        this->start;

    while (
        cursor->next != nullptr
    ) {

        cursor =
            cursor->next;
    }

    cursor->next =
        nuevo;

    this->cantidad++;
}

Servicio* ListaServicios::get(
    int index
) const {

    if (
        index < 0 ||
        index >= this->cantidad
    ) {

        return nullptr;
    }

    NodoServicio* cursor =
        this->start;

    int posicion = 0;

    while (
        cursor != nullptr
    ) {

        if (
            posicion == index
        ) {

            return
                cursor->servicio;
        }

        cursor =
            cursor->next;

        posicion++;
    }

    return nullptr;
}

Servicio*
ListaServicios::buscarServicio(
    string nombre
) const {

    NodoServicio* cursor =
        this->start;

    while (
        cursor != nullptr
    ) {

        if (
            cursor->servicio->getNombre()
            == nombre
        ) {

            return
                cursor->servicio;
        }

        cursor =
            cursor->next;
    }

    return nullptr;
}

void ListaServicios::mostrarServicios() const {

    cout
        << "\n=== DEPARTAMENTOS/SERVICIOS ==="
        << endl;

    if (
        this->start == nullptr
    ) {

        cout
            << "No hay servicios registrados."
            << endl;

        return;
    }

    NodoServicio* cursor =
        this->start;

    int numero = 1;

    while (
        cursor != nullptr
    ) {

        cout
            << numero
            << ". "
            << cursor->servicio->getNombre()
            << endl;

        numero++;

        cursor =
            cursor->next;
    }
}

void ListaServicios::clear() {

    while (
        this->start != nullptr
    ) {

        NodoServicio* eliminado =
            this->start;

        this->start =
            this->start->next;

        delete eliminado->servicio;

        delete eliminado;
    }

    this->cantidad = 0;
}
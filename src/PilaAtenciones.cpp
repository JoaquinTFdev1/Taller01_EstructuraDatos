#include "PilaAtenciones.h"
#include <iostream>
using namespace std;

PilaAtenciones::PilaAtenciones() {

    this->topNode = nullptr;

    this->cantidad = 0;
}

PilaAtenciones::~PilaAtenciones() {

    this->clear();
}


bool PilaAtenciones::isEmpty() const {

    return this->topNode == nullptr;
}


int PilaAtenciones::getSize() const {

    return this->cantidad;
}


void PilaAtenciones::push(
    const Atencion& atencion
) {

    NodoAtencion* nuevo =
        new NodoAtencion(atencion);


    nuevo->next =
        this->topNode;


    this->topNode =
        nuevo;


    this->cantidad++;
}


bool PilaAtenciones::pop(
    Atencion& atencion
) {

    if (
        this->topNode == nullptr
    ) {

        return false;
    }


    NodoAtencion* eliminado =
        this->topNode;


    atencion =
        eliminado->atencion;


    this->topNode =
        eliminado->next;


    delete eliminado;


    this->cantidad--;


    return true;
}


bool PilaAtenciones::top(
    Atencion& atencion
) const {

    if (
        this->topNode == nullptr
    ) {

        return false;
    }


    atencion =
        this->topNode->atencion;


    return true;
}


void PilaAtenciones::mostrar() const {

    cout
        << "\n=== HISTORIAL DE ATENCIONES ==="
        << endl;


    if (
        this->topNode == nullptr
    ) {

        cout
            << "No hay atenciones registradas."
            << endl;

        return;
    }


    NodoAtencion* cursor =
        this->topNode;


    int numero = 1;


    while (
        cursor != nullptr
    ) {

        cout
            << numero
            << ". "
            << cursor->atencion.getNombre()
            << " | Edad: "
            << cursor->atencion.getEdad()
            << " | Departamento: "
            << cursor->atencion.getServicio()
            << endl;


        cursor =
            cursor->next;


        numero++;
    }
}


void PilaAtenciones::clear() {

    while (
        this->topNode != nullptr
    ) {

        NodoAtencion* eliminado =
            this->topNode;


        this->topNode =
            this->topNode->next;


        delete eliminado;
    }


    this->cantidad = 0;
}
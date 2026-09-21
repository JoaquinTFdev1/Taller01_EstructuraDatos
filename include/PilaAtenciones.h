#pragma once
#include "Atencion.h"

class PilaAtenciones {

private:
    class NodoAtencion {

    public:
        Atencion atencion;
        NodoAtencion* next;
        NodoAtencion(Atencion& atencion) {
            this->atencion = atencion;
            this->next = nullptr;
        }
    };

    NodoAtencion* topNode;
    int cantidad;

public:

    PilaAtenciones();

    ~PilaAtenciones();

    PilaAtenciones(PilaAtenciones&) = delete;

    PilaAtenciones& operator=(PilaAtenciones&) = delete;

    bool isEmpty();

    int getSize();

    void push(Atencion& atencion);
    bool pop(Atencion& atencion);

    bool top(Atencion& atencion);

    void mostrar();

    void clear();
};




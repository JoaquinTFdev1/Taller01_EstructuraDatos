#pragma once
#include "Atencion.h"

class PilaAtenciones {

private:
    class NodoAtencion {

    public:
        Atencion atencion;
        NodoAtencion* next;
        NodoAtencion(const Atencion& atencion) {
            this->atencion = atencion;
            this->next = nullptr;
        }
    };

    NodoAtencion* topNode;
    int cantidad;

public:

    PilaAtenciones();

    ~PilaAtenciones();

    PilaAtenciones(const PilaAtenciones&) = delete;

    PilaAtenciones& operator=(const PilaAtenciones&) = delete;

    bool isEmpty() const;

    int getSize() const;

    void push(const Atencion& atencion);

    bool pop(Atencion& atencion);

    bool top(Atencion& atencion) const;

    void mostrar() const;

    void clear();
};
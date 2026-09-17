#include "Atencion.h"

Atencion::Atencion() {

    this->id = "";
    this->nombre = "";
    this->edad = 0;
    this->servicio = "";
}

Atencion::Atencion(
    const Paciente& paciente
) {

    this->id =
        paciente.getId();

    this->nombre =
        paciente.getNombre();

    this->edad =
        paciente.getEdad();

    this->servicio =
        paciente.getServicio();
}


Atencion::~Atencion() {
}


string Atencion::getId() const {

    return this->id;
}


string Atencion::getNombre() const {

    return this->nombre;
}


int Atencion::getEdad() const {

    return this->edad;
}


string Atencion::getServicio() const {

    return this->servicio;
}

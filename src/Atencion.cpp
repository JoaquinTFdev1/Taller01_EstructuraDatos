#include "Atencion.h"

Atencion::Atencion() {
    this->id = "";
    this->nombre = "";
    this->edad = 0;
    this->servicio = "";
}

Atencion::Atencion(Paciente& paciente) {
    this->id = paciente.getId();
    this->nombre = paciente.getNombre();
    this->edad = paciente.getEdad();
    this->servicio = paciente.getServicio();
}

Atencion::~Atencion() {}

string Atencion::getId() {
    return this->id;
}

string Atencion::getNombre() {
    return this->nombre;
}

int Atencion::getEdad() {
    return this->edad;
}

string Atencion::getServicio() {
    return this->servicio;
}
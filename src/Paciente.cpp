#include "../include/Paciente.h"

Paciente::Paciente(string id,string nombre,int edad,string servicio): Persona(nombre, edad) {
    this->id = id;
    this->servicio = servicio;
}

Paciente::~Paciente() {}

string Paciente::getId() {
    return this->id;
}

string Paciente::getServicio() {
    return this->servicio;
}
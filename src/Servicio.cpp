#include "Servicio.h"
#include <iostream>

using namespace std;

Servicio::Servicio(string nombre) {
    this->nombre = nombre;
}

Servicio::~Servicio() {}

string Servicio::getNombre() const {
    return this->nombre;
}

int Servicio::getCantidadPacientes() const {
    return this->pacientes.getSize();
}

void Servicio::agregarPaciente(Paciente* paciente) {
    this->pacientes.insertLast(paciente);
}

Paciente* Servicio::buscarPaciente(string id) const {
    return this->pacientes.buscarPorId(id);
}

void Servicio::mostrarPacientes() const {
    cout << "\n=== " << this->nombre << " ===" << endl;
    cout << "Cantidad de pacientes: " << this->pacientes.getSize() << endl;
    this->pacientes.mostrar();
}
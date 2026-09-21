#include "Servicio.h"
#include "Utilidades.h"
#include <iostream>

using namespace std;

Servicio::Servicio(string nombre) {
    this->nombre = nombre;
}

Servicio::~Servicio() {}

string Servicio::getNombre() {
    return this->nombre;
}

int Servicio::getCantidadPacientes() {
    return this->pacientes.getSize();
}

void Servicio::agregarPaciente(Paciente* paciente) {
    this->pacientes.insertLast(paciente);
}

Paciente* Servicio::buscarPaciente(string id) {
    return this->pacientes.buscarPorId(id);
}

void Servicio::mostrarPacientes() {
    string titulo = "URGENCIAS";
    string departamento = "urgencias";
    if (this->nombre == "Medicina General") {
        titulo = "MEDICINA GENERAL";
        departamento = "medicina general";
    }
    else if (this->nombre == "Cardiologia") {
        titulo = "CARDIOLOGÍA";
        departamento = "cardiología";
    }
    else if (this->nombre == "Neurologia") {
        titulo = "NEUROLOGÍA";
        departamento = "neurología";
    }
    else if (this->nombre == "Traumatologia") {
        titulo = "TRAUMATOLOGÍA";
        departamento = "traumatología";
    }
    else if (this->nombre == "Cirugia") {
        titulo = "CIRUGÍA";
        departamento = "cirugía";
    }
    else if (this->nombre == "Pediatria") {
        titulo = "PEDIATRÍA";
        departamento = "pediatría";
    }
    else if (this->nombre == "Hospitalizacion") {
        titulo = "HOSPITALIZACIÓN";
        departamento = "hospitalización";
    }

    cout << "\n=== ESTADO " << titulo << " ===" << endl;
    cout << "Pacientes en el departamento de " << departamento << ": " << this->pacientes.getSize() << endl;
    this->pacientes.mostrar();
}
#include "Hospital.h"
#include "ArchivoPacientes.h"
#include "Servicio.h"
#include "Utilidades.h"

#include <fstream>
#include <iostream>

using namespace std;

Hospital::Hospital() {
    this->inicializarServicios();
}

Hospital::~Hospital() {}

void Hospital::inicializarServicios() {

    this->servicios.insertLast(new Servicio("Urgencias"));
    this->servicios.insertLast(new Servicio("Medicina General"));
    this->servicios.insertLast(new Servicio("Cardiologia"));
    this->servicios.insertLast(new Servicio("Neurologia"));
    this->servicios.insertLast(new Servicio("Traumatologia"));
    this->servicios.insertLast(new Servicio("Cirugia"));
    this->servicios.insertLast(new Servicio("Pediatria"));
    this->servicios.insertLast(new Servicio("Hospitalizacion"));
}

bool Hospital::cargarPacientesDesdeArchivo(string ruta) {

    ifstream archivo(ruta);

    if (!archivo.is_open()) {
        cout << "Error: no se pudo abrir el archivo '" << ruta << "'." << endl;
        return false;
    }

    string linea;

    int numeroLinea = 0;
    int incorporados = 0;
    int rechazados = 0;


    while (getline(archivo,linea)) {

        numeroLinea++;

        if (recortar(linea).empty()) {

            cout << "Linea " << numeroLinea << " rechazada: linea vacia." << endl;
            rechazados++;
            continue;
        }

        string id;
        string nombre;
        int edad = 0;
        string servicio;
        string error;

        bool valida = interpretarLineaPaciente(linea,id,nombre,edad,servicio,error);

        if (!valida) {
            cout << "Linea " << numeroLinea << " rechazada: " << error << "." << endl;
            rechazados++;
            continue;
        }

        if (this->existePaciente(id)) {
            cout << "Linea " << numeroLinea << " rechazada: paciente duplicado con ID " << id << "."<< endl;
            rechazados++;
            continue;
        }

        Paciente* paciente = new Paciente(id,nombre,edad,servicio);

        this->colaEspera.push(paciente);

        incorporados++;
    }

    archivo.close();

    cout << "\n=== RESULTADO DE LA CARGA ===" << endl;
    cout << "Pacientes incorporados: " << incorporados << endl;
    cout << "Registros rechazados: " << rechazados << endl;

    return true;
}


void Hospital::mostrarCola() const {

    this->colaEspera.mostrar();
}


bool Hospital::existePaciente(string id) const {

    if (this->colaEspera.buscarPorId(id)!= nullptr) {
        return true;
    }

    string nombreServicio;

    if (this->servicios.buscarPaciente(id,nombreServicio)!= nullptr) {
        return true;
    }
    return false;
}


void Hospital::atenderPacientes(int cantidad) {

    if (cantidad <= 0) {
        cout << "La cantidad a atender debe ser mayor que 0." << endl;
        return;
    }

    if (this->colaEspera.isEmpty()) {

        cout << "No hay pacientes pendientes." << endl;
        return;
    }


    if (cantidad > this->colaEspera.getSize()) {

        cout << "Solo hay " << this->colaEspera.getSize() << " paciente(s) en espera." << endl;
        cout << "Se atenderan todos los disponibles." << endl;

        cantidad = this->colaEspera.getSize();
    }


    cout << "\n=== ATENDIENDO PACIENTES ===" << endl;

    for (int i = 0; i < cantidad; i++) {

        Paciente* paciente = this->colaEspera.pop();

        if (paciente == nullptr) {
            return;
        }

        Servicio* servicio = this->servicios.buscarServicio(paciente->getServicio());

        if (servicio == nullptr) {

            cout << "Error: no se encontro el servicio de " << paciente->getNombre() << "." << endl;
            this->colaEspera.push(paciente);
            return;
        }

        servicio->agregarPaciente(paciente);
        Atencion registro(*paciente);

        this->historial.push(registro);

        cout << "\nPaciente atendido:" << endl;
        cout << "ID: " << paciente->getId() << endl;
        cout << "Nombre: " << paciente->getNombre() << endl;
        cout << "Edad: " << paciente->getEdad() << endl;
        cout << "Servicio: " << paciente->getServicio() << endl;
        cout << "Paciente enviado a " << paciente->getServicio() << "." << endl;
    }
}

void Hospital::mostrarDepartamento(int numero) const {

    if (numero < 1 || numero > this->servicios.getSize()) {
        cout << "Departamento invalido." << endl;
        return;
    }

    Servicio* servicio = this->servicios.get(numero - 1);

    if (servicio == nullptr) {
        cout << "No fue posible acceder al departamento." << endl;
        return;
    }

    servicio->mostrarPacientes();
}

void Hospital::mostrarHistorial() const {

    this->historial.mostrar();
}

void Hospital::mostrarServicios() const {

    this->servicios.mostrarServicios();
}
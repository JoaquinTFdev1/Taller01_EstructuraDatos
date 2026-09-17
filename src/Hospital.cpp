#include "Hospital.h"
#include "ArchivoPacientes.h"
#include "Servicio.h"

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

        cout << "No se pudo abrir el archivo: " << ruta << endl;
        return false;
    }

    string linea;

    int numeroLinea = 0;
    int incorporados = 0;

    while (getline(archivo,linea)) {

        numeroLinea++;
        string id;
        string nombre;

        int edad = 0;
        string servicio;
        string error;

        bool valida = interpretarLineaPaciente(linea,id,nombre,edad,servicio,error);

        if (!valida) {

            cout << "Linea " << numeroLinea << " rechazada: " << error << "." << endl;
            continue;
        }

        Paciente* paciente =
            new Paciente(
                id,
                nombre,
                edad,
                servicio
            );

        this->colaEspera.push(
            paciente
        );


        incorporados++;
    }


    archivo.close();


    cout
        << "\nCarga finalizada."
        << endl;


    cout
        << "Pacientes incorporados: "
        << incorporados
        << endl;


    return true;
}


void Hospital::mostrarCola() const {

    this->colaEspera.mostrar();
}


void Hospital::mostrarServicios() const {

    this->servicios.mostrarServicios();
}
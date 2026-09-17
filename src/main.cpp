#include <iostream>

#include "ArchivoPacientes.h"

using namespace std;

int main() {

    string linea =
        "001;Juan Perez;25;Cardiologia";


    string id;

    string nombre;

    int edad = 0;

    string servicio;

    string error;


    bool valido =
        interpretarLineaPaciente(
            linea,
            id,
            nombre,
            edad,
            servicio,
            error
        );


    if (
        valido
    ) {

        cout
            << "=== PACIENTE VALIDO ==="
            << endl;


        cout
            << "ID: "
            << id
            << endl;


        cout
            << "Nombre: "
            << nombre
            << endl;


        cout
            << "Edad: "
            << edad
            << endl;


        cout
            << "Servicio: "
            << servicio
            << endl;
    }

    else {

        cout
            << "Error: "
            << error
            << endl;
    }


    return 0;
}
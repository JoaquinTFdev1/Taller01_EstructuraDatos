// Nombre: Joaquín Esteban Torres Flores
// RUT: 21.547.370-8
// Usuario de GitHub: JoaquinTFdev1
// Carrera: Ingeniería Civil Industrial


#include <iostream>

#include "Hospital.h"

using namespace std;

int main() {

    cout << "================================" << endl;
    cout << "       HOSPITAL MARMAJA         " << endl;
    cout << "================================" << endl;

    Hospital hospital;

    hospital.cargarPacientesDesdeArchivo(
        "pacientes.txt"
    );

    cout << "\n=== ESTADO INICIAL ===" << endl;

    hospital.mostrarEstadoGeneral();

    hospital.atenderPacientes(2);

    cout << "\n=== ESTADO DESPUES DE ATENDER ===" << endl;

    hospital.mostrarEstadoGeneral();

    return 0;
}
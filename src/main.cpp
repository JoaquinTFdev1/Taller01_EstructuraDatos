
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

    cout << "\n=== PRUEBA 1: PACIENTE EN ESPERA ===" << endl;

    hospital.buscarPaciente("002");

    hospital.atenderPacientes(1);

    cout << "\n=== PRUEBA 2: PACIENTE DERIVADO ===" << endl;

    hospital.buscarPaciente("001");

    cout << "\n=== PRUEBA 3: PACIENTE INEXISTENTE ===" << endl;

    hospital.buscarPaciente("999");

    return 0;
}
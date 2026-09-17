#include <iostream>
#include "Hospital.h"

using namespace std;


int main() {

    cout << "================================" << endl;
    cout << "       HOSPITAL MARMAJA         " << endl;
    cout << "================================" << endl;

    Hospital hospital;

    hospital.cargarPacientesDesdeArchivo("pacientes.txt");

    cout << "\n=== COLA INICIAL ===" << endl;

    hospital.mostrarCola();

    hospital.atenderPacientes(2);

    cout << "\n=== COLA DESPUES DE ATENDER ===" << endl;

    hospital.mostrarCola();

    cout << "\n=== CARDIOLOGIA ===" << endl;

    hospital.mostrarDepartamento(3);

    cout << "\n=== URGENCIAS ===" << endl;

    hospital.mostrarDepartamento(1);

    hospital.mostrarHistorial();


    return 0;
}
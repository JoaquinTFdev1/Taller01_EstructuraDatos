#include <iostream>

#include "Hospital.h"

using namespace std;


int main() {

    cout << "================================" << endl;
    cout << "       HOSPITAL MARMAJA         " << endl;
    cout << "================================" << endl;


    Hospital hospital;


    cout
        << "\nCargando pacientes..."
        << endl;


    hospital.cargarPacientesDesdeArchivo(
        "pacientes.txt"
    );


    hospital.mostrarCola();


    return 0;
}
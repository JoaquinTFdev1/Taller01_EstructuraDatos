#include <iostream>
#include "Paciente.h"

using namespace std;

int main() {

    cout << "================================" << endl;
    cout << "       HOSPITAL MARMAJA         " << endl;
    cout << "================================" << endl;

    Paciente paciente("001","Juan Perez",25,"Cardiologia");

    cout << "\n=== PACIENTE DE PRUEBA ===" << endl;

    cout << "ID: " << paciente.getId() << endl;
    cout << "Nombre: " << paciente.getNombre() << endl;
    cout << "Edad: " << paciente.getEdad() << endl;
    cout << "Servicio: " << paciente.getServicio() << endl;

    return 0;
}
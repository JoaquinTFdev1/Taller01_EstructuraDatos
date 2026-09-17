#include <iostream>
#include "Servicio.h"

using namespace std;

int main() {

    cout << "================================" << endl;
    cout << "       HOSPITAL MARMAJA         " << endl;
    cout << "================================" << endl;

    Servicio cardiologia("Cardiologia");

    cardiologia.agregarPaciente(new Paciente("001","Juan Perez",25,"Cardiologia"));
    cardiologia.agregarPaciente(new Paciente("006","Sofia Diaz",52,"Cardiologia"));
    cardiologia.mostrarPacientes();

    cout << "\nBuscando paciente 006..." << endl;

    Paciente* encontrado = cardiologia.buscarPaciente("006");

    if (encontrado != nullptr) {
        cout << "Paciente encontrado: " << encontrado->getNombre() << endl;
    }

    return 0;
}
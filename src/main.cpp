#include <iostream>

#include "ListaPacientes.h"

using namespace std;

int main() {

    cout << "================================" << endl;
    cout << "       HOSPITAL MARMAJA         " << endl;
    cout << "================================" << endl;

    ListaPacientes pacientes;

    pacientes.insertLast(new Paciente("001","Juan Perez",25,"Cardiologia"));
    pacientes.insertLast(new Paciente("002","Maria Soto",67,"Urgencias"));
    pacientes.insertLast(new Paciente("003","Pedro Rojas",43,"Cirugia"));

    cout << "\n=== LISTA DE PACIENTES ===" << endl;
    pacientes.mostrar();

    cout << "\nCantidad: " << pacientes.getSize() << endl;

    Paciente* encontrado = pacientes.buscarPorId("002");

    if (encontrado != nullptr) {
        cout << "\nPaciente encontrado: " << encontrado->getNombre() << endl;
    }

    return 0;
}
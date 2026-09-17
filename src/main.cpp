#include <iostream>
#include "ColaPacientes.h"
using namespace std;

int main() {

    cout << "================================" << endl;
    cout << "       HOSPITAL MARMAJA         " << endl;
    cout << "================================" << endl;

    ColaPacientes cola;

    Paciente* p1 = new Paciente("001", "Juan Perez", 25, "Cardiologia");
    Paciente* p2 = new Paciente("002", "Maria Soto", 67, "Urgencias");
    Paciente* p3 = new Paciente("003", "Pedro Rojas", 43, "Cirugia");

    cola.push(p1);
    cola.push(p2);
    cola.push(p3);

    cola.mostrar();
    cout << "\nCantidad inicial: " << cola.getSize() << endl;

    Paciente* primero = cola.front();

    if (primero != nullptr) {
        cout << "Primer paciente: " << primero->getId() << endl;
    }

    cout << "\n=== PRUEBA FIFO ===" << endl;

    while (!cola.isEmpty()) {

        Paciente* paciente = cola.pop();

        cout << "Paciente retirado: " << paciente->getId() << " - " << paciente->getNombre() << endl;
        delete paciente;
    }

    cola.mostrar();

    cout << "\nCantidad final: "
         << cola.getSize()
         << endl;

    return 0;
}
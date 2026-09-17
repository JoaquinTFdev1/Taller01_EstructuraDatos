#include <iostream>
#include "ListaServicios.h"

using namespace std;
int main() {

    cout << "================================" << endl;
    cout << "       HOSPITAL MARMAJA         " << endl;
    cout << "================================" << endl;

    ListaServicios servicios;

    servicios.insertLast(
        new Servicio("Urgencias")
    );

    servicios.insertLast(
        new Servicio("Medicina General")
    );

    servicios.insertLast(
        new Servicio("Cardiologia")
    );

    servicios.insertLast(
        new Servicio("Neurologia")
    );

    servicios.insertLast(
        new Servicio("Traumatologia")
    );

    servicios.insertLast(
        new Servicio("Cirugia")
    );

    servicios.insertLast(
        new Servicio("Pediatria")
    );

    servicios.insertLast(
        new Servicio("Hospitalizacion")
    );

    servicios.mostrarServicios();

    cout
        << "\nCantidad de servicios: "
        << servicios.getSize()
        << endl;

    cout
        << "\nBuscando Cardiologia..."
        << endl;

    Servicio* cardiologia =
        servicios.buscarServicio(
            "Cardiologia"
        );

    if (
        cardiologia != nullptr
    ) {

        cout
            << "Servicio encontrado: "
            << cardiologia->getNombre()
            << endl;
    }

    return 0;
}
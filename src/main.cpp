#include <iostream>

#include "Utilidades.h"

using namespace std;

int main() {

    cout
        << "=== PRUEBA DE VALIDACIONES ==="
        << endl;


    int edad = 0;


    if (
        convertirAEnteroNoNegativo(
            "25",
            edad
        )
    ) {

        cout
            << "Edad valida: "
            << edad
            << endl;
    }


    if (
        !convertirAEnteroNoNegativo(
            "2a",
            edad
        )
    ) {

        cout
            << "Edad '2a' rechazada correctamente."
            << endl;
    }


    string servicio1 =
        obtenerNombreServicioCanonico(
            "Cardiologia"
        );


    cout
        << "Servicio valido: "
        << servicio1
        << endl;


    string servicio2 =
        obtenerNombreServicioCanonico(
            "Oncologia"
        );


    if (
        servicio2.empty()
    ) {

        cout
            << "Oncologia no pertenece a los servicios del hospital."
            << endl;
    }


    return 0;
}
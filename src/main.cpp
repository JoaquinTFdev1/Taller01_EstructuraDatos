
// Nombre: Joaquín Esteban Torres Flores
// RUT: 21.547.370-8
// Usuario de GitHub: JoaquinTFdev1
// Carrera: Ingeniería Civil Industrial

#include <iostream>
#include <string>

#include "Hospital.h"
#include "Utilidades.h"

using namespace std;

int main() {

    Hospital hospital;

    hospital.cargarPacientesDesdeArchivo("pacientes.txt", false);

    string entrada;

    int opcion = 0;
    bool continuar = true;

    while (continuar) {

        cout << "\n=== HOSPITAL MARMAJA ===" << endl;
        cout << "1. Atender pacientes" << endl;
        cout << "2. Ver departamento" << endl;
        cout << "3. Revisar historial de atencion" << endl;
        cout << "4. Mostrar cola de pacientes pendientes" << endl;
        cout << "5. Mostrar estado general de servicios" << endl;
        cout << "6. Buscar paciente por ID" << endl;
        cout << "7. Salir" << endl;

        cout << "\nSeleccionar opcion: ";

        if (!getline(cin, entrada)) {
            break;
        }

        if (!convertirAEnteroNoNegativo(entrada, opcion)) {
            cout << "Opcion invalida. Debe ingresar un numero." << endl;
            continue;
        }

        if (opcion < 1 || opcion > 7) {
            cout << "Opcion invalida. Ingrese un numero entre 1 y 7." << endl;
            continue;
        }

        if (opcion == 1) {

            hospital.mostrarCola();

            cout << "\nIndique la cantidad de pacientes a atender: ";

            if (!getline(cin, entrada)) {
                break;
            }

            int cantidad = 0;

            if (!convertirAEnteroNoNegativo(entrada, cantidad)) {
                cout << "Cantidad invalida." << endl;
                continue;
            }

            hospital.atenderPacientes(cantidad);
        }

        else if (opcion == 2) {

            hospital.mostrarServicios();

            cout << "\nSeleccionar opcion: ";

            if (!getline(cin, entrada)) {
                break;
            }

            int numero = 0;

            if (!convertirAEnteroNoNegativo(entrada, numero)) {
                cout << "Departamento invalido." << endl;
                continue;
            }

            hospital.mostrarDepartamento(numero);
        }

        else if (opcion == 3) {
            hospital.mostrarHistorial();
        }

        else if (opcion == 4) {
            hospital.mostrarCola();
        }

        else if (opcion == 5) {
            hospital.mostrarEstadoGeneral();
        }

        else if (opcion == 6) {

            cout << "\nIngrese el ID del paciente: ";

            if (!getline(cin, entrada)) {
                break;
            }

            hospital.buscarPaciente(entrada);
        }

        else if (opcion == 7) {
            continuar = false;
        }
    }

    cout << "\nHasta luego :3." << endl;

    return 0;
}
#pragma once
#include "ListaPacientes.h"
#include <string>

using namespace std;
class Servicio {

private:

    string nombre;
    ListaPacientes pacientes;

public:

    Servicio(string nombre);
    ~Servicio();
    string getNombre();
    int getCantidadPacientes();
    void agregarPaciente(Paciente* paciente);
    Paciente* buscarPaciente(string id);
    void mostrarPacientes();
};
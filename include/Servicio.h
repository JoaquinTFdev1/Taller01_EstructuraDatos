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

    string getNombre() const;

    int getCantidadPacientes() const;

    void agregarPaciente(
        Paciente* paciente
    );

    Paciente* buscarPaciente(
        string id
    ) const;

    void mostrarPacientes() const;
};
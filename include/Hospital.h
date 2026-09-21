#pragma once

#include "ColaPacientes.h"
#include "ListaServicios.h"
#include "PilaAtenciones.h"
#include <string>

using namespace std;


class Hospital {

private:

    ColaPacientes colaEspera;

    ListaServicios servicios;

    PilaAtenciones historial;

    void inicializarServicios();
    bool existePaciente(string id);


public:

    Hospital();
    ~Hospital();

    bool cargarPacientesDesdeArchivo(string ruta,bool mostrarResumen = true);

    void mostrarCola();

    void mostrarServicios();

    void atenderPacientes(int cantidad);

    void mostrarDepartamento(int numero);

    void mostrarHistorial();

    void mostrarEstadoGeneral();

    void buscarPaciente(string id);
};
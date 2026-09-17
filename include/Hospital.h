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


public:
    Hospital();
    ~Hospital();
    bool cargarPacientesDesdeArchivo(string ruta);
    void mostrarCola() const;
    void mostrarServicios() const;
};
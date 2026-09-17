#pragma once

#include "ColaPacientes.h"
#include "ListaServicios.h"
#include "PilaAtenciones.h"

class Hospital {

private:
    ColaPacientes colaEspera;
    ListaServicios servicios;
    PilaAtenciones historial;

    void inicializarServicios();


public:
    Hospital();
    ~Hospital();
    void mostrarServicios() const;
};
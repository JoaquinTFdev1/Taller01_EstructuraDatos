#pragma once
#include "Paciente.h"
#include <string>

using namespace std;
class Atencion {

private:
    string id;
    string nombre;
    int edad;
    string servicio;

public:
    Atencion();
    Atencion(Paciente& paciente);

    ~Atencion();

    string getId();

    string getNombre();

    int getEdad();

    string getServicio();
};
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
    Atencion(const Paciente& paciente);

    ~Atencion();

    string getId() const;

    string getNombre() const;

    int getEdad() const;

    string getServicio() const;
};
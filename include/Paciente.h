#pragma once

#include "Persona.h"

#include <string>

using namespace std;

class Paciente : public Persona {

private:
    string id;
    string servicio;

public:
    Paciente(
        string id,
        string nombre,
        int edad,
        string servicio
    );

    ~Paciente();

    string getId() const;

    string getServicio() const;
};
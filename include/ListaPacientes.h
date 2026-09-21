#pragma once

#include "Paciente.h"
#include <string>

using namespace std;

class ListaPacientes {

private:

    class NodoPaciente {

    public:

        Paciente* paciente;

        NodoPaciente* next;

        NodoPaciente(Paciente* paciente) {

            this->paciente = paciente;

            this->next = nullptr;
        }
    };

    NodoPaciente* start;

    int cantidad;

public:

    ListaPacientes();

    ~ListaPacientes();

    ListaPacientes(ListaPacientes&) = delete;

    ListaPacientes& operator=(ListaPacientes&) = delete;

    bool isEmpty();

    int getSize();

    void insertLast(Paciente* paciente);

    Paciente* get(int index);

    Paciente* getFirst();

    Paciente* buscarPorId(string id);

    void mostrar();

    void clear();
};
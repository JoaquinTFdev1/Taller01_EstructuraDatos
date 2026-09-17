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

    ListaPacientes(const ListaPacientes&) = delete;

    ListaPacientes& operator=(const ListaPacientes&) = delete;

    bool isEmpty() const;

    int getSize() const;

    void insertLast(Paciente* paciente);

    Paciente* get(int index) const;

    Paciente* getFirst() const;

    Paciente* buscarPorId(string id) const;

    void mostrar() const;

    void clear();
};
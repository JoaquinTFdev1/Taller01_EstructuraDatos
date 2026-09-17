#pragma once

#include "Paciente.h"

class ColaPacientes {

private:

    class NodoCola {

    public:
        Paciente* paciente;
        NodoCola* next;

        NodoCola(Paciente* paciente) {

            this->paciente = paciente;
            this->next = nullptr;
        }
    };

    NodoCola* frente;
    NodoCola* final;

    int cantidad;

public:

    ColaPacientes();

    ~ColaPacientes();

    // Evitar copias accidentales de la cola
    ColaPacientes(const ColaPacientes&) = delete;
    ColaPacientes& operator=(const ColaPacientes&) = delete;

    bool isEmpty() const;

    int getSize() const;

    void push(Paciente* paciente);

    Paciente* pop();

    Paciente* front() const;

    void mostrar() const;
};
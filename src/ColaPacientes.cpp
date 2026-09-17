//
// Created by joaqu on 17-09-2026.
//

#include "ColaPacientes.h"

#include <iostream>

using namespace std;

ColaPacientes::ColaPacientes() {

    this->frente = nullptr;
    this->final = nullptr;
    this->cantidad = 0;
}

ColaPacientes::~ColaPacientes() {

    while (!this->isEmpty()) {

        Paciente* paciente = this->pop();
        delete paciente;
    }
}

bool ColaPacientes::isEmpty() const {
    return this->frente == nullptr;
}

int ColaPacientes::getSize() const {
    return this->cantidad;
}

void ColaPacientes::push(Paciente* paciente) {

    if (paciente == nullptr) {
        return;
    }

    NodoCola* nuevo = new NodoCola(paciente);

    if (this->frente == nullptr) {
        this->frente = nuevo;
        this->final = nuevo;
    }
    else {
        this->final->next = nuevo;
        this->final = nuevo;
    }
    this->cantidad++;
}

Paciente* ColaPacientes::pop() {

    if (this->frente == nullptr) {
        return nullptr;
    }

    NodoCola* eliminado = this->frente;
    Paciente* paciente = eliminado->paciente;

    this->frente = eliminado->next;

    if (this->frente == nullptr) {
        this->final = nullptr;
    }

    delete eliminado;
    this->cantidad--;
    return paciente;
}

Paciente* ColaPacientes::front() const {

    if (this->frente == nullptr) {

        return nullptr;
    }

    return this->frente->paciente;
}

void ColaPacientes::mostrar() const {

    cout << "\n=== PACIENTES EN ESPERA ===" << endl;

    if (this->isEmpty()) {
        cout << "No hay pacientes pendientes." << endl;
        return;
    }

    NodoCola* cursor = this->frente;

    int numero = 1;

    while (cursor != nullptr) {

        cout << numero << ". " << cursor->paciente->getId() << " - " << cursor->paciente->getNombre() << endl;
        cursor = cursor->next;
        numero++;
    }
}
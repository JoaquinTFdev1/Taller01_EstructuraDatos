//
// Created by joaqu on 17-09-2026.
//
#include "ListaPacientes.h"
#include <iostream>

using namespace std;

ListaPacientes::ListaPacientes() {
    this->start = nullptr;
    this->cantidad = 0;
}

ListaPacientes::~ListaPacientes() {
    this->clear();
}

bool ListaPacientes::isEmpty() const {
    return this->start == nullptr;
}

int ListaPacientes::getSize() const {
    return this->cantidad;
}

void ListaPacientes::insertLast(
    Paciente* paciente
) {

    if (paciente == nullptr) {
        return;
    }

    NodoPaciente* nuevo = new NodoPaciente(paciente);

    if (this->start == nullptr) {
        this->start = nuevo;
        this->cantidad++;
        return;
    }

    NodoPaciente* cursor = this->start;

    while (cursor->next != nullptr) {
        cursor = cursor->next;
    }

    cursor->next = nuevo;
    this->cantidad++;
}

Paciente* ListaPacientes::get(
    int index
) const {

    if (index < 0 || index >= this->cantidad) {
        return nullptr;
    }

    NodoPaciente* cursor = this->start;

    int posicion = 0;

    while (cursor != nullptr) {

        if (posicion == index) {
            return cursor->paciente;
        }
        cursor = cursor->next;
        posicion++;
    }

    return nullptr;
}

Paciente*
ListaPacientes::getFirst() const {

    if (this->start == nullptr) {
        return nullptr;
    }

    return
        this->start->paciente;
}

Paciente*
ListaPacientes::buscarPorId(
    string id
) const {

    NodoPaciente* cursor = this->start;

    while (cursor != nullptr) {
        if (cursor->paciente->getId() == id) {
            return cursor->paciente;
        }

        cursor = cursor->next;
    }

    return nullptr;
}

void ListaPacientes::mostrar() const {

    if (this->start == nullptr) {
        cout << "No hay pacientes en la lista." << endl;
        return;
    }

    NodoPaciente* cursor =this->start;
    int numero = 1;

    while (cursor != nullptr) {
        Paciente* paciente = cursor->paciente;
        cout << numero << ". " << paciente->getId() << " - " << paciente->getNombre() << " (" << paciente->getEdad() << ")" << endl;
        numero++;
        cursor = cursor->next;
    }
}

void ListaPacientes::clear() {

    while (this->start != nullptr) {

        NodoPaciente* eliminado =this->start;
        this->start = this->start->next;

        delete eliminado->paciente;
        delete eliminado;
    }

    this->cantidad = 0;
}

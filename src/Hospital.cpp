#include "Hospital.h"
#include "Servicio.h"

Hospital::Hospital() {

    this->inicializarServicios();
}

Hospital::~Hospital() {
}

void Hospital::inicializarServicios() {

    this->servicios.insertLast(
        new Servicio("Urgencias"));

    this->servicios.insertLast(
        new Servicio("Medicina General"));

    this->servicios.insertLast(
        new Servicio("Cardiologia"));

    this->servicios.insertLast(
        new Servicio("Neurologia"));

    this->servicios.insertLast(
        new Servicio("Traumatologia"));

    this->servicios.insertLast(
        new Servicio("Cirugia"));

    this->servicios.insertLast(
        new Servicio("Pediatria"));

    this->servicios.insertLast(
        new Servicio("Hospitalizacion"));
}

void Hospital::mostrarServicios() const {
    this->servicios.mostrarServicios();
}
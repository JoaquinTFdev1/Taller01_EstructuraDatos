#include "Utilidades.h"
#include <climits>

string recortar(string texto) {

    int inicio = 0;
    if (texto.empty()) {
        return "";
    }

    int fin = texto.length() - 1;

    while (inicio <= fin && (texto[inicio] == ' ' || texto[inicio] == '\t' || texto[inicio] == '\r' || texto[inicio] == '\n')) {
        inicio++;
    }

    while (fin >= inicio && (texto[fin] == ' ' || texto[fin] == '\t' || texto[fin] == '\r' || texto[fin] == '\n')) {
        fin--;
    }

    if (inicio > fin) {
        return "";
    }

    string resultado = "";
    for (int i = inicio; i <= fin; i++) {
        resultado += texto[i];
    }
    return resultado;
}

bool convertirAEnteroNoNegativo(string texto,int& valor) {

    texto = recortar(texto);
    if (texto.empty()) {
        return false;
    }
    int numero = 0;

    for (char caracter : texto) {
        if (caracter < '0' || caracter > '9') {
            return false;
        }
        int digito = caracter - '0';
        if (numero > (INT_MAX - digito) / 10) {
            return false;
        }
        numero = numero * 10 + digito;
    }
    valor = numero;
    return true;
}

string obtenerNombreServicioCanonico(string servicio) {

    servicio = recortar(servicio);
    if (servicio == "Urgencias") {
        return "Urgencias";
    }

    if (servicio == "Medicina General") {
        return "Medicina General";
    }

    if (servicio == "Cardiologia" || servicio == "Cardiología") {
        return "Cardiologia";
    }

    if (servicio == "Neurologia" || servicio == "Neurología") {
        return "Neurologia";
    }

    if (servicio == "Traumatologia" || servicio == "Traumatología") {
        return "Traumatologia";
    }

    if (servicio == "Cirugia" || servicio == "Cirugía") {
        return "Cirugia";
    }

    if (servicio == "Pediatria" || servicio == "Pediatría") {
        return "Pediatria";
    }

    if (servicio == "Hospitalizacion" || servicio == "Hospitalización") {
        return "Hospitalizacion";
    }

    return "";
}

string nombreServicioConTildes(string servicio) {
    if (servicio == "Cardiologia") return "Cardiologia";
    if (servicio == "Neurologia") return "Neurologia";
    if (servicio == "Traumatologia") return "Traumatologia";
    if (servicio == "Cirugia") return "Cirugia";
    if (servicio == "Pediatria") return "Pediatria";
    if (servicio == "Hospitalizacion") return "Hospitalizacion";
    return servicio;
}
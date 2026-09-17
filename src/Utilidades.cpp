#include "Utilidades.h"
#include <cctype>
#include <climits>


string recortar(
    string texto
) {

    int inicio = 0;

    int fin =
        static_cast<int>(
            texto.size()
        ) - 1;


    while (
        inicio <= fin &&
        isspace(
            static_cast<unsigned char>(
                texto[inicio]
            )
        )
    ) {

        inicio++;
    }


    while (
        fin >= inicio &&
        isspace(
            static_cast<unsigned char>(
                texto[fin]
            )
        )
    ) {

        fin--;
    }


    if (
        inicio > fin
    ) {

        return "";
    }


    return texto.substr(
        inicio,
        fin - inicio + 1
    );
}


bool convertirAEnteroNoNegativo(
    string texto,
    int& valor
) {

    texto =
        recortar(texto);


    if (
        texto.empty()
    ) {

        return false;
    }


    int numero = 0;


    for (
        char caracter : texto
    ) {


        if (
            caracter < '0' ||
            caracter > '9'
        ) {

            return false;
        }


        int digito =
            caracter - '0';


        if (
            numero >
            (INT_MAX - digito) / 10
        ) {

            return false;
        }


        numero =
            numero * 10 + digito;
    }


    valor =
        numero;


    return true;
}

string obtenerNombreServicioCanonico(
    string servicio
) {

    servicio =
        recortar(servicio);


    if (
        servicio == "Urgencias"
    ) {

        return "Urgencias";
    }


    if (
        servicio == "Medicina General"
    ) {

        return "Medicina General";
    }


    if (
        servicio == "Cardiologia" ||
        servicio == "Cardiología"
    ) {

        return "Cardiologia";
    }


    if (
        servicio == "Neurologia" ||
        servicio == "Neurología"
    ) {

        return "Neurologia";
    }


    if (
        servicio == "Traumatologia" ||
        servicio == "Traumatología"
    ) {

        return "Traumatologia";
    }


    if (
        servicio == "Cirugia" ||
        servicio == "Cirugía"
    ) {

        return "Cirugia";
    }


    if (
        servicio == "Pediatria" ||
        servicio == "Pediatría"
    ) {

        return "Pediatria";
    }


    if (
        servicio == "Hospitalizacion" ||
        servicio == "Hospitalización"
    ) {

        return "Hospitalizacion";
    }


    return "";
}
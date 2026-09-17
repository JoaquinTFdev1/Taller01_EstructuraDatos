#include "ArchivoPacientes.h"

#include "Utilidades.h"


bool interpretarLineaPaciente(
    string linea,
    string& id,
    string& nombre,
    int& edad,
    string& servicio,
    string& error
) {


    string campos[4];


    int cantidadCampos = 0;


    const char* inicioCampo =
        linea.c_str();


    const char* cursor =
        inicioCampo;


    while (true) {

        if (
            *cursor == ';' ||
            *cursor == '\0'
        ) {

            if (
                cantidadCampos >= 4
            ) {

                error =
                    "la linea tiene mas de cuatro campos";

                return false;
            }

            int largoCampo =
                static_cast<int>(
                    cursor - inicioCampo
                );


            campos[cantidadCampos] =
                recortar(
                    string(
                        inicioCampo,
                        largoCampo
                    )
                );


            cantidadCampos++;


            if (
                *cursor == '\0'
            ) {

                break;
            }


            cursor++;


            inicioCampo =
                cursor;
        }

        else {

            cursor++;
        }
    }


    if (
        cantidadCampos != 4
    ) {

        error =
            "la linea debe tener el formato ID;Nombre;Edad;Servicio";

        return false;
    }


    if (
        campos[0].empty()
    ) {

        error =
            "el ID esta vacio";

        return false;
    }


    if (
        campos[1].empty()
    ) {

        error =
            "el nombre esta vacio";

        return false;
    }

    if (
        !convertirAEnteroNoNegativo(
            campos[2],
            edad
        )
    ) {

        error =
            "la edad es invalida";

        return false;
    }



    string servicioCanonico =
        obtenerNombreServicioCanonico(
            campos[3]
        );


    if (
        servicioCanonico.empty()
    ) {

        error =
            "el servicio no pertenece al hospital";

        return false;
    }


    id =
        campos[0];


    nombre =
        campos[1];


    servicio =
        servicioCanonico;


    return true;
}
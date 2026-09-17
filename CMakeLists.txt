cmake_minimum_required(VERSION 3.16)

project(Taller01_EstructuraDatos LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(taller01
        src/main.cpp
        src/Persona.cpp
        include/Paciente.h
        src/Paciente.cpp
        include/Persona.h
        include/ColaPacientes.h
        src/ColaPacientes.cpp
        include/ListaPacientes.h
        src/ListaPacientes.cpp
        include/Servicio.h
        src/Servicio.cpp
        include/ListaServicios.h
        src/ListaServicios.cpp
        include/Atencion.h
        src/Atencion.cpp
        include/PilaAtenciones.h
        src/PilaAtenciones.cpp
        include/Utilidades.h
        src/Utilidades.cpp
        include/ArchivoPacientes.h
        src/ArchivoPacientes.cpp
        include/Hospital.h
        src/Hospital.cpp
)



target_include_directories(
        taller01
        PRIVATE
        include
)


configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/pacientes.txt
        ${CMAKE_CURRENT_BINARY_DIR}/pacientes.txt
        COPYONLY
)
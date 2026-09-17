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
)

target_include_directories(taller01 PRIVATE include)
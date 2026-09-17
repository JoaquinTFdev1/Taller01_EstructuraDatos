
# Taller 01 - Estructura de Datos

## Hospital Marmaja

Proyecto desarrollado en C++ para la asignatura
Estructura de Datos de la Universidad Católica del Norte.

## Objetivo

Desarrollar un sistema de gestion de pacientes
utilizando estructuras de datos implementadas
manualmente mediante nodos y punteros.

## Integrantes

Nombre: Joaquín Esteban Torres Flores
RUT: 21.547.370-8
Usuario de GitHub: JoaquinTFdev1
Carrera: Ingeniería Civil Industrial

## Tecnologias

- C++17
- CLion
- CMake
- Git y GitHub

## Compilacion y ejecucion

1. Abrir el proyecto en CLion.
2. Esperar la configuracion de CMake.
3. Seleccionar el ejecutable taller01.
4. Presionar Run.

## Estado del proyecto

Configuracion inicial del entorno de desarrollo.
```

Por ahora el README solamente describe lo que realmente tenemos.

Más adelante lo actualizaremos a medida que implementemos las estructuras y las funcionalidades del hospital.

Antes de entregar, debes completar los datos reales de los integrantes. Si el repositorio será público, ten presente que el RUT incluido en el README también será visible públicamente.

## Paso 6. Ejecutar

Presiona el botón verde ▶ de CLion.

La salida esperada es:

```text
================================
       HOSPITAL MARMAJA
================================
Sistema iniciado correctamente.
```

Si aparece correctamente, podemos registrar el primer commit.

## Paso 7. Crear el commit 1

En la terminal escribe:

```bash
git add CMakeLists.txt src/main.cpp README.md .gitignore
```

Después:

```bash
git status
```

Comprueba que los cuatro archivos aparezcan preparados para el commit y que no se haya agregado la carpeta `cmake-build-debug`.

Ahora ejecuta:

```bash
git commit -m "Inicializa proyecto C++ y configura entorno CLion"
```

Si Git te pide configurar tu nombre y correo, utiliza los datos que quieras asociar a tus commits:

```bash
git config --global user.name "Tu Nombre"
git config --global user.email "tu-correo@example.com"
```

Reemplaza ambos valores por los tuyos y vuelve a ejecutar el commit.

<box border radius="lg" padding={3} gap={2}>
  <row align="center" gap={2}>
    <icon name="check-circle" color="success" size="lg"/>
    **Resultado del commit 1**
  </row>
  `Inicializa proyecto C++ y configura entorno CLion`

  <text color="secondary" size="sm">El repositorio contiene la primera versión funcional del programa, su configuración y su documentación inicial.</text>
</box>

---

# COMMIT 2 — Implementar Persona y Paciente

<badge color="info">Segundo avance · Programación orientada a objetos</badge>

Ahora comenzamos con las entidades del hospital.

En lugar de implementar todas las clases inmediatamente, empezaremos con dos:

```text
       Persona
          |
          v
       Paciente
```

Una persona tiene nombre y edad.

Un paciente es una persona que además posee un identificador y un servicio al que debe ser enviado.

Es una relación de herencia sencilla y justificable dentro del sistema.

## Paso 1. Crear Persona.h

Haz clic derecho en la carpeta `include`.

Selecciona `New → C/C++ Header File`, si está disponible, o simplemente `New → File`.

Crea:

`Persona.h`

Coloca:

<CodeBlock language="cpp" editable>
#pragma once

#include <string>

using namespace std;

class Persona {

protected:
    string nombre;
    int edad;

public:
    Persona(string nombre, int edad);

    virtual ~Persona();

    string getNombre() const;

    int getEdad() const;
};

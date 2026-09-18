# Taller 01 — Estructura de Datos

## Hospital Marmaja

Sistema de gestión de pacientes desarrollado en **C++17** para el Taller 01 de la asignatura **Estructura de Datos**. El programa simula el ingreso y la atención de pacientes mediante estructuras de datos implementadas manualmente con nodos y punteros.

El sistema permite cargar pacientes desde archivos de texto, mantener una cola de espera, derivar pacientes a los servicios del hospital y consultar un historial de atenciones.

## Datos del estudiante

| Dato | Información |
|---|---|
| Nombre | Joaquín Esteban Torres Flores |
| RUT | 21.547.370-8 |
| Carrera | Ingeniería Civil Industrial |
| Universidad | Universidad Católica del Norte |
| GitHub | [JoaquinTFdev1](https://github.com/JoaquinTFdev1) |

## Objetivo

Aplicar los contenidos de estructuras de datos y programación orientada a objetos mediante el desarrollo de un sistema que integre:

- Una **cola FIFO** para organizar pacientes por orden de llegada.
- Una **lista enlazada principal** que almacena los servicios del hospital.
- Una **lista enlazada de pacientes** dentro de cada servicio.
- Una **pila LIFO** que registra las atenciones realizadas.
- **Herencia** entre las clases `Persona` y `Paciente`.
- **Aritmética de punteros** para interpretar los campos de los archivos de entrada.
- **Memoria dinámica** para crear y liberar nodos y pacientes.

Las estructuras solicitadas se implementan manualmente, sin utilizar contenedores STL como reemplazo de la cola, las listas o la pila.

## Estructura del proyecto

```text
Taller01-EstructuraDatos/
│
├── CMakeLists.txt
├── README.md
├── .gitignore
├── pacientes.txt
├── pacientes_pruebas_invalidas.txt
│
├── include/
│   ├── Persona.h
│   ├── Paciente.h
│   ├── ColaPacientes.h
│   ├── ListaPacientes.h
│   ├── Servicio.h
│   ├── ListaServicios.h
│   ├── Atencion.h
│   ├── PilaAtenciones.h
│   ├── Utilidades.h
│   ├── ArchivoPacientes.h
│   └── Hospital.h
│
└── src/
    ├── main.cpp
    ├── Persona.cpp
    ├── Paciente.cpp
    ├── ColaPacientes.cpp
    ├── ListaPacientes.cpp
    ├── Servicio.cpp
    ├── ListaServicios.cpp
    ├── Atencion.cpp
    ├── PilaAtenciones.cpp
    ├── Utilidades.cpp
    ├── ArchivoPacientes.cpp
    └── Hospital.cpp
```

Los archivos `.h` contienen las declaraciones de las clases y funciones, mientras que los archivos `.cpp` contienen sus implementaciones.

## Funcionamiento del sistema

### 1. Carga de pacientes

El programa lee un archivo de texto en el que cada línea representa un paciente con el siguiente formato:

```text
ID;Nombre;Edad;Servicio
```

Ejemplo:

```text
001;Juan Perez;25;Cardiologia
002;Maria Soto;67;Urgencias
003;Pedro Rojas;43;Cirugia
```

Los registros válidos se incorporan al final de la cola de espera, respetando el orden en que aparecen en el archivo.

### 2. Atención de pacientes

Cuando se solicita atender pacientes, el sistema procesa primero a quien lleva más tiempo esperando.

El flujo de atención es:

```text
Cola de espera (FIFO)
        |
        v
Verificación del servicio
        |
        v
Lista de pacientes del servicio
        |
        v
Registro en el historial (LIFO)
```

Antes de retirar un paciente de la cola, se comprueba que su servicio exista. Después, el paciente se incorpora a la lista enlazada correspondiente y se genera un registro independiente para el historial.

### 3. Consultas

El sistema permite consultar los pacientes pendientes, revisar un servicio específico, buscar pacientes por ID y visualizar el estado general del hospital. El historial muestra las atenciones desde la más reciente hasta la más antigua.

## Servicios disponibles

El hospital se inicializa con ocho servicios:

| N.º | Servicio |
|---:|---|
| 1 | Urgencias |
| 2 | Medicina General |
| 3 | Cardiologia |
| 4 | Neurologia |
| 5 | Traumatologia |
| 6 | Cirugia |
| 7 | Pediatria |
| 8 | Hospitalizacion |

Cada servicio contiene su propia lista enlazada de pacientes.

## Menú principal

Al ejecutar el programa, se presenta el siguiente menú:

```text
1. Atender pacientes
2. Ver departamento
3. Revisar historial de atencion
4. Mostrar cola de pacientes pendientes
5. Mostrar estado general de servicios
6. Buscar paciente por ID
7. Cargar pacientes desde otro archivo
8. Salir
```

Las operaciones de consulta no modifican el orden de los pacientes en las estructuras.

## Validaciones

Durante la carga y el uso del menú, el programa contempla las siguientes situaciones:

- Archivo inexistente o inaccesible.
- Líneas vacías o con una cantidad incorrecta de campos.
- Identificador o nombre vacío.
- Edad con caracteres no numéricos.
- Servicio que no pertenece al hospital.
- Identificador duplicado entre pacientes registrados.
- Opciones del menú o cantidades de atención inválidas.
- Intentos de atender pacientes cuando la cola está vacía.
- Solicitudes de atención superiores a la cantidad disponible.

Los registros incorrectos se informan y no se incorporan a la cola.

## Gestión de memoria

Las estructuras utilizan nodos creados dinámicamente y cuentan con destructores para liberar los recursos que administran.

La **cola** es responsable de los pacientes que permanecen en espera. Cuando un paciente se atiende, el puntero se transfiere a la **lista de pacientes del servicio**, que pasa a ser responsable de liberarlo.

La **pila de atenciones** almacena copias de los datos necesarios para el historial; no conserva el puntero del paciente original.

Este diseño evita que la cola y el servicio intenten liberar el mismo paciente.

## Compilación y ejecución

### Requisitos

- Compilador compatible con C++17.
- CMake 3.16 o superior.
- CLion o un entorno equivalente para compilar y ejecutar C++.

### Desde CLion

1. Abrir la carpeta `Taller01-EstructuraDatos`.
2. Esperar a que CLion configure el proyecto mediante CMake.
3. Seleccionar la configuración de ejecución `taller01`.
4. Presionar **Run**.

El archivo `pacientes.txt` se copia al directorio de compilación mediante CMake para facilitar su lectura durante la ejecución.

### Desde una terminal

Ubicarse en la carpeta principal del proyecto y ejecutar:

```bash
cmake -S . -B build
cmake --build build --config Debug
```

La ubicación del ejecutable depende del sistema operativo y del generador de CMake utilizado. En CLion puede ejecutarse directamente desde la configuración `taller01`.

## Comprobación del funcionamiento

El programa puede revisarse manualmente desde su menú. Por ejemplo:

1. Cargar `pacientes.txt` y comprobar el orden de llegada.
2. Atender dos pacientes y verificar que desaparezcan de la cola.
3. Consultar los servicios correspondientes y comprobar que recibieron a esos pacientes.
4. Revisar el historial y comprobar que la atención más reciente aparezca primero.
5. Cargar nuevamente el mismo archivo para comprobar el rechazo de IDs duplicados.
6. Utilizar `pacientes_pruebas_invalidas.txt` para revisar los mensajes asociados a registros incorrectos.

## Control de versiones

El desarrollo se organizó en commits que reflejan la incorporación progresiva de las clases, las estructuras manuales, la lectura de archivos, las validaciones, la integración del hospital y la documentación final.

El historial del repositorio permite revisar la evolución del proyecto desde su configuración inicial hasta la versión entregada.

# Taller 01 - Estructura de Datos

## Hospital Marmaja

Programa para gestionar pacientes de un hospital. Lee un archivo de texto, mantiene una cola de espera, deriva a los pacientes a sus servicios y registra las atenciones realizadas.

## Estudiante

- **Nombre:** Joaquín Esteban Torres Flores
- **RUT:** 21.547.370-8
- **Carrera:** Ingeniería Civil Industrial
- **Universidad:** Universidad Católica del Norte
- **GitHub:** [JoaquinTFdev1](https://github.com/JoaquinTFdev1)
- **Repositorio:** [Taller01_EstructuraDatos](https://github.com/JoaquinTFdev1/Taller01_EstructuraDatos)

## Estructuras utilizadas

El programa implementa manualmente, mediante nodos y punteros, una cola FIFO para los pacientes pendientes, una lista enlazada principal de servicios, una lista enlazada de pacientes por servicio y una pila LIFO para el historial. También utiliza herencia entre `Persona` y `Paciente`, memoria dinámica y aritmética de punteros para separar los campos del archivo de entrada.

## Archivo de entrada

Al iniciar, el programa carga automáticamente `pacientes.txt`. Cada línea debe tener este formato, sin encabezado:

```text
ID;Nombre;Edad;Servicio
```

Ejemplo:

```text
001;Juan Perez;25;Cardiologia
002;Maria Soto;67;Urgencias
003;Pedro Rojas;43;Cirugia
```

Se informan y rechazan las líneas vacías, los campos faltantes o adicionales, los ID o nombres vacíos, las edades inválidas, los servicios desconocidos y los ID repetidos. Para utilizar otro conjunto de pacientes, se reemplaza el contenido de `pacientes.txt` y se vuelve a ejecutar el programa.

## Servicios

1. Urgencias
2. Medicina General
3. Cardiología
4. Neurología
5. Traumatología
6. Cirugía
7. Pediatría
8. Hospitalización

## Menú

```text
=== HOSPITAL MARMAJA ===
1. Atender pacientes
2. Ver departamento
3. Revisar historial de atencion
4. Mostrar cola de pacientes pendientes
5. Mostrar estado general de servicios
6. Buscar paciente por ID
7. Salir
```

Los pacientes se atienden en orden de llegada. Al atender uno, sale de la cola, pasa a la lista de su servicio y se guarda un registro de la atención en la pila. El historial se muestra desde la atención más reciente.

## Compilación y ejecución

**Requisitos:** compilador compatible con C++17 y CMake 3.16 o superior.

**En CLion:** abrir la carpeta del proyecto, esperar a que CMake termine de configurar, seleccionar `taller01` y ejecutar.

**Desde una terminal**, situarse en la carpeta del proyecto y ejecutar:

```bash
cmake -S . -B build
cmake --build build --config Debug
```

Ejecutar `taller01` desde su directorio de compilación para que encuentre `pacientes.txt`, que CMake copia allí. La ubicación del ejecutable puede variar según el sistema operativo y el generador utilizado.

## Organización

- `include/`: declaraciones de clases y funciones (`.h`).
- `src/`: implementaciones y programa principal (`.cpp`).
- `pacientes.txt`: datos de entrada.
- `CMakeLists.txt`: configuración de compilación.

Al terminar, los destructores liberan los nodos y los pacientes que permanecen en la cola o que fueron derivados a los servicios. El historial guarda copias de los datos de atención, no los punteros originales de los pacientes.

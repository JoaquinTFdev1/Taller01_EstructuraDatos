# Taller 01 - Estructura de Datos

## Hospital Marmaja

Este proyecto consiste en un sistema de gestión de pacientes para el Hospital Marmaja. Su funcionamiento se basa en recibir pacientes desde un archivo de texto, organizarlos según su orden de llegada, atenderlos y derivarlos al servicio correspondiente.

Para administrar la información se implementaron manualmente una cola, listas enlazadas y una pila. El sistema también permite consultar pacientes, revisar los servicios del hospital y visualizar el historial de atenciones.

## Datos del estudiante

| Dato | Información |
|---|---|
| Nombre | Joaquín Esteban Torres Flores |
| RUT | 21.547.370-8 |
| Carrera | Ingeniería Civil Industrial |
| Universidad | Universidad Católica del Norte |
| Usuario de GitHub | [JoaquinTFdev1](https://github.com/JoaquinTFdev1) |
| Repositorio | [Taller01_EstructuraDatos](https://github.com/JoaquinTFdev1/Taller01_EstructuraDatos) |

## 1. Objetivo del programa

El objetivo es administrar el flujo de pacientes de un hospital utilizando estructuras de datos implementadas mediante nodos y punteros.

El programa debe mantener el orden de llegada de los pacientes, distribuirlos entre ocho servicios y registrar cada atención en un historial. Además, debe controlar registros incorrectos, pacientes duplicados y operaciones sobre estructuras vacías.

## 2. Estructura del proyecto

```text
Taller01-EstructuraDatos/
│
├── CMakeLists.txt
├── README.md
├── .gitignore
├── pacientes.txt
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

La carpeta `include` contiene las declaraciones de las clases y funciones. La carpeta `src` contiene sus implementaciones y el programa principal.

Cada clase tiene una responsabilidad específica, lo que permite mantener separadas las operaciones de la cola, las listas, la pila y la administración general del hospital.

## 3. Estructuras de datos

### Cola de pacientes

La cola almacena a los pacientes que todavía no han sido atendidos.

Su funcionamiento es **FIFO (First In, First Out)**: el primer paciente que ingresa es el primero que se atiende.

```text
Frente                               Final
  |                                    |
  v                                    v
[Paciente 1] -> [Paciente 2] -> [Paciente 3]
```

Los nuevos pacientes se incorporan al final. Cuando se realiza una atención, se retira al paciente que está al frente.

### Lista enlazada de servicios

El hospital mantiene una lista enlazada principal que contiene los ocho servicios:

1. Urgencias.
2. Medicina General.
3. Cardiología.
4. Neurología.
5. Traumatología.
6. Cirugía.
7. Pediatría.
8. Hospitalización.

Cada nodo de esta lista almacena un servicio y un enlace hacia el siguiente.

### Lista de pacientes por servicio

Cada servicio posee una lista enlazada independiente para almacenar a sus pacientes.

De esta manera, los pacientes derivados a Cardiología se almacenan en la lista de Cardiología, los de Urgencias en la lista de Urgencias, y así sucesivamente.

```text
Hospital
   |
   v
Urgencias --------> Paciente -> Paciente
   |
   v
Medicina General -> Paciente
   |
   v
Cardiologia -----> Paciente -> Paciente
   |
  ...
```

### Pila de atenciones

La pila almacena el historial de las atenciones realizadas.

Su funcionamiento es **LIFO (Last In, First Out)**: la última atención registrada aparece primero al consultar el historial.

```text
Cima
 |
 v
[Última atención]
        |
        v
[Atención anterior]
        |
        v
[Primera atención]
```

El historial guarda los datos de cada atención de forma independiente del paciente almacenado en su servicio.

## 4. Clases y funciones

### 4.1. `Persona`

Es la clase base de la jerarquía. Reúne la información general que posee una persona.

**Atributos:**

- `nombre`: nombre de la persona.
- `edad`: edad de la persona.

**Funciones:**

| Función | Funcionamiento |
|---|---|
| `Persona(nombre, edad)` | Inicializa el nombre y la edad recibidos. |
| `~Persona()` | Destructor de la clase base. |
| `getNombre()` | Devuelve el nombre almacenado. |
| `getEdad()` | Devuelve la edad almacenada. |

### 4.2. `Paciente`

Hereda de `Persona` y agrega los datos necesarios para identificar y derivar a un paciente dentro del hospital.

**Atributos propios:**

- `id`: identificador del paciente.
- `servicio`: servicio al que debe ser derivado.

El nombre y la edad se obtienen de la clase `Persona`.

**Funciones:**

| Función | Funcionamiento |
|---|---|
| `Paciente(id, nombre, edad, servicio)` | Crea un paciente, inicializa los datos heredados y almacena su identificador y servicio. |
| `~Paciente()` | Destructor del paciente. |
| `getId()` | Devuelve su identificador. |
| `getServicio()` | Devuelve el servicio solicitado. |

La herencia evita volver a declarar el nombre y la edad en la clase `Paciente`.

### 4.3. `ColaPacientes`

Administra los pacientes que se encuentran esperando atención.

Cada `NodoCola` almacena un puntero a un paciente y un puntero `next` hacia el siguiente nodo. La cola mantiene los punteros `frente` y `final`, además de la cantidad de pacientes.

**Funciones:**

| Función | Funcionamiento |
|---|---|
| `ColaPacientes()` | Inicializa la cola vacía, con sus punteros en `nullptr` y cantidad cero. |
| `~ColaPacientes()` | Libera los nodos y los pacientes que permanezcan en espera. |
| `isEmpty()` | Comprueba si la cola está vacía. |
| `getSize()` | Devuelve la cantidad de pacientes pendientes. |
| `push(paciente)` | Crea un nodo y agrega el paciente al final de la cola. |
| `pop()` | Retira el primer nodo y devuelve el puntero al paciente. |
| `front()` | Permite consultar al primer paciente sin retirarlo. |
| `buscarPorId(id)` | Recorre la cola hasta encontrar un paciente con el identificador solicitado. |
| `mostrar()` | Muestra los pacientes pendientes en orden de llegada. |

En `pop()`, se elimina el nodo de la cola, pero no el paciente. Esto permite trasladarlo posteriormente a la lista del servicio correspondiente.

### 4.4. `ListaPacientes`

Representa la lista enlazada utilizada dentro de cada servicio.

Cada `NodoPaciente` contiene un puntero al paciente y otro al siguiente nodo. El atributo `start` apunta al primer nodo y `cantidad` mantiene el número de pacientes almacenados.

**Funciones:**

| Función | Funcionamiento |
|---|---|
| `ListaPacientes()` | Inicializa la lista vacía. |
| `~ListaPacientes()` | Llama a `clear()` para liberar sus recursos. |
| `isEmpty()` | Indica si la lista no contiene pacientes. |
| `getSize()` | Devuelve la cantidad de pacientes de la lista. |
| `insertLast(paciente)` | Recorre la lista e incorpora un nuevo nodo al final. |
| `get(index)` | Obtiene el paciente ubicado en una posición determinada. |
| `getFirst()` | Devuelve el primer paciente sin retirarlo. |
| `buscarPorId(id)` | Recorre los nodos y devuelve el paciente cuyo ID coincide. |
| `mostrar()` | Muestra el nombre y la edad de los pacientes almacenados. |
| `clear()` | Elimina los nodos y los pacientes de la lista, dejándola vacía. |

La inserción, búsqueda y consulta se realizan recorriendo los enlaces entre nodos.

### 4.5. `Servicio`

Representa uno de los departamentos del hospital.

**Atributos:**

- `nombre`: nombre del servicio.
- `pacientes`: lista enlazada propia de pacientes.

**Funciones:**

| Función | Funcionamiento |
|---|---|
| `Servicio(nombre)` | Crea el servicio con el nombre recibido. |
| `~Servicio()` | Destructor del servicio; su lista de pacientes se destruye junto con él. |
| `getNombre()` | Devuelve el nombre del servicio. |
| `getCantidadPacientes()` | Consulta la cantidad de pacientes de su lista. |
| `agregarPaciente(paciente)` | Incorpora un paciente al final de la lista del servicio. |
| `buscarPaciente(id)` | Busca un paciente dentro de ese servicio. |
| `mostrarPacientes()` | Muestra el nombre del departamento, su cantidad de pacientes y el contenido de su lista. |

Un servicio no administra directamente los nodos: utiliza los métodos de su objeto `ListaPacientes`.

### 4.6. `ListaServicios`

Es la lista enlazada principal del hospital.

Cada `NodoServicio` contiene un puntero a un objeto `Servicio` y un enlace al siguiente nodo.

**Funciones:**

| Función | Funcionamiento |
|---|---|
| `ListaServicios()` | Inicializa la lista principal vacía. |
| `~ListaServicios()` | Libera los servicios y sus nodos mediante `clear()`. |
| `isEmpty()` | Comprueba si no existen servicios almacenados. |
| `getSize()` | Devuelve la cantidad de servicios. |
| `insertLast(servicio)` | Incorpora un servicio al final de la lista. |
| `get(index)` | Obtiene el servicio que ocupa una posición determinada. |
| `buscarServicio(nombre)` | Recorre la lista hasta encontrar un servicio por su nombre. |
| `buscarPaciente(id, nombreServicio)` | Recorre los servicios y busca el paciente dentro de cada uno. Si lo encuentra, también entrega el nombre del servicio. |
| `mostrarServicios()` | Muestra los ocho servicios numerados. |
| `mostrarEstadoGeneral()` | Recorre los servicios, muestra la cantidad de pacientes de cada uno y devuelve el total de derivados. |
| `clear()` | Elimina los nodos y destruye los servicios almacenados. |

La búsqueda general de un paciente utiliza las listas de pacientes que ya posee cada servicio; no necesita una lista adicional.

### 4.7. `Atencion`

Representa un registro del historial.

**Atributos:**

- `id`: identificador del paciente atendido.
- `nombre`: nombre del paciente.
- `edad`: edad del paciente.
- `servicio`: servicio al que fue derivado.

**Funciones:**

| Función | Funcionamiento |
|---|---|
| `Atencion()` | Inicializa un registro vacío. |
| `Atencion(paciente)` | Copia los datos del paciente para generar un registro de atención. |
| `~Atencion()` | Destructor del registro. |
| `getId()` | Devuelve el ID almacenado. |
| `getNombre()` | Devuelve el nombre almacenado. |
| `getEdad()` | Devuelve la edad almacenada. |
| `getServicio()` | Devuelve el servicio registrado. |

La atención conserva sus propios datos y no guarda el puntero original del paciente.

### 4.8. `PilaAtenciones`

Administra el historial de atenciones del hospital.

Cada `NodoAtencion` contiene un registro `Atencion` y un puntero al siguiente nodo. `topNode` apunta a la cima de la pila.

**Funciones:**

| Función | Funcionamiento |
|---|---|
| `PilaAtenciones()` | Inicializa la pila vacía. |
| `~PilaAtenciones()` | Libera los nodos almacenados mediante `clear()`. |
| `isEmpty()` | Comprueba si la pila está vacía. |
| `getSize()` | Devuelve la cantidad de atenciones registradas. |
| `push(atencion)` | Crea un nodo y lo incorpora a la cima. |
| `pop(atencion)` | Retira la atención de la cima y entrega sus datos. |
| `top(atencion)` | Consulta la atención más reciente sin retirarla. |
| `mostrar()` | Recorre el historial desde la atención más reciente hasta la más antigua. |
| `clear()` | Elimina todos los nodos del historial. |

Cada vez que un paciente es atendido se crea un registro y se incorpora con `push()`. La consulta con `mostrar()` no elimina las atenciones.

### 4.9. Funciones de `Utilidades`

Estas funciones permiten revisar los datos ingresados y mantener los nombres de los servicios de forma consistente.

| Función | Funcionamiento |
|---|---|
| `recortar(texto)` | Elimina espacios y saltos de línea sobrantes al comienzo y al final de un texto. |
| `convertirAEnteroNoNegativo(texto, valor)` | Comprueba que el texto contenga dígitos y entrega el número correspondiente. Rechaza caracteres incorrectos y valores que excedan el límite admitido. |
| `obtenerNombreServicioCanonico(servicio)` | Comprueba si el servicio pertenece al hospital y devuelve el nombre utilizado internamente. |
| `nombreServicioConTildes(servicio)` | Entrega el nombre del servicio con tildes para mostrarlo en pantalla. |

Por ejemplo, `Cardiologia` y `Cardiología` se reconocen como el mismo servicio. Internamente se utiliza un único nombre para que las búsquedas y derivaciones sean consistentes.

### 4.10. Función de `ArchivoPacientes`

**`interpretarLineaPaciente(linea, id, nombre, edad, servicio, error)`**

Recibe una línea del archivo y comprueba que tenga los cuatro campos establecidos:

```text
ID;Nombre;Edad;Servicio
```

Su funcionamiento es el siguiente:

1. Recorre los caracteres de la línea buscando los puntos y coma.
2. Separa el contenido en cuatro campos.
3. Elimina los espacios sobrantes de cada campo.
4. Verifica que el ID y el nombre no estén vacíos.
5. Comprueba que la edad sea válida.
6. Verifica que el servicio pertenezca al hospital.
7. Si todo es correcto, entrega los datos y devuelve `true`.
8. Si encuentra un problema, entrega el motivo en `error` y devuelve `false`.

Durante la separación de los campos se utiliza aritmética de punteros: el recorrido avanza por los caracteres y calcula la distancia entre el inicio y el final de cada campo.

### 4.11. `Hospital`

Es la clase que coordina las estructuras y las operaciones principales.

**Atributos:**

- `colaEspera`: pacientes que todavía esperan atención.
- `servicios`: lista enlazada principal con los ocho servicios.
- `historial`: pila de atenciones realizadas.

**Funciones:**

| Función | Funcionamiento |
|---|---|
| `Hospital()` | Crea el hospital e inicializa sus servicios. |
| `~Hospital()` | Destructor del hospital; sus estructuras se destruyen junto con él. |
| `inicializarServicios()` | Crea e incorpora los ocho servicios establecidos en el enunciado. |
| `existePaciente(id)` | Comprueba si el ID ya se encuentra en la cola o en alguno de los servicios. |
| `cargarPacientesDesdeArchivo(ruta, mostrarResumen)` | Abre el archivo, procesa sus líneas, rechaza registros incorrectos o duplicados e incorpora los pacientes válidos a la cola. Puede mostrar un resumen de la carga. |
| `mostrarCola()` | Solicita a la cola que muestre los pacientes pendientes. |
| `mostrarServicios()` | Muestra la lista de servicios disponibles. |
| `atenderPacientes(cantidad)` | Atiende pacientes siguiendo FIFO, los deriva al servicio correspondiente y registra sus atenciones. |
| `mostrarDepartamento(numero)` | Obtiene el servicio seleccionado y muestra sus pacientes. |
| `mostrarHistorial()` | Muestra el contenido de la pila de atenciones. |
| `mostrarEstadoGeneral()` | Presenta los pacientes derivados, los pendientes y el total registrado. |
| `buscarPaciente(id)` | Busca al paciente en la cola y, si no está allí, en los servicios. Muestra su información y ubicación. |

#### Funcionamiento de `atenderPacientes()`

Esta función conecta las tres estructuras principales.

Primero comprueba que la cantidad solicitada sea válida y que existan pacientes pendientes. Si se solicita atender más pacientes de los disponibles, utiliza la cantidad que realmente hay en la cola.

Para cada atención:

1. Consulta al primer paciente mediante `front()`.
2. Busca el servicio indicado por el paciente.
3. Si el servicio existe, retira al paciente mediante `pop()`.
4. Incorpora el paciente a la lista enlazada del servicio.
5. Crea un registro `Atencion` con sus datos.
6. Agrega el registro a la pila mediante `push()`.
7. Muestra los datos del paciente y el servicio al que fue enviado.

El servicio se comprueba antes de retirar al paciente. Si no existe, el paciente conserva su posición en la cola.

#### Funcionamiento de `cargarPacientesDesdeArchivo()`

La función abre el archivo solicitado y lo lee línea por línea. Cada línea se entrega a `interpretarLineaPaciente()`.

Si el registro es inválido, se muestra el motivo y se continúa con la siguiente línea. Si es válido, se comprueba que su ID no esté registrado previamente.

Cuando el ID no está repetido, se crea el paciente y se incorpora al final de la cola. La función lleva la cuenta de los pacientes incorporados y rechazados.

## 5. Funcionamiento del programa principal

El archivo `main.cpp` crea un objeto `Hospital` y carga automáticamente el archivo `pacientes.txt`.

Después muestra un menú que se repite hasta que el usuario selecciona la opción de salir.

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

### Opción 1. Atender pacientes

Muestra la cola de espera y solicita la cantidad de pacientes que se desea atender.

Después llama a `atenderPacientes()`, que procesa a los pacientes respetando su orden de llegada.

### Opción 2. Ver departamento

Muestra los ocho servicios numerados y solicita seleccionar uno.

Luego llama a `mostrarDepartamento()` para consultar la cantidad de pacientes del servicio y mostrar sus nombres y edades.

### Opción 3. Revisar historial de atención

Llama a `mostrarHistorial()`.

Las atenciones se presentan desde la más reciente hasta la más antigua, respetando el funcionamiento LIFO de la pila.

### Opción 4. Mostrar cola de pacientes pendientes

Llama a `mostrarCola()` para consultar los pacientes que todavía esperan atención.

Esta opción no retira ni modifica a los pacientes.

### Opción 5. Mostrar estado general de servicios

Llama a `mostrarEstadoGeneral()`.

El programa presenta la cantidad de pacientes de cada servicio, el total de derivados, los pendientes y el total registrado en el hospital.

### Opción 6. Buscar paciente por ID

Solicita el identificador del paciente y llama a `buscarPaciente()`.

La búsqueda revisa primero la cola y luego los servicios. Si encuentra al paciente, muestra sus datos e indica si está en espera o derivado. Si no existe, informa que no fue encontrado.

### Opción 7. Salir

Finaliza el ciclo del menú y termina la ejecución del programa.

Al terminar, se ejecutan los destructores de las estructuras que pertenecen al hospital.

## 6. Archivo de entrada

El programa utiliza `pacientes.txt`, ubicado en la carpeta principal del proyecto.

El archivo se carga automáticamente al iniciar. No contiene una fila de encabezados y cada línea debe respetar el siguiente formato:

```text
ID;Nombre;Edad;Servicio
```

Ejemplo:

```text
001;Juan Perez;25;Cardiologia
002;Maria Soto;67;Urgencias
003;Pedro Rojas;43;Cirugia
004;Ana Torres;12;Pediatria
005;Luis Diaz;31;Traumatologia
```

Los pacientes se incorporan a la cola en el mismo orden en que aparecen en el archivo.

Para trabajar con otros pacientes, se reemplaza el contenido de `pacientes.txt` antes de iniciar nuevamente el programa. El archivo utilizado durante la ejecución debe encontrarse en el directorio desde el que el programa lo lee.

## 7. Validaciones y manejo de errores

El sistema contempla las siguientes situaciones:

| Situación | Comportamiento |
|---|---|
| Archivo inexistente | Informa que no pudo abrirse. |
| Línea vacía | Rechaza la línea y continúa con la siguiente. |
| Campos faltantes o adicionales | Rechaza el registro. |
| ID vacío | Rechaza el registro. |
| Nombre vacío | Rechaza el registro. |
| Edad inválida | Rechaza el registro. |
| Servicio desconocido | Rechaza el registro. |
| ID duplicado | No incorpora nuevamente al paciente. |
| Cola vacía | Informa que no hay pacientes pendientes. |
| Historial vacío | Informa que no hay atenciones registradas. |
| Cantidad de atención inválida | Informa el error y no realiza la operación. |
| Cantidad mayor a la disponible | Atiende solamente a los pacientes existentes. |
| Departamento inválido | Informa que la selección no corresponde a un servicio. |
| Paciente no encontrado | Informa que no existe un paciente con ese ID. |
| Opción de menú inválida | Informa el error y vuelve a mostrar el menú. |

La validación de duplicados revisa tanto los pacientes pendientes como los que ya fueron derivados a un servicio.

## 8. Memoria dinámica

Los pacientes, servicios y nodos se crean dinámicamente. Cada estructura se encarga de liberar los recursos que le pertenecen.

La cola administra los pacientes que siguen esperando. Cuando uno es atendido, `pop()` elimina su nodo, pero devuelve el puntero al paciente para que pueda incorporarse a la lista del servicio.

Desde ese momento, la lista de pacientes del servicio queda a cargo de liberar ese objeto.

El historial almacena una copia de los datos de la atención, por lo que sus registros no dependen del puntero original del paciente.

Al terminar el programa, los destructores liberan los nodos y los objetos que permanecen almacenados en las estructuras.

## 9. Compilación y ejecución

El proyecto está organizado para compilarse mediante su archivo `CMakeLists.txt`.

Desde la carpeta principal puede configurarse y compilarse con:

```bash
cmake -S . -B build
cmake --build build --config Debug
```

Una vez compilado, se ejecuta el programa `taller01` desde el directorio de ejecución que contiene `pacientes.txt`.

También puede abrirse el proyecto en CLion y ejecutar directamente la configuración `taller01`.

## 10. Control de versiones

El desarrollo se realizó utilizando Git y GitHub. Los commits registran la incorporación progresiva de las clases, las estructuras de datos, la lectura del archivo, las validaciones, la integración del hospital y los ajustes de funcionamiento.

El repositorio del proyecto se encuentra en:

https://github.com/JoaquinTFdev1/Taller01_EstructuraDatos

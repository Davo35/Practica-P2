#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

// Estructura para representar a un paciente
struct Paciente {
    string nombre;
    string telefono;
    string id;
    int edad; // Nueva variable para la edad

    Paciente(string n, string t, string i, int e) : nombre(n), telefono(t), id(i), edad(e) {}
};

// Estructura para representar un consultorio
struct Consultorio {
    string nombre;
    string doctor;
    int capacidadMaxima;

    Consultorio(string n, string d, int c) : nombre(n), doctor(d), capacidadMaxima(c) {}
};

// Función para crear un consultorio
Consultorio crearConsultorio() {
    string nombre, doctor;
    int capacidadMaxima;

    cout << "Ingrese el nombre del consultorio: ";
    cin >> nombre;
    cout << "Ingrese el nombre del doctor: ";
    cin >> doctor;
    cout << "Ingrese la capacidad máxima: ";
    cin >> capacidadMaxima;

    return Consultorio(nombre, doctor, capacidadMaxima);
}

// Función para registrar un paciente en un consultorio
bool registrarPaciente(Consultorio &consultorio, std::queue<Paciente> &pacientes) {
    if (pacientes.size() < consultorio.capacidadMaxima) {
        string nombre, telefono, id;
        int edad;

        cout << "Ingrese el nombre del paciente: ";
        cin >> nombre;
        cout << "Ingrese el teléfono del paciente: ";
        cin >> telefono;
        cout << "Ingrese el ID del paciente: ";
        cin >> id;
        cout << "Ingrese la edad del paciente: ";
        cin >> edad;

        pacientes.push(Paciente(nombre, telefono, id, edad));
        return true;
    } else {
        cout << "El consultorio está lleno." << endl;
        return false;
    }
}

// Función para mostrar pacientes en un consultorio
void mostrarPacientes(std::queue<Paciente> &pacientes, const string &nombreConsultorio) {
    cout << "Pacientes en el consultorio " << nombreConsultorio << ":" << endl;

    int opcion;
    cout << "Desea ordenar los pacientes por edad? (1. Sí / 2. No): ";
    cin >> opcion;

    // Cola auxiliar para almacenar pacientes ordenados
    std::queue<Paciente> colaAuxiliar;

    if (opcion == 1) {
        // Ordenar pacientes de mayor a menor edad
        while (!pacientes.empty()) {
            Paciente p = pacientes.front();
            pacientes.pop();
            colaAuxiliar.push(p);
        }

        // Ordenar la cola auxiliar usando selección
        while (!colaAuxiliar.empty()) {
            Paciente mayor = colaAuxiliar.front();
            std::queue<Paciente> tempQueue;
            bool found = false;

            // Buscar el paciente mayor
            while (!colaAuxiliar.empty()) {
                Paciente p = colaAuxiliar.front();
                colaAuxiliar.pop();
                if (p.edad > mayor.edad) {
                    tempQueue.push(mayor);
                    mayor = p;
                } else {
                    tempQueue.push(p);
                }
            }

            // Agregar el paciente mayor a la cola original
            colaAuxiliar.push(mayor);
            while (!tempQueue.empty()) {
                colaAuxiliar.push(tempQueue.front());
                tempQueue.pop();
            }
        }

        // Mostrar pacientes ordenados
        while (!colaAuxiliar.empty()) {
            Paciente p = colaAuxiliar.front();
            cout << "Nombre: " << p.nombre << ", Teléfono: " << p.telefono << ", ID: " << p.id << ", Edad: " << p.edad << endl;
            colaAuxiliar.pop();
            pacientes.push(p); // Devolver a la cola original
        }
    } else {
        // Mostrar pacientes sin ordenar
        while (!pacientes.empty()) {
            Paciente p = pacientes.front();
            cout << "Nombre: " << p.nombre << ", Teléfono: " << p.telefono << ", ID: " << p.id << ", Edad: " << p.edad << endl;
            pacientes.pop();
            colaAuxiliar.push(p); // Mantener en la cola auxiliar
        }

        // Devolver a la cola original
        while (!colaAuxiliar.empty()) {
            pacientes.push(colaAuxiliar.front());
            colaAuxiliar.pop();
        }
    }
}

// Función para buscar un paciente en un consultorio
void buscarPaciente(const std::queue<Paciente> &pacientes, const string &id, const string &nombreConsultorio) {
    std::queue<Paciente> copia = pacientes;
    bool encontrado = false;
    while (!copia.empty()) {
        Paciente p = copia.front();
        if (p.id == id) {
            cout << "Paciente encontrado en " << nombreConsultorio << ": " << p.nombre << ", Teléfono: " << p.telefono << ", Edad: " << p.edad << endl;
            encontrado = true;
            break;
        }
        copia.pop();
    }
    if (!encontrado) {
        cout << "Paciente no encontrado en " << nombreConsultorio << "." << endl;
    }
}

// Función para eliminar un paciente de un consultorio
bool eliminarPaciente(Consultorio &consultorio, std::queue<Paciente> &pacientes, const string &id) {
    std::queue<Paciente> copia;
    bool encontrado = false;

    while (!pacientes.empty()) {
        Paciente p = pacientes.front();
        pacientes.pop();

        if (p.id == id) {
            cout << "Paciente " << p.nombre << " eliminado." << endl;
            encontrado = true;
            continue; // No añadir a la copia
        }
        copia.push(p);
    }

    pacientes = copia; // Reemplazar con los que quedan
    return encontrado;
}

// Función principal
int main() {
    Consultorio consultorio = crearConsultorio();
    std::queue<Paciente> pacientes; // Cola de pacientes
    int opcion;

    do {
        cout << "\nMenu:\n";
        cout << "1. Registrar paciente\n";
        cout << "2. Mostrar pacientes\n";
        cout << "3. Buscar paciente\n";
        cout << "4. Eliminar paciente\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarPaciente(consultorio, pacientes);
                break;
            case 2:
                mostrarPacientes(pacientes, consultorio.nombre);
                break;
            case 3: {
                string id;
                cout << "Ingrese el ID del paciente: ";
                cin >> id;
                buscarPaciente(pacientes, id, consultorio.nombre);
                break;
            }
            case 4: {
                string id;
                cout << "Ingrese el ID del paciente a eliminar: ";
                cin >> id;
                eliminarPaciente(consultorio, pacientes, id);
                break;
            }
            case 5:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no válida." << endl;
                break;
        }
    } while (opcion != 5);

    return 0;
}


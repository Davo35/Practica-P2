#include <iostream>
#include <queue>
#include <string>

// Estructura para representar un invitado
struct Invitado {
    std::string nombre;         // Nombre del invitado
    std::string codigoInvitacion; // Código de invitación

    // Constructor
    Invitado(const std::string& n, const std::string& c)
        : nombre(n), codigoInvitacion(c) {}
};

// Función para mostrar el menú
void mostrarMenu() {
    std::cout << "\nMenu de Entrada a la Fiesta:\n";
    std::cout << "1. Agregar Invitado\n";
    std::cout << "2. Mostrar Invitados en Cola\n";
    std::cout << "3. Permitir Entrada\n";
    std::cout << "4. Salir\n";
    std::cout << "Seleccione una opción: ";
}

// Función principal
int main() {
    std::queue<Invitado> cola; // Declaración de la cola para invitados
    int opcion;

    do {
        mostrarMenu(); // Mostrar el menú
        std::cin >> opcion; // Leer la opción del usuario
        std::cin.ignore(); // Limpiar el buffer

        switch (opcion) {
            case 1: {
                // Agregar Invitado a la Cola
                std::string nombre, codigoInvitacion;

                std::cout << "Ingrese el nombre del invitado: ";
                std::getline(std::cin, nombre); // Leer el nombre
                std::cout << "Ingrese el código de invitación: ";
                std::getline(std::cin, codigoInvitacion); // Leer el código

                // Crear un nuevo invitado y agregarlo a la cola
                cola.push(Invitado(nombre, codigoInvitacion));
                std::cout << "Invitado agregado a la cola.\n";
                break;
            }
            case 2: {
                // Mostrar Invitados en la Cola
                std::cout << "\nInvitados en Cola:\n";
                if (cola.empty()) {
                    std::cout << "No hay invitados en la cola.\n"; // Mensaje si la cola está vacía
                } else {
                    std::queue<Invitado> temp = cola; // Copia de la cola
                    while (!temp.empty()) {
                        Invitado invitado = temp.front(); // Obtener el invitado frontal
                        std::cout << "Nombre: " << invitado.nombre
                                  << ", Código de Invitación: " << invitado.codigoInvitacion << std::endl;
                        temp.pop(); // Eliminar el invitado frontal
                    }
                }
                break;
            }
            case 3: {
                // Permitir Entrada al Primer Invitado en la Cola
                if (!cola.empty()) {
                    Invitado invitado = cola.front(); // Obtener el invitado frontal
                    std::cout << "Permitiendo entrada a: " << invitado.nombre
                              << " con código de invitación: " << invitado.codigoInvitacion << std::endl;
                    cola.pop(); // Eliminar el invitado que entra
                } else {
                    std::cout << "No hay invitados en la cola para permitir entrada.\n"; // Mensaje si no hay invitados
                }
                break;
            }
            case 4:
                std::cout << "Saliendo del programa.\n"; // Mensaje de salida
                break;
            default:
                std::cout << "Opción inválida. Intente nuevamente.\n"; // Manejo de opción inválida
                break;
        }
    } while (opcion != 4); // Continuar hasta que el usuario elija salir

    return 0; // Fin del programa
}

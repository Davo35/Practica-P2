#include <iostream>
#include <vector>
#include <string>

// Definición de la estructura Cliente
struct Cliente {
    std::string nombre;         // Nombre del cliente
    int numeroCuenta;           // Número de cuenta del cliente
    double saldo;               // Saldo en la cuenta

    // Constructor para facilitar la creación de nuevos clientes
    Cliente(const std::string& n, int nc, double s)
        : nombre(n), numeroCuenta(nc), saldo(s) {}
};

// Función para mostrar el menú
void mostrarMenu() {
    std::cout << "\nMenu del Banco:\n";
    std::cout << "1. Agregar cliente\n";
    std::cout << "2. Mostrar clientes\n";
    std::cout << "3. Buscar cliente\n";
    std::cout << "4. Salir\n";
    std::cout << "Seleccione una opción: ";
}

// Función para leer un número de cuenta de manera segura
int leerNumeroCuenta() {
    int numeroCuenta;
    while (true) {
        std::cout << "Ingrese el número de cuenta (solo números): ";
        std::cin >> numeroCuenta;

        // Comprobar si la entrada es válida
        if (std::cin.fail()) {
            std::cin.clear(); // Limpiar el estado de error
            std::cin.ignore(10000, '\n'); // Ignorar la línea
            std::cout << "Incorrecto, ingresar de nuevo. Asegúrese de ingresar solo números.\n";
        } else {
            std::cin.ignore(10000, '\n'); // Limpiar el buffer
            return numeroCuenta; // Devolver el número de cuenta válido
        }
    }
}

// Función principal
int main() {
    std::vector<Cliente> clientes; // Vector para almacenar clientes
    int opcion;

    do {
        mostrarMenu(); // Mostrar el menú
        std::cin >> opcion; // Leer la opción del usuario
        std::cin.ignore(); // Limpiar el buffer

        switch (opcion) {
            case 1: {
                // Agregar cliente
                std::string nombre;
                int numeroCuenta;
                double saldo;

                std::cout << "Ingrese el nombre del cliente: ";
                std::getline(std::cin, nombre); // Leer el nombre del cliente
                numeroCuenta = leerNumeroCuenta(); // Llamar a la función para leer el número de cuenta
                std::cout << "Ingrese el saldo: ";
                std::cin >> saldo; // Leer el saldo del cliente

                // Crear un nuevo cliente y agregarlo al vector
                clientes.emplace_back(nombre, numeroCuenta, saldo);
                std::cout << "Cliente agregado con éxito.\n"; // Confirmación de éxito
                break;
            }
            case 2: {
                // Mostrar todos los clientes
                std::cout << "\nClientes del Banco:\n";
                for (const auto& cliente : clientes) {
                    // Mostrar información de cada cliente
                    std::cout << "Nombre: " << cliente.nombre
                              << ", Número de Cuenta: " << cliente.numeroCuenta
                              << ", Saldo: $" << cliente.saldo << std::endl;
                }
                break;
            }
            case 3: {
                // Buscar cliente
                int numeroCuentaBuscado = leerNumeroCuenta(); // Llamar a la función para leer el número de cuenta

                bool encontrado = false; // Variable para rastrear si se encuentra el cliente
                for (const auto& cliente : clientes) {
                    if (cliente.numeroCuenta == numeroCuentaBuscado) {
                        // Si se encuentra al cliente, mostrar sus datos
                        std::cout << "Cliente encontrado:\n";
                        std::cout << "Nombre: " << cliente.nombre
                                  << ", Saldo: $" << cliente.saldo << std::endl;
                        encontrado = true; // Marcar como encontrado
                        break; // Salir del bucle
                    }
                }
                if (!encontrado) {
                    std::cout << "Cliente no encontrado.\n"; // Mensaje si no se encuentra
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

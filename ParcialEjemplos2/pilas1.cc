#include <iostream>
#include <stack>
#include <string>

// Estructura para representar un artículo
struct Articulo {
    std::string nombre; // Nombre del artículo
    double precio;      // Precio del artículo
    int cantidad;       // Cantidad del artículo

    // Constructor
    Articulo(const std::string& n, double p, int c)
        : nombre(n), precio(p), cantidad(c) {}
};

// Función para mostrar el menú
void mostrarMenu() {
    std::cout << "\nMenu del Supermercado:\n";
    std::cout << "1. Agregar Artículo\n";
    std::cout << "2. Mostrar Artículos\n";
    std::cout << "3. Salir\n";
    std::cout << "Seleccione una opción: ";
}

// Función principal
int main() {
    std::stack<Articulo> pila; // Declaración de la pila para artículos
    int opcion;

    do {
        mostrarMenu(); // Mostrar el menú
        std::cin >> opcion; // Leer la opción del usuario
        std::cin.ignore(); // Limpiar el buffer

        switch (opcion) {
            case 1: {
                // Agregar Artículo a la Pila
                std::string nombre;
                double precio;
                int cantidad;

                std::cout << "Ingrese el nombre del artículo: ";
                std::getline(std::cin, nombre); // Leer el nombre
                std::cout << "Ingrese el precio del artículo: ";
                std::cin >> precio; // Leer el precio
                std::cout << "Ingrese la cantidad del artículo: ";
                std::cin >> cantidad; // Leer la cantidad

                // Crear un nuevo artículo y agregarlo a la pila
                pila.push(Articulo(nombre, precio, cantidad));
                std::cout << "Artículo agregado a la Pila.\n";
                break;
            }
            case 2: {
                // Mostrar Artículos de la Pila
                std::cout << "\nContenido de la Pila:\n";
                if (pila.empty()) {
                    std::cout << "La Pila está vacía.\n";
                } else {
                    std::stack<Articulo> temp = pila; // Copia de la pila
                    while (!temp.empty()) {
                        Articulo articulo = temp.top(); // Obtener el artículo superior
                        std::cout << "Nombre: " << articulo.nombre
                                  << ", Precio: $" << articulo.precio
                                  << ", Cantidad: " << articulo.cantidad << std::endl;
                        temp.pop(); // Eliminar el artículo superior
                    }
                }
                break;
            }
            case 3:
                std::cout << "Saliendo del programa.\n"; // Mensaje de salida
                break;
            default:
                std::cout << "Opción inválida. Intente nuevamente.\n"; // Manejo de opción inválida
                break;
        }
    } while (opcion != 3); // Continuar hasta que el usuario elija salir

    return 0; // Fin del programa
}

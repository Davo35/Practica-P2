#include <iostream>     // Para entrada y salida de datos
#include <vector>      // Para usar el contenedor vector
#include <algorithm>   // Para usar funciones como sort
#include <string>      // Para usar std::string

// Definición de la estructura Persona
struct Persona {
    std::string nombre;       // Campo para el nombre
    std::string apellido;     // Campo para el apellido
    int id;                   // Campo para el ID
    std::string horaIngreso;  // Campo para la hora de ingreso

    // Sobrecarga del operador < para permitir la comparación
    bool operator<(const Persona& p) const {
        // Comparar por apellido primero
        if (apellido != p.apellido) {
            return apellido < p.apellido; // Si los apellidos son diferentes, devuelve el menor
        }
        // Si los apellidos son iguales, compara por nombre
        return nombre < p.nombre; // Devuelve el menor de los nombres
    }
};

// Función para mostrar el menú de opciones
void mostrarMenu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Ingresar datos\n";          // Opción para ingresar datos
    std::cout << "2. Buscar datos\n";            // Opción para buscar datos
    std::cout << "3. Mostrar datos en orden\n";  // Opción para mostrar datos ordenados
    std::cout << "4. Salir\n";                    // Opción para salir del programa
    std::cout << "Seleccione una opción: ";      // Solicita al usuario que seleccione una opción
}

// Función principal del programa
int main() {
    std::vector<Persona> personas; // Vector para almacenar las personas
    int opcion;                   // Variable para almacenar la opción seleccionada

    do {
        mostrarMenu();            // Llamada a la función que muestra el menú
        std::cin >> opcion;      // Lee la opción seleccionada por el usuario
        std::cin.ignore();       // Limpia el buffer para evitar problemas con getline

        switch (opcion) {
            case 1: { // Opción para ingresar datos
                Persona p; // Crear una instancia de Persona
                std::cout << "Ingrese nombre: ";
                std::getline(std::cin, p.nombre); // Lee el nombre completo

                std::cout << "Ingrese apellido: ";
                std::getline(std::cin, p.apellido); // Lee el apellido completo

                std::cout << "Ingrese ID: ";
                std::cin >> p.id; // Lee el ID
                std::cin.ignore(); // Limpia el buffer

                std::cout << "Ingrese hora de ingreso: ";
                std::getline(std::cin, p.horaIngreso); // Lee la hora de ingreso

                // Agrega la nueva persona al vector
                personas.push_back(p);
                break; // Sale del case 1
            }
            case 2: { // Opción para buscar datos
                std::string nombreBuscado, apellidoBuscado; // Variables para almacenar los datos buscados
                std::cout << "Ingrese nombre a buscar: ";
                std::getline(std::cin, nombreBuscado); // Lee el nombre a buscar

                std::cout << "Ingrese apellido a buscar: ";
                std::getline(std::cin, apellidoBuscado); // Lee el apellido a buscar

                bool encontrado = false; // Bandera para indicar si se encontró o no

                // Recorre el vector de personas
                for (const auto& p : personas) {
                    // Compara si el nombre y apellido coinciden
                    if (p.nombre == nombreBuscado && p.apellido == apellidoBuscado) {
                        std::cout << "Datos encontrados:\n"; // Mensaje de éxito
                        std::cout << "Nombre: " << p.nombre << ", Apellido: " << p.apellido
                                  << ", ID: " << p.id << ", Hora de ingreso: " << p.horaIngreso << std::endl;
                        encontrado = true; // Se encontró la persona
                        break; // Sale del bucle
                    }
                }
                // Si no se encontró, muestra un mensaje
                if (!encontrado) {
                    std::cout << "Datos no encontrados." << std::endl;
                }
                break; // Sale del case 2
            }
            case 3: { // Opción para mostrar datos en orden
                // Ordena el vector de personas usando el operador < definido anteriormente
                std::sort(personas.begin(), personas.end());
                std::cout << "\nDatos ordenados:\n";
                // Muestra los datos de cada persona
                for (const auto& p : personas) {
                    std::cout << "Nombre: " << p.nombre << ", Apellido: " << p.apellido
                              << ", ID: " << p.id << ", Hora de ingreso: " << p.horaIngreso << std::endl;
                }
                break; // Sale del case 3
            }
            case 4: // Opción para salir
                std::cout << "Saliendo del programa." << std::endl; // Mensaje de salida
                break; // Sale del case 4
            default: // Opción inválida
                std::cout << "Opción inválida. Intente nuevamente." << std::endl;
                break; // Sale del default
        }
    } while (opcion != 4); // El bucle se repite hasta que la opción sea 4

    return 0; // Fin del programa
}

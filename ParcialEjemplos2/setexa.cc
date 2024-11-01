#include <iostream>     
#include <set>         
#include <string>      

// Función para mostrar el menú de opciones
void Menu() {
    std::cout << "\nMenu de la Tienda de comida:\n";
    std::cout << "1. Agregar comida\n";          
    std::cout << "2. Eliminar comida\n";         
    std::cout << "3. Mostrar comidas\n";         
    std::cout << "4. Salir\n";                  
    std::cout << "Seleccione una opción: ";     
}

// Función principal del programa
int main() {
    std::set<std::string> comidas; // Conjunto para almacenar los nombres de las comidas
    int opcion;                   // Variable para almacenar la opción seleccionada

    do {
        Menu();            // Muestra el menú de opciones
        std::cin >> opcion;      // Lee la opción seleccionada por el usuario
        std::cin.ignore();       // Limpia el buffer de entrada para evitar problemas con getline

        switch (opcion) {
            case 1: { // Opción para agregar comida
                std::string comida; // Variable para almacenar el nombre de la comida
                std::cout << "Ingrese el nombre de la comida a agregar: ";
                std::getline(std::cin, comida); // Lee el nombre de la comida

                // Intenta agregar la comida al conjunto
                auto resultado = comidas.insert(comida);
                if (resultado.second) { // Si la comida se agregó con éxito
                    std::cout << "Comida agregada: " << comida << std::endl;
                } else { // Si ya existe en el conjunto
                    std::cout << "La comida '" << comida << "' ya está en la lista." << std::endl;
                }
                break; // Sale del case 1
            }
            case 2: { // Opción para eliminar comida
                std::string comida; // Variable para almacenar el nombre de la comida a eliminar
                std::cout << "Ingrese el nombre de la comida a eliminar: ";
                std::getline(std::cin, comida); // Lee el nombre de la comida

                // Intenta eliminar la comida del conjunto y devuelve el número de eliminaciones
                size_t eliminados = comidas.erase(comida);
                if (eliminados > 0) { // Si se eliminó al menos una comida
                    std::cout << "Comida eliminada: " << comida << std::endl;
                } else { // Si no se encontró la comida
                    std::cout << "La comida '" << comida << "' no se encontró en la lista." << std::endl;
                }
                break; // Sale del case 2
            }
            case 3: { // Opción para mostrar comidas
                std::cout << "\nComidas disponibles:\n";
                // Itera sobre el conjunto de comidas y muestra cada una
                for (const auto& comida : comidas) {
                    std::cout << "- " << comida << std::endl; // Muestra el nombre de la comida
                }
                break; // Sale del case 3
            }
            case 4: // Opción para salir
                std::cout << "Saliendo del programa." << std::endl; // Mensaje de salida
                break; // Sale del case 4
            default: // Opción no válida
                std::cout << "Opción inválida. Intente nuevamente." << std::endl; // Mensaje de error
                break; // Sale del default
        }
    } while (opcion != 4); // Continúa repitiendo el menú hasta que el usuario elija salir

    return 0; // Fin del programa
}

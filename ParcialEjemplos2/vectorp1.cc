#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> nombres;
    std::vector<int> edades;

    std::string nombre;
    int edad;
    char continuar;

    // Ingreso de datos
    do {
        std::cout << "Ingrese el nombre: ";
        std::getline(std::cin, nombre);
        nombres.push_back(nombre); // Agregar nombre al vector

        std::cout << "Ingrese la edad: ";
        std::cin >> edad;
        edades.push_back(edad); // Agregar edad al vector

        std::cout << "¿Desea ingresar otra persona? (s/n): ";
        std::cin >> continuar;
        std::cin.ignore(); // Limpiar el buffer de entrada
    } while (continuar == 's' || continuar == 'S');

    // Mostrar resultados
    std::cout << "\nLista de Personas:\n";
    for (size_t i = 0; i < nombres.size(); ++i) {
        std::cout << "Nombre: " << nombres[i] << ", Edad: " << edades[i] << std::endl;
    }

    return 0;
}

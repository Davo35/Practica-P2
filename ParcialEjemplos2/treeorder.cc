#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    std::vector<std::string> nombres;
    std::string nombre;
    char continuar;

    // Ingreso de nombres
    do {
        std::cout << "Ingrese un nombre: ";
        std::getline(std::cin, nombre);
        nombres.push_back(nombre); // Agregar nombre al vector

        std::cout << "¿Desea ingresar otro nombre? (s/n): ";
        std::cin >> continuar;
        std::cin.ignore(); // Limpiar el buffer
    } while (continuar == 's' || continuar == 'S');

    // Ordenar el vector de nombres
    std::sort(nombres.begin(), nombres.end());

    // Mostrar nombres ordenados
    std::cout << "\nNombres ordenados:\n";
    for (const auto& n : nombres) {
        std::cout << n << std::endl;
    }

    // Búsqueda de un nombre
    std::cout << "\nIngrese un nombre a buscar: ";
    std::getline(std::cin, nombre);

    // Buscar usando búsqueda binaria
    if (std::binary_search(nombres.begin(), nombres.end(), nombre)) {
        std::cout << "El nombre \"" << nombre << "\" está en la lista." << std::endl;
    } else {
        std::cout << "El nombre \"" << nombre << "\" no está en la lista." << std::endl;
    }

    return 0;
}

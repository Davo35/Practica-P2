#include <iostream>
#include <set>
#include <string>

struct Libro {
    std::string Titulo;

    bool operator<(const Libro& otro) const {
        return Titulo < otro.Titulo;
    }
};

void agregarLibro(std::set<Libro>& biblioteca, const std::string& titulo) {
    Libro nuevoLibro = {titulo};
    if (biblioteca.insert(nuevoLibro).second) {
        std::cout << "Libro agregado: " << titulo << std::endl;
    } else {
        std::cout << "El libro ya existe en la biblioteca.\n";
    }
}

void buscarLibro(const std::set<Libro>& biblioteca, const std::string& titulo) {
    Libro libroBuscado = {titulo};
    auto iterador = biblioteca.find(libroBuscado);
    if (iterador != biblioteca.end()) {
        std::cout << "Libro encontrado: " << iterador->Titulo << std::endl;
    } else {
        std::cout << "Libro no encontrado.\n";
    }
}

void eliminarLibro(std::set<Libro>& biblioteca, const std::string& titulo) {
    Libro libroAEliminar = {titulo};
    auto iterador = biblioteca.find(libroAEliminar);
    if (iterador != biblioteca.end()) {
        biblioteca.erase(iterador);
        std::cout << "Libro eliminado: " << titulo << std::endl;
    } else {
        std::cout << "Libro no encontrado.\n";
    }
}

void mostrarLibros(const std::set<Libro>& biblioteca) {
    if (biblioteca.empty()) {
        std::cout << "No hay libros en la biblioteca.\n";
    } else {
        std::cout << "Libros en la biblioteca:\n";
        for (const auto& libro : biblioteca) {
            std::cout << libro.Titulo << std::endl;
        }
    }
}

int main() {
    std::set<Libro> biblioteca;
    agregarLibro(biblioteca, "Cien años de soledad");
    agregarLibro(biblioteca, "Don Quijote de la Mancha");
    buscarLibro(biblioteca, "Cien años de soledad");
    eliminarLibro(biblioteca, "Cien años de soledad");
    mostrarLibros(biblioteca);
    return 0;
}

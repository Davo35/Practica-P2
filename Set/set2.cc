#include <iostream>
#include <set>
#include <string>

struct Estudiante {
    std::string Nombre;
    std::string Identificacion;

    bool operator<(const Estudiante& otro) const {
        return Identificacion < otro.Identificacion;
    }
};

void agregarEstudiante(std::set<Estudiante>& estudiantes, const std::string& nombre, const std::string& id) {
    Estudiante nuevoEstudiante = {nombre, id};
    if (estudiantes.insert(nuevoEstudiante).second) {
        std::cout << "Estudiante agregado: " << nombre << " con ID: " << id << std::endl;
    } else {
        std::cout << "El estudiante con ID " << id << " ya existe.\n";
    }
}

void buscarEstudiante(const std::set<Estudiante>& estudiantes, const std::string& id) {
    Estudiante estudianteBuscado = {"", id}; // Nombre no importa
    auto iterador = estudiantes.find(estudianteBuscado);
    if (iterador != estudiantes.end()) {
        std::cout << "Estudiante encontrado: " << iterador->Nombre << " con ID: " << id << std::endl;
    } else {
        std::cout << "Estudiante no encontrado.\n";
    }
}

void eliminarEstudiante(std::set<Estudiante>& estudiantes, const std::string& id) {
    Estudiante estudianteAEliminar = {"", id}; // Nombre no importa
    auto iterador = estudiantes.find(estudianteAEliminar);
    if (iterador != estudiantes.end()) {
        estudiantes.erase(iterador);
        std::cout << "Estudiante con ID " << id << " eliminado.\n";
    } else {
        std::cout << "Estudiante no encontrado.\n";
    }
}

void mostrarEstudiantes(const std::set<Estudiante>& estudiantes) {
    if (estudiantes.empty()) {
        std::cout << "No hay estudiantes registrados.\n";
    } else {
        std::cout << "Estudiantes registrados:\n";
        for (const auto& estudiante : estudiantes) {
            std::cout << "Nombre: " << estudiante.Nombre << ", ID: " << estudiante.Identificacion << std::endl;
        }
    }
}

int main() {
    std::set<Estudiante> estudiantes;
    agregarEstudiante(estudiantes, "Juan Pérez", "12345");
    agregarEstudiante(estudiantes, "María López", "67890");
    buscarEstudiante(estudiantes, "12345");
    eliminarEstudiante(estudiantes, "67890");
    mostrarEstudiantes(estudiantes);
    return 0;
}

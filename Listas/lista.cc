#include <iostream>
#include <string>
#include <list>
#include <algorithm>

struct Estudiante {
    std::string nombre;
    int edad;
    std::string carrera;
    double promedio;
};

void Menu();
void Agregar(std::list<Estudiante> &alumnos);
void Mostrar(std::list<Estudiante> &alumnos);
void Buscar(std::list<Estudiante> &alumnos);
void EliminarPorNombre(std::list<Estudiante> &alumnos);

int main() {
    std::list<Estudiante> estudiantes;
    int eleccion;

    do {
        Menu();
        std::cout << "Opcion: ";
        std::cin >> eleccion;

        switch (eleccion) {
            case 1:
                system("cls");
                Agregar(estudiantes);
                break;
            case 2:
                system("cls");
                Mostrar(estudiantes);
                break;

            case 3:
                system("cls");
                Buscar(estudiantes);
                break;

            case 4:
                system("cls");
                EliminarPorNombre(estudiantes);
                break;

            case 5:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "\nDigitar una opcion\n";
                system("pause");
                break;
        }
    } while (eleccion != 5);

    return 0;
}

void Menu() {
    system("cls");
    std::cout << "\n---- Registro de estudiantes ------ \n";
    std::cout << "\n1. Agregar || 2. Mostrar || 3. Buscar || 4. Eliminar || 5. Salir\n\n";
}

void Agregar(std::list<Estudiante> &alumnos) {
    Estudiante nuevo_estudiante;
    int cantidad;

    std::cout << "\nCuantos estudiantes va ingresar: ";
    std::cin >> cantidad;
    std::cin.ignore();  // Limpiar el buffer

    for (int i = 0; i < cantidad; i++) {
        system("cls");
        std::cout << "\n--- Alumno " << i + 1 << " ---\n";
        std::cout << "Nombre: ";
        std::getline(std::cin, nuevo_estudiante.nombre);

        std::cout << "Carrera: ";
        std::getline(std::cin, nuevo_estudiante.carrera);

        std::cout << "Edad: ";
        std::cin >> nuevo_estudiante.edad;

        std::cout << "Promedio: ";
        std::cin >> nuevo_estudiante.promedio;
        std::cin.ignore();  // Limpiar el buffer

        alumnos.push_back(nuevo_estudiante); // Agregando estudiante a la lista
        std::cout << "\nAlumno " << i + 1 << " Guardado\n";
        system("pause");
    }
}

void Mostrar(std::list<Estudiante> &alumnos) {
    int opcion_orden;

    std::cout << "\nComo quiere ver los estudiantes: ";
    std::cout << "\n1. Promedio || 2. Por carrera || 3. Sin ordenar\n";
    std::cout << "Opcion: ";
    std::cin >> opcion_orden;

    if (opcion_orden == 1) {
        alumnos.sort([](const Estudiante &mayor, const Estudiante &menor) {
            return mayor.promedio > menor.promedio;
        });

    } else if (opcion_orden == 2) {
        alumnos.sort([](const Estudiante &a, const Estudiante &b) {
            return a.carrera < b.carrera; // Orden alfabético
        });

    } else {
        std::cout << "\n---- Estudiantes sin ordenar ----- \n";
    }

    for (const auto &jovenes : alumnos) {
        std::cout << "\n-------------------------------\n";
        std::cout << "\nNombre: " << jovenes.nombre;
        std::cout << "\nEdad: " << jovenes.edad;
        std::cout << "\nPromedio: " << jovenes.promedio;
        std::cout << "\nCarrera: " << jovenes.carrera << std::endl;
    }

    system("pause");
}

void Buscar(std::list<Estudiante> &alumnos){

    std::string nombre_buscar;

    std::cout << "\nIngresar el nombre a buscar: ";
    std::cin.ignore();
    std::getline(std::cin, nombre_buscar);

    bool encontrado = true;

    for (const auto &buscar : alumnos)
    {
        if (nombre_buscar == buscar.nombre)
        {
            std::cout << "\nNombre: " << buscar.nombre << std::endl;
            std::cout << "\nEdad: " << buscar.edad << std::endl;
            std::cout << "\nPromedio: " << buscar.promedio << std::endl;
            std::cout << "\nCarrera: " << buscar.carrera << std::endl;

            encontrado = true;
            system("pause");
            break;
        }
    }
    
    if (!encontrado)
    {
        std::cout << "Estudiante no encontrado.\n";
        system("pause");
    }
}

void EliminarPorNombre(std::list<Estudiante> &alumnos){

    std::string nombre_eliminar;
    std::cout << "\nIngresar el nombre a eliminar: ";
    std::cin.ignore();
    std::getline(std::cin, nombre_eliminar);

    auto iterador = std::remove_if(alumnos.begin(), alumnos.end(), [&nombre_eliminar](const Estudiante &estudiante){
        return estudiante.nombre == nombre_eliminar;
    });

    if (iterador != alumnos.end())
    {
        alumnos.erase(iterador, alumnos.end());
        std::cout << "\nAlumno " << nombre_eliminar << " eliminado\n";
        system("pause");
    }

    else{
        std::cout << "\nNo se encontro estudiante\n";
        system("pause");
    }
}
    
    



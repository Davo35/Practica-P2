#include <iostream>
#include <string>
#include <list>
#include <algorithm>

// Estructura para los miembros del club
struct Miembro {
    std::string primer_nombre;
    std::string apellido;
    int edad;
};

// Estructura para el club
struct Club {
    std::string nombre;          // Nombre del club
    std::string fecha_creacion;  // Fecha de creación del club
    int capacidad_max;           // Capacidad máxima
    std::list<Miembro> miembros; // Lista de miembros
};

// Prototipos de funciones
void Menu();
void CrearClub(std::list<Club>& clubs);
void MostrarClub(const std::list<Club>& clubs);
void RegistrarMiembro(std::list<Club>& clubs);
void MostrarMiembros(const std::list<Club>& clubs);
void MiembrosTotales(const std::list<Club>& clubs);
void BuscarMiembro(const std::list<Club>& clubs);

int main() {
    int opcion;
    std::list<Club> clubs;  // Lista para almacenar clubes

    do {
        system("cls");
        Menu();
        std::cout << "Elegir una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                system("cls");
                CrearClub(clubs);
                break;
            case 2:
                system("cls");
                MostrarClub(clubs);
                break;
            case 3:
                system("cls");
                RegistrarMiembro(clubs);
                break;
            case 4:
                system("cls");
                MostrarMiembros(clubs);
                break;
            case 5:
                system("cls");
                MiembrosTotales(clubs);
                break;
            case 6:
                system("cls");
                BuscarMiembro(clubs);
                break;
            default:
                break;
        }
    } while (opcion != 7);

    std::cout << "\nSaliendo......\n";
    system("pause");

    return 0;
}

void Menu() {
    std::cout << "\n---- Registro de Clubes ----\n\n";
    std::cout << "1. Crear un nuevo club   || 2. Mostrar todos los clubes  || 3. "
                 "Registrar miembros en un club   || 4. Ver miembros de un club     "
                 "|| 5. Ver total de miembros de un club  || 6. Buscar miembro en un club || 7. Salir\n\n";
}

void CrearClub(std::list<Club>& clubs) {
    Club nuevo_club;

    std::cout << "\n--- REGISTRO DE CLUBES ---";
    std::cout << "\nIngrese el nombre del club: ";
    std::cin.ignore();  // Para evitar problemas con getline
    std::getline(std::cin, nuevo_club.nombre);

    std::cout << "\nFecha de creacion del club (Dia/Mes/ano): ";
    std::getline(std::cin, nuevo_club.fecha_creacion);

    std::cout << "\nCapacidad maxima del club: ";
    std::cin >> nuevo_club.capacidad_max;

    clubs.push_back(nuevo_club);  // Agregar el nuevo club a la lista

    std::cout << "\nClub creado exitosamente.\n";
    system("pause");
}

void MostrarClub(const std::list<Club>& clubs) {
    std::cout << "\n--- Lista de Clubes --- ";

    for (const auto& club : clubs) {
        std::cout << "\n\nNombre del club: " << club.nombre;
        std::cout << "\nFecha de creacion: " << club.fecha_creacion;
        std::cout << "\nMiembros en el club: " << club.miembros.size();
        std::cout << "\nCapacidad: " << club.capacidad_max << " Personas\n";
    }
    system("pause");
}

void RegistrarMiembro(std::list<Club>& clubs) {
    std::string NombreClub;

    std::cout << "\n---- Registrarse a un club ---- \n\n";
    std::cout << "Ingrese el nombre del club a registrarse: ";
    std::cin.ignore();
    std::getline(std::cin, NombreClub);

    for (auto& club : clubs) {
        if (club.nombre == NombreClub) {
            if (club.miembros.size() >= club.capacidad_max) {
                std::cout << "\nCapacidad maxima alcanzada\n";
                system("pause");
                return;
            }

            Miembro nuevo_miembro;
            std::cout << "\nIngresar primer nombre: ";
            std::getline(std::cin, nuevo_miembro.primer_nombre);
            std::cout << "Apellido: ";
            std::getline(std::cin, nuevo_miembro.apellido);
            std::cout << "Edad: ";
            std::cin >> nuevo_miembro.edad;
            std::cin.ignore();

            club.miembros.push_back(nuevo_miembro);  // Agregar el nuevo miembro
            std::cout << "\nSe ha registrado correctamente\n";
            system("pause");
            return;
        }
    }

    std::cout << "\nNo se encontro el club\n";
    system("pause");
}

void MostrarMiembros(const std::list<Club>& clubs) {
    std::string NombreClub;
    std::cout << "\n -- Miembros del club --- \n";
    std::cout << "\nIngresar el nombre del club: ";
    std::cin.ignore();
    std::getline(std::cin, NombreClub);

    for (const auto& club : clubs) {
        if (club.nombre == NombreClub) {
            std::cout << "\n\n--- Miembros del club " << NombreClub << " ---- \n\n";
            for (const auto& miembro : club.miembros) {
                std::cout << "\nNombre: " << miembro.primer_nombre << " " << miembro.apellido;
                std::cout << "\nEdad: " << miembro.edad << std::endl;
            }
            system("pause");
            return;
        }
    }

    std::cout << "\nNo se encontro el club\n";
    system("pause");
}

void MiembrosTotales(const std::list<Club>& clubs) {
    std::string NombreClub;

    std::cout << "\nIngresar nombre del club para ver el total de miembros: ";
    std::cin.ignore();
    std::getline(std::cin, NombreClub);

    for (const auto& club : clubs) {
        if (club.nombre == NombreClub) {
            std::cout << "\nMiembros totales del club " << NombreClub << ": "
                      << club.miembros.size() << std::endl;
            system("pause");
            return;
        }
    }

    std::cout << "\nNo se encontro el club\n";
    system("pause");
}

void BuscarMiembro(const std::list<Club>& clubs) {
    std::string NombreClub, NombreMiembro;

    std::cout << "\n---- Buscar miembro en un club ---- \n\n";
    std::cout << "Ingrese el nombre del club: ";
    std::cin.ignore();
    std::getline(std::cin, NombreClub);

    for (const auto& club : clubs) {
        if (club.nombre == NombreClub) {
            std::cout << "Ingrese el primer nombre del miembro a buscar: ";
            std::getline(std::cin, NombreMiembro);

            for (const auto& miembro : club.miembros) {
                if (miembro.primer_nombre == NombreMiembro) {
                    std::cout << "\nMiembro encontrado: " << miembro.primer_nombre << " "
                              << miembro.apellido << ", Edad: " << miembro.edad << std::endl;
                    system("pause");
                    return;
                }
            }

            std::cout << "\nNo se encontró el miembro en el club " << NombreClub << ".\n";
            system("pause");
            return;
        }
    }

    std::cout << "\nNo se encontró el club " << NombreClub << ".\n";
    system("pause");
}
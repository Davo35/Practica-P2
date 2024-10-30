#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Estudiante
{
    std::string nombre;
    int edad;
    double promedio; //notas
    std::string carrera;
};

void Menu();
void Agregar(std::vector<Estudiante> &alumnos);
void Mostar(std::vector<Estudiante> &alumnos);
void Buscar(std::vector<Estudiante> &alumnos);
void EliminarPorNombre(std::vector<Estudiante> &alumnos);
void BuscarCarrera(std::vector<Estudiante> &alumnos);

int main(){

    std::vector<Estudiante> alumnos;

    system("cls");
    int opcion;

    do
    {
        Menu();
        std::cout << "\nElegir una opcion: ";
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
            Agregar(alumnos);
            break;

        case 2:
            Mostar(alumnos);
            break;

        case 3:
            Buscar(alumnos);
            break;

        case 4:
            BuscarCarrera(alumnos);
            break;

        case 5:
            EliminarPorNombre(alumnos);
            break;
        
        default:
            std::cout << "\nOpcion no valida, intente de nuevo\n";
            break;
        }
    } while (opcion != 6);
    
    

    return 0;
}

void Menu(){

    system("cls");
  std::cout << "\n------ Registro alummnos ------- \n\n";
  std::cout << "1. Agregar estudiante || 2. Mostrar || 3. Buscar Nombre || 4. Buscar Carrera  || 5. Eliminar  ||  6. Salir\n\n";
}

void Agregar(std::vector<Estudiante> &alumnos){

    Estudiante nuevo_estudiante;
    int num_alumnos;
    
    system("cls");
    std::cout << "\nCuantos alumnos va ingresar: ";
    std::cin >> num_alumnos;

    for (int i = 0; i < num_alumnos; i++)
    {
        std::cout << "\nNombre del alumno " << i+1 << ": ";
        std::cin.ignore();
        std::getline(std::cin, nuevo_estudiante.nombre);

        std::cout << "\nEdad del estudiante " << i+1 << ": ";
        std::cin >> nuevo_estudiante.edad;

        std::cout << "\nPromedio del estudiante " << i+1 << ": ";
        std::cin >> nuevo_estudiante.promedio;

        std::cout << "\nCarrera del estudiante " << i+1 << ": ";
        std::cin.ignore();
        std::getline(std::cin, nuevo_estudiante.carrera);
        

        alumnos.push_back(nuevo_estudiante);
    }
}

void Mostar(std::vector<Estudiante> &alumnos){

    int opcion_orden;

    std::cout << "\nComo quiere ver los estudiantes: ";
    std::cout << "\n1. Por promedio || 2. Por carrera || 3. Sin ordenar\n";

    std::cout << "Opcion: ";
    std::cin >> opcion_orden;

    //segun la opcion elegida
    if (opcion_orden == 1)
    {
        std::sort(alumnos.begin(), alumnos.end(), [](const Estudiante &mayor, const Estudiante &menor){
        return mayor.promedio > menor.promedio;
    });

    std::cout << "\n---- Estudiantes ordenados por promedio ---- \n";
    }

    else if (opcion_orden == 2)
    {
        std::sort(alumnos.begin(), alumnos.end(), [](const Estudiante &mayor, const Estudiante &menor){
        return mayor.carrera < menor.carrera; //alfabeticamente    
    });

        std::cout << "\n---- Estudiantes ordenados por carrera ---- \n";
    }

    else{
        std::cout << "\n---- Estudiantes sin ordenar ---- \n";
    }
    
    //MOSTRANDO LISTA

    for (const auto &cherada : alumnos)
    {   
        std::cout << "\n---------------------------------------------";
        std::cout << "\nNombre: " << cherada.nombre << std::endl;
        std::cout << "\nEdad: " << cherada.edad << std::endl;
        std::cout << "\nPromedio: " << cherada.promedio << std::endl;
        std::cout << "\nCarrera: " << cherada.carrera << std::endl;
    }
    system("pause");
}

void Buscar(std::vector<Estudiante> &alumnos){

    std::string nombre_buscado;
    std::cout << "\nIngresar el nombre a buscar: ";
    std::cin.ignore();
    std::getline(std::cin, nombre_buscado);

    bool encontrado = false;

    for (const auto &buscado : alumnos)
    {
        if (nombre_buscado == buscado.nombre)
        {
            std::cout << "\nNombre: " << buscado.nombre << std::endl;
            std::cout << "\nEdad: " << buscado.edad << std::endl;
            std::cout << "\nPromedio: " << buscado.promedio << std::endl;
            std::cout << "\nCarrera: " << buscado.carrera << std::endl;

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

void EliminarPorNombre(std::vector<Estudiante> &alumnos){

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

void BuscarCarrera(std::vector<Estudiante> &alumnos){

    std::string carrera_buscado;
    std::cout << "\nIngresar el nombre a buscar: ";
    std::cin.ignore();
    std::getline(std::cin, carrera_buscado);

    bool encontrado = false;

    for (const auto &buscado : alumnos)
    {
        if (carrera_buscado == buscado.carrera)
        {
            std::cout << "\nNombre: " << buscado.nombre << std::endl;
            std::cout << "\nEdad: " << buscado.edad << std::endl;
            std::cout << "\nPromedio: " << buscado.promedio << std::endl;
            std::cout << "\nCarrera: " << buscado.carrera << std::endl;

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
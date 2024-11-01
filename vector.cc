//LIBRERIA VECTOR

#include <iostream>
#include <vector> 
#include <string>
#include <algorithm>

struct Estudiante
{
    std::string nombre;
    int edad;
};

void Menu();
void AgregarEstudiante(std::vector<Estudiante> &alumnos);
void Mostrar(const std::vector<Estudiante> &alumnos);
void Buscar(std::vector<Estudiante> &alumnos);
void Eliminar(std::vector<Estudiante> &alumnos);

int main(){
    std::vector<Estudiante> alumnos; //vector tipo estudiante(struct) llamado alumnos

    int opcion;

    do
    {
    Menu();
    std::cout << "\nElegir una opcion: ";
    std::cin >> opcion;

    switch (opcion)
    {
    case 1:
        AgregarEstudiante(alumnos); //pasamos el vector alumnos
        break;

    case 2:
        Mostrar(alumnos);
        break;

    case 3:
        Buscar(alumnos);
        break;

    case 4:
        Eliminar(alumnos);
        break;
    }

    } while (opcion != 5);

    return 0;
}

void Menu(){

    system("cls");
  std::cout << "\n------ Registro alummnos ------- \n\n";
  std::cout << "1. Agregar estudiante || 2. Mostrar || 3. Buscar || 4. Eliminar  ||  5. Salir\n\n";
}

void AgregarEstudiante(std::vector<Estudiante> &alumnos){
    int numero;

    std::cout << "\nCuantos estudiantes va ingresar: ";
    std::cin >> numero;

    //VARIABLE STRUCT PARA USAR LOS CAMPOS
    Estudiante nuevoEstudiante;

    for (int i = 0; i < numero; i++)
    {
        std::cout << "\n\nIngrese el nombre del estudiante " << i+1 << " : ";
        std::cin.ignore();
        std::getline(std::cin, nuevoEstudiante.nombre);

        std::cout << "\nIngrese la edad: ";
        std::cin >> nuevoEstudiante.edad;

        //GUARDA TODA LA INFO DE nuevoEstudiante AL FINAL DEL VECTOR
        alumnos.push_back(nuevoEstudiante); 
    } 
}

void Mostrar(const std::vector<Estudiante> &alumnos){

    std::cout << "\nLista de estudiantes\n\n";

    for (const auto &variableEstudiante : alumnos)
    {
        std::cout << "\nNombre: " << variableEstudiante.nombre << std::endl;
        std::cout << "Edad: " << variableEstudiante.edad << std::endl;
    }
    
    system("pause");
}

void Buscar(std::vector<Estudiante> &alumnos){

    std::string buscar_nombre;
    bool encontrado = false;

    std::cout << "\nIngresar el nombre del estudiante a buscar: ";
    std::cin.ignore();
    std::getline(std::cin, buscar_nombre);

    for (const auto &buscar_estudiante : alumnos)
    {
        if (buscar_estudiante.nombre == buscar_nombre)
        {
            std::cout << "\nNombre: " << buscar_estudiante.nombre << std::endl;
            std::cout << "\nEdad: " << buscar_estudiante.edad << std::endl;
            encontrado = true;
            system("pause");
            break;
        }
    }

    //si no se encontro
    if (!encontrado)
    {
        std::cout << "\nEl estudiante no fue encontrado\n";
        system("pause");
    }
}

void Eliminar(std::vector<Estudiante> &alumnos){

    std::string nombre_eliminar;
    std::cout << "\nIngresar el nombre el estudiante a eliminar: ";
    std::cin.ignore();
    std::getline(std::cin, nombre_eliminar);

    //recorre de inicio a fin buscar el nombre
    auto iterador = std::remove_if(alumnos.begin(), alumnos.end(), [&nombre_eliminar](const Estudiante &estudiante){
        return estudiante.nombre == nombre_eliminar;
    });

    //si el iterador no llego al final, encontro algo
    if (iterador != alumnos.end())
    {
        //vector alumnos 
        alumnos.erase(iterador, alumnos.end());
        std::cout << "\nEl alumno " << nombre_eliminar << " fue eliminado\n";
        system("pause");
    }

    else{
        std::cout << "\nNo se encontro al estudiante\n";
        system("pause");
    }
    






}
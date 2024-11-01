#include <iostream>
#include <stack>

struct Historial
{
    std::string url;
};

void Menu();
void Agregar(std::stack<Historial> &navegacion);
bool ExisteHistorial(const std::stack<Historial> &navegacion, const std::string &pagina);
void Mostrar(std::stack<Historial> &navegacion);
void Retroceder(std::stack<Historial> &navegacion);
void Buscar(std::stack<Historial> &navegacion);

int main(){

    //Declarando pila
    std::stack<Historial> historial_navegacion;
    int opcion;
    do
    {
        Menu();
        std::cout << "\nElegir una opcion: ";
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
            system("cls");
            Agregar(historial_navegacion);
            break;

        case 2:
            system("cls");
            Mostrar(historial_navegacion);
            break;

        case 3:
            system("cls");
            Retroceder(historial_navegacion);
            break;

        case 4:
            system("cls");
            Buscar(historial_navegacion);
            break;
        
        default:
            std::cout << "\nElegir una opcion correcta\n";
            system("pause");
            break;
        }

    
    } while (opcion != 5);

    return 0;
}

void Menu(){

    system("cls");
    std::cout << "\n--- Histiorial de busqueda ---\n";
    std::cout << "\n1. Agregar pagina || 2. Mostrar Paginas || 3. Retroceder historial || 4. Buscar || 5. Salir\n";
}

bool ExisteHistorial(const std::stack<Historial> &navegacion, const std::string &pagina){

    //Como solo queremos comprobar creamos un stack temporal para no modificiar original
    std::stack <Historial> temp = navegacion;

    //Recorre hasta el final
    while (!temp.empty())
    {
        if (temp.top().url == pagina)
        {
            return true; //la pagina existe
        }
        
        temp.pop(); 
    }
    
    //si no existe 
    return false;
}

void Agregar(std::stack<Historial> &navegacion){

    std::string pagina_agregar;
    char opcion;

    std::cout << "\nIngrese el nombre/url de la pagina: ";
    std::cin.ignore();
    std::getline(std::cin, pagina_agregar);

    //Comprobando si pagina ya existe
    if (ExisteHistorial(navegacion, pagina_agregar))
    {   //si es true, ya existe la pagina
        std::cout << "\nLa pagina ya existe dentro del historial, quieres agregarla nuevamente? (S | N): ";
        std::cin >> opcion;

        if (opcion == 'n' || opcion == 'N')
        {
            std::cout << "\nPagina no se agrego\n";
            system("pause");
            return;
        }
    }

    navegacion.push(Historial{pagina_agregar});
    std::cout << "\nPagina se agrego \n";
    system("pause");

}

void Mostrar(std::stack<Historial> &navegacion){

    if (navegacion.empty())
    {
        std::cout << "\nEl historial esta vacio\n";
        system("pause");
        return;
    }
    
    //Para no modificar original
    std::stack<Historial> temp = navegacion;

    std::cout << "\n--- Historial de navegacion ---\n\n";
    while (!temp.empty())
    {   //mientras no este vacia

        std::cout << temp.top().url << std::endl;
        temp.pop();
    }

    system("pause");
}

void Retroceder(std::stack<Historial> &navegacion){

    if (!navegacion.empty())
    {
        std::cout << "\nRetrocediendo historial a " << navegacion.top().url << std::endl;
        navegacion.pop(); //elimina pag en la cima
        system("pause");
    }

    else{
        std::cout << "\nNo hay mas paginas\n";
        system("pause");
    }
}

void Buscar(std::stack<Historial> &navegacion){

    std::stack<Historial> temp = navegacion;
    std::string pagina_buscar;

    std::cout << "\nDigitar la pagina a buscar: ";
    std::cin.ignore();
    std::getline(std::cin, pagina_buscar);

    while (!temp.empty())
    {
        if (temp.top().url == pagina_buscar)
        {
            std::cout << "\nLa pagina " << pagina_buscar << " se encontro dentro del historial\n";
            system("pause");
            
        }
        temp.pop();
    }

    std::cout << "\nNo se encontro la pagina\n";
    system("pause");
    


}


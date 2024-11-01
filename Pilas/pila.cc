#include <iostream>
#include <stack>

int main(){

    //CREANDO PILA, <int> tipo entero
    std::stack<int> pila; 

    //AGREGANDO ELEMENTOS
    pila.push(10);
    pila.push(20);
    pila.push(30);
    
    //mostrando cima de la pila

    std::cout << "\nCima de la pila: " << pila.top() << std::endl;

    //Eliminando elemento
    pila.pop();
    std::cout << "\nEl elemento de la cima de la pila fue eliminado: " << pila.top() << std::endl;

    //Comprobando si esta vacia lapila
    if (!pila.empty())
    {
        std::cout << "\nLa pila no esta vacia, tamano: " << pila.size() << std::endl;
    }

    //Limpiar toda la pila
    while (!pila.empty())
    {
        std::cout << "\nEliminando: " << pila.top() << std::endl;
        pila.pop();//elimina elemento de la cima
    }

    //comprobando si esta vacia
    if (pila.empty())
    {
        std::cout << "\nLa pila esta vacia";
    }
    
    return 0;
}
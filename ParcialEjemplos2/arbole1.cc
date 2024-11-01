#include <iostream>
#include <string>

struct Nodo {
    std::string nombre;
    int numero;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(const std::string& n, int num)
        : nombre(n), numero(num), izquierda(nullptr), derecha(nullptr) {}
};

class ArbolBinario {
private:
    Nodo* raiz;

    void insertar(Nodo*& nodo, const std::string& nombre, int numero) {
        if (nodo == nullptr) {
            nodo = new Nodo(nombre, numero);
        } else if (numero < nodo->numero) {
            insertar(nodo->izquierda, nombre, numero);
        } else {
            insertar(nodo->derecha, nombre, numero);
        }
    }

    void inOrden(Nodo* nodo) {
        if (nodo != nullptr) {
            inOrden(nodo->izquierda);
            std::cout << "Nombre: " << nodo->nombre << ", Número: " << nodo->numero << std::endl;
            inOrden(nodo->derecha);
        }
    }

public:
    ArbolBinario() : raiz(nullptr) {}

    void insertar(const std::string& nombre, int numero) {
        insertar(raiz, nombre, numero);
    }

    void mostrarEnOrden() {
        std::cout << "Contenido del árbol en orden:\n";
        inOrden(raiz);
    }
};

int main() {
    ArbolBinario arbol;
    std::string nombre;
    int numero;
    char continuar;

    // Ingreso de datos
    do {
        std::cout << "Ingrese el nombre: ";
        std::getline(std::cin, nombre);
        std::cout << "Ingrese el número: ";
        std::cin >> numero;
        std::cin.ignore(); // Limpiar el buffer de entrada

        arbol.insertar(nombre, numero); // Insertar en el árbol

        std::cout << "¿Desea ingresar otra persona? (s/n): ";
        std::cin >> continuar;
        std::cin.ignore(); // Limpiar el buffer
    } while (continuar == 's' || continuar == 'S');

    // Mostrar resultados
    arbol.mostrarEnOrden();

    return 0;
}

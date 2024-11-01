#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Banco
{
    std::string nombre_titular;
    int numero_cuenta;
    double saldo_inicial;
};

void Menu();
void AgregarCuenta(std::vector<Banco> &cuenta);
void Mostrar(std::vector<Banco> &cuenta);
bool CompararPorCuentas(const Banco& num1, const Banco& num2);
void OrdenarPorNumero(std::vector<Banco>& cuentas);
void BuscarCuenta(std::vector<Banco> &cuenta);

int main(){

    std::vector<Banco> cuentas;
    int opcion;

    do
    {
        system("cls");
        std::cout << "\n---- Registro de cuentas ---- \n\n";
        Menu();

        std::cout << "\nElegir una opcion: ";
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
            system("cls");
            AgregarCuenta(cuentas);
            break;

        case 2:
            system("cls");
            Mostrar(cuentas);
            break;

        case 3:
            system("cls");
            BuscarCuenta(cuentas);
            break;
        
        default:
            std::cout << "\nDigitar una opcion valida\n";
            system("pause");
            break;
        }


    } while (opcion != 4);
    
    std::cout << "\nSaliendo....";

    return 0;
}

void Menu(){

    std::cout << "1. Registrar una cuenta bancaria." << std::endl;
    std::cout << "2. Mostrar cuentas." << std::endl;
    std::cout << "3. Buscar una cuenta en especifico." << std::endl;
    std::cout << "4. Salir." << std::endl;
}

// Para comparar cuentas
bool CompararPorCuentas(const Banco& num1, const Banco& num2) {
    return num1.numero_cuenta < num2.numero_cuenta;
}

// Para ordenar por número de cuenta
void OrdenarPorNumero(std::vector<Banco>& cuenta) {
    std::sort(cuenta.begin(), cuenta.end(), CompararPorCuentas);
}

void AgregarCuenta(std::vector<Banco> &cuenta){

    Banco nueva_cuenta;

    std::cout << "\nIngresar el nombre del titular de la cuenta: ";
    std::cin.ignore();
    std::getline(std::cin, nueva_cuenta.nombre_titular);

    std::cout << "\nIngresar el numero de cuenta: ";
    std::cin >> nueva_cuenta.numero_cuenta;

    std::cout << "\nCual sera el saldo inicial $: ";
    std::cin >> nueva_cuenta.saldo_inicial;

    cuenta.push_back(nueva_cuenta); //ingresando informacion de la cuenta
    std::cout << "\nCuenta fue registrada correctamente\n";
    system("pause");
}

void Mostrar(std::vector<Banco> &cuenta){

    if (cuenta.empty())
    {
        //ESTA VACIO EL VECTOR
        std::cout << "\nNo hay cuentas registradas\n";
        return;
    }

    //si hay almenos 1 cuenta
    std::cout << "\n -- Cuentas registradas sin ordenar-- \n";

    for (const auto &banca : cuenta)
    {
        std::cout << "\nTitular de la cuenta: " << banca.nombre_titular;
        std::cout << "\nNumero de cuenta: " << banca.numero_cuenta;
        std::cout << "\nSaldo inicial: " << banca.saldo_inicial << std::endl;
        
    }

    OrdenarPorNumero(cuenta);

    std::cout << "\n\n -- Cuentas registradas por #cuenta-- \n";

    for (const auto &banca : cuenta)
    {
        std::cout << "\nTitular de la cuenta: " << banca.nombre_titular;
        std::cout << "\nNumero de cuenta: " << banca.numero_cuenta;
        std::cout << "\nSaldo inicial: " << banca.saldo_inicial << std::endl;
        
    }
    
    system("pause");
}

void BuscarCuenta(std::vector<Banco> &cuenta){

    int buscar_cuenta;
    Banco mostrar_cuenta;
    
    std::cout << "\nIngresar el numero de la cuenta a buscar: ";
    std::cin >> buscar_cuenta;

    OrdenarPorNumero(cuenta);

    Banco cuenta_buscar = {"", buscar_cuenta, 0.0};

    //Usando binary search
    bool encontrado;

    encontrado = std::binary_search(cuenta.begin(), cuenta.end(), cuenta_buscar, CompararPorCuentas);

    if (encontrado)
    {
        std::cout << "\nLa cuenta fue encontrada\n";
        system("pause");
    }

    else{
        std::cout << "\nNo se encontro la cuenta\n";
        system("pause");
    }
    

}





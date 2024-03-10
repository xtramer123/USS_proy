#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
#include "comprar.h"

using namespace std;
// edicion
void MenuEdit()
{
    short dec;
    bool band = true;
    do
    {
        cout << "\n**** MENU DE EDICION DE PRODUCTOS ****" << endl;
        cout << "1- Bebidas no Alcoholicas " << endl;
        cout << "2- Bebidas Alcoholicas " << endl;
        cout << "3- Snack Dulce " << endl;
        cout << "4- Snack Salado " << endl;
        cout << "5- Alimentos " << endl;
        cout << "6- Productos del Hogar " << endl;
        cout << "7- Salir " << endl;
        cin >> dec;
        switch (dec)
        {
        case 1:
            editBeb();
            break;
        case 2:
            editAlco();
            break;
        case 3:
            editDul();
            break;
        case 4:
            editSal();
            break;
        case 5:
            editHog();
            break;
        case 6:
            editAli();
            break;
        default:
            band = false;
            break;
        }
    } while (band == true);
}
// compra
void menuCOM()
{
    short dec;
    bool band = true;
    do
    {
        cout << "CLIENTE: " << seleccionado->person.nombre;
        cout << "\n**** MENU DE COMPRA ****" << endl;
        cout << "1- Bebidas no Alcoholicas " << endl;
        cout << "2- Bebidas Alcoholicas " << endl;
        cout << "3- Snack Dulce " << endl;
        cout << "4- Snack Salado " << endl;
        cout << "5- Alimentos " << endl;
        cout << "6- Productos del Hogar " << endl;
        cout << "7- Salir " << endl;
        cin >> dec;
        switch (dec)
        {
        case 1:
            comBeb();
            break;
        case 2:
            comAlco();
            break;
        case 3:
            comDul();
            break;
        case 4:
            mostSAL();
            break;
        case 5:
            most_alim();
            break;
        case 6:
            most_hog();
            break;
        default:
            band = false;
            break;
        }
    } while (band == true);
}
// agregado
void menuAg()
{
    short dec;
    bool band = true;
    do
    {
        cout << "\n**** MENU DE AGREGADO ****" << endl;
        cout << "1- Bebidas no Alcoholicas " << endl;
        cout << "2- Bebidas Alcoholicas " << endl;
        cout << "3- Snack Dulce " << endl;
        cout << "4- Snack Salado " << endl;
        cout << "5- Alimentos " << endl;
        cout << "6- Productos del Hogar " << endl;
        cout << "7- Salir " << endl;
        cin >> dec;
        switch (dec)
        {
        case 1:
            agBeb();
            break;
        case 2:
            agAL();
            break;
        case 3:
            agDUL();
            break;
        case 4:
            agSAL();
            break;
        case 5:
            ag_alimentos();
            break;
        case 6:
            ag_prodHogar();
            break;
        default:
            band = false;
            break;
        }
    } while (band == true);
}
// eliminacion
void menuDEL()
{
    short dec;
    bool band = true;
    do
    {
        cout << "\n**** MENU DE ELIMINAR ****" << endl;
        cout << "1- Bebidas no Alcoholicas " << endl;
        cout << "2- Bebidas Alcoholicas " << endl;
        cout << "3- Snack Salado " << endl;
        cout << "4- Snack Dulce " << endl;
        cout << "5- Alimentos " << endl;
        cout << "6- Productos del Hogar " << endl;
        cout << "7- Salir " << endl;
        cin >> dec;
        switch (dec)
        {
        case 1:
            delet_beb();
            break;
        case 2:
            delet_alco();
            break;
        case 3:
            delet_sal();
            break;
        case 4:
            delet_dulce();
            break;
        case 5:
            delet_Ali();
            break;
        case 6:
            delet_Hog();
            break;
        default:
            band = false;
            break;
        }
    } while (band == true);
}

void menu()
{
    short r;
    short dec;
    bool band = true;
    do
    {
        cout << "**** DIOS ES AMOR ****" << endl;
        cout << "1- Agregar " << endl;
        cout << "2- Comprar " << endl;
        cout << "3- Editar " << endl;
        cout << "4- Eliminar " << endl;
        cout << "5- Salir " << endl;
        cin >> dec;
        switch (dec)
        {
        case 1:
            cout << "Cliente [1]: " << endl;
            cout << "Productos [2]: " << endl;
            cin >> r;
            if (r == 1)
                agregarClients();
            if (r == 2)
                menuAg();
            break;
        case 2:
            elegirCl();
            break;
        case 3:
            cout << "Cliente [1]: " << endl;
            cout << "Productos [2]: " << endl;
            cin >> r;
            if (r == 1)
                editClient();
            if (r == 2)
                MenuEdit();
            break;
        case 4:
            cout << "Cliente [1]: " << endl;
            cout << "Productos [2]: " << endl;
            cin >> r;
            if (r == 1)
                deletClients();
            if (r == 2)
                menuDEL();
            break;

        default:
            band = false;
            break;
        }
    } while (band);
}

int main()
{
    menu();
}

#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "eliminar.h"
#include "clientes.h"

using namespace std;

void menuCOM()
{
    short dec;
    bool band = true;
    do
    {
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
            mostBEB();
            break;
        case 2:
            mostALCO();
            break;
        case 3:
            mostDUL();
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
            break;
        default:
            band = false;
            break;
        }
    } while (band == true);
}

void menu()
{
    //
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
            menuCOM();
            break;
        case 3:

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

main()
{
    menu();
}

#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "agregar_ver.h"

using namespace std;

// eliminar
void delet_beb()
{
    nodoBeb *actual = primeroB;
    nodoBeb *ante;
    nodoBeb *sigue;
    string code;
    mostBEB();
    if (actual != NULL)
    {
        cout << "Ingresa el codigo de la bebida: ";
        cin >> code;
        while (actual != NULL)
        {
            if (actual->bebidas.codigo == code)
            {
                if (actual == primeroB)
                {
                    primeroB = primeroB->sig;
                    if (primeroB == NULL)
                    {
                        ultimoB = primeroB;
                    }
                    else
                    {
                        primeroB->ant = NULL;
                    }
                    delete actual;
                    break;
                }
                else
                {
                    if (actual == ultimoB)
                    {
                        ultimoB = ultimoB->ant;
                        ultimoB->sig = NULL;
                    }
                    else
                    {
                        ante = actual->ant;
                        sigue = actual->sig;
                        // conectamos
                        ante->sig = sigue;
                        sigue->ant = ante;
                    }
                    delete actual;
                    break;
                }
            }
            actual = actual->sig;
            if (actual == NULL)
            {
                cout << "No encontrado ";
                break;
            }
        }
    }
}

void delet_alco()
{
    nodoAl *borrar = primeroAh;
    nodoAl *anterior;
    nodoAl *siguiente;
    string code;
    mostALCO();
    if (borrar != NULL)
    {
        cout << "Ingresa el codigo de la bebida a eliminar: ";
        cin >> code;
        while (borrar != NULL)
        {
            if (borrar->alcolicas.codigo == code)
            {
                if (borrar == primeroAh)
                { // borramos el primero
                    primeroAh = primeroAh->sig;
                    if (primeroAh == NULL)
                    { // cuando solo queda uno
                        ultimoAh = primeroAh;
                    }
                    else
                    { // cuando hay mas d 1
                        primeroAh->ant = NULL;
                    }
                    delete borrar;
                    break; // rompo pq ya lo encontre
                }
                else
                {
                    if (borrar == ultimoAh)
                    {
                        ultimoAh = ultimoAh->ant;
                        ultimoAh->sig = NULL;
                    }
                    else
                    {
                        anterior = borrar->ant;
                        siguiente = borrar->sig;
                        // conectamos
                        anterior->sig = siguiente;
                        siguiente->ant = anterior;
                    }
                    delete borrar;
                    break;
                }
            }
            borrar = borrar->sig;
            if (borrar == NULL)
            {
                cout << "No encontrado";
                break;
            }
        }
    }
}

void delet_sal()
{
    string code;
    nodoSAL *actual = primeroSA;
    nodoSAL *anterior;
    nodoSAL *siguiente;
    mostSAL();
    if (actual != NULL)
    {
        cout << "Ingresa el codigo del snack a eliminar: ";
        cin >> code;
        while (actual != NULL)
        {
            if (actual != NULL)
            {
                if (actual->snSAL.codigo == code)
                {
                    if (actual == primeroSA)
                    {
                        primeroSA = primeroSA->sig;
                        if (primeroSA == NULL)
                        { // cuando queda un elemento
                            ultimoSA = primeroSA;
                        }
                        else
                        {
                            primeroSA->ant = NULL;
                        }
                        delete actual;
                        break;
                    }
                    else
                    {
                        if (actual == ultimoSA)
                        { // cuando haya 2 o mas
                            ultimoSA = ultimoSA->ant;
                            ultimoSA->sig = NULL;
                        }
                        else // cuando el elemento no sea ni el inicio ni el final
                        {
                            anterior = actual->ant;
                            siguiente = actual->sig;
                            // ahora conectamos
                            anterior->sig = siguiente;
                            siguiente->ant = anterior;
                        }
                        delete actual;
                        break;
                    }
                }
            }
            actual = actual->sig;
            if (actual == NULL)
            {
                cout << "No existe tal producto";
                break;
            }
        }
    }
}

void delet_dulce()
{
    nodoDUL *actual = primeroD;
    nodoDUL *anterior;
    nodoDUL *siguiente;
    string code = " ";
    mostDUL();
    if (actual != NULL)
    {
        cout << "Ingresa codigo de snack a eliminar: ";
        cin >> code;
        while (actual != NULL)
        {
            if (actual->snDul.codigo == code)
            {
                if (actual == primeroD)
                {
                    primeroD = primeroD->sig;
                    if (primeroD == NULL)
                    {
                        ultimoD = primeroD;
                    }
                    else
                    {
                        primeroD->ant = NULL;
                    }
                    delete actual;
                    break;
                }
                else
                {
                    if (actual == ultimoD)
                    {
                        ultimoD = ultimoD->ant;
                        ultimoD->sig = NULL;
                    }
                    else
                    {
                        anterior = actual->ant;
                        siguiente = actual->sig;
                        // conectamos
                        anterior->sig = siguiente;
                        siguiente->ant = anterior;
                    }
                    delete actual;
                    break;
                }
            }
            actual = actual->sig;
            if (actual == NULL)
            {
                cout << "No encontrado";
                break;
            }
        }
    }
}

// MENUS
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
            menuAg();
            break;
        case 2:
            menuCOM();
            break;
        case 3:

            break;
        case 4:
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

#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "clientes.h"
#include "eliminar.h"
//
using namespace std;
void comBeb();
nodoClient *seleccionado = NULL;
void elegirCl()
{
    seleccionado = NULL;
    short i = 1;
    nodoClient *actual = primerC;
    string dni;
    mostClients();
    if (actual != NULL)
    {
        cout << "Ingresar DNI: ";
        cin >> dni;
        while (actual != NULL)
        {
            if (actual->person.dni == dni)
            {
                cout << "\nCliente [" << i << "] SELECCIONADO " << endl;
                cout << "Nombre: " << actual->person.nombre << endl;
                cout << "Apellido: " << actual->person.apellido << endl;
                cout << "DNI: " << actual->person.dni << endl;
                cout << "Edad: " << actual->person.edad << endl;
                cout << "Deuda: $" << actual->person.deuda << endl;
                seleccionado = actual;
                break;
            }
            else
            {
                i++;
                actual = actual->sig;
            }
            if (actual == NULL)
            {
                cout << "No encontrado " << endl;
                break;
            }
        }
    }
    if (seleccionado != NULL)
    {
        menuCOM();
    }
}

void comBeb()
{
    nodoBeb *comprado = NULL;
    nodoBeb *actual = primeroB;
    string code;
    short cant;
    short stock;
    float precio;
    mostBEB();
    if (actual != NULL)
    {
        cout << "Ingresa el codigo de la bebida a compra: ";
        cin >> code;
        while (actual != NULL)
        {
            if (actual->bebidas.codigo == code)
            {
                cout << "Bebida comprada: " << endl;
                cout << "Nombre: " << actual->bebidas.nombre << endl;
                cout << "Precio: " << actual->bebidas.precio << endl;
                cout << "Litros: " << actual->bebidas.litros << endl;
                cout << "Stock: " << actual->bebidas.stock << endl;
                cout << "Ingresa cantidad: ";
                cin >> cant;
                stock = actual->bebidas.stock;
                if (stock <= 0)
                {
                    cout << "Sin stock";
                    break;
                }
                else
                {
                    comprado = actual;
                    precio = comprado->bebidas.precio;
                    comprado->bebidas.stock = comprado->bebidas.stock - cant;
                    seleccionado->person.deuda = precio * cant;
                }
                break;
            }
            else
            {
                actual = actual->sig;
            }
            if (actual == NULL)
            {
                cout << "No encontrado " << endl;
                break;
            }
        }
    }
}
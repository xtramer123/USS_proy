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
void comAlco();
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
                if (stock - cant < 0)
                {
                    cout << "Error en la compra";
                    return;
                }
                else
                {
                    comprado = actual;
                    precio = comprado->bebidas.precio;
                    comprado->bebidas.stock -= cant; // acortado
                    seleccionado->person.deuda += (precio * cant);
                    short pos = seleccionado->person.cantidad.bebCom;
                    seleccionado->person.cantidad.bebCom++;
                    seleccionado->person.boletaNom.noAlc[pos] = comprado->bebidas.nombre;
                    seleccionado->person.boletaPre.noAlc[pos] = comprado->bebidas.precio;
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

void comAlco()
{
    nodoAl *comprado = NULL;
    nodoAl *actual = primeroAh;
    string codigo;
    short cant, stock, precio;
    mostALCO();
    if (actual != NULL)
    {
        cout << "Ingresa codigo de bebida a comprar: ";
        cin >> codigo;
        while (actual != NULL)
        {
            if (actual->alcolicas.codigo == codigo)
            {
                cout << "Bebida comprada " << endl;
                cout << "Nombre: " << actual->alcolicas.nombre << endl;
                cout << "Precio: $" << actual->alcolicas.precio << endl;
                cout << "litros: " << actual->alcolicas.litros << "L" << endl;
                cout << "Stock: " << actual->alcolicas.stock << endl;
                stock = actual->alcolicas.stock;
                cout << "Ingresa cantidad a comprar: ";
                cin >> cant;
                if (stock - cant < 0)
                {
                    cout << "Error en la compra" << endl;
                    return;
                }
                else
                {
                    comprado = actual;
                    precio = comprado->alcolicas.precio;
                    seleccionado->person.deuda += (precio * cant);
                    comprado->alcolicas.stock -= cant;
                    short pos = seleccionado->person.cantidad.alcoComp;
                    seleccionado->person.cantidad.alcoComp++;
                    seleccionado->person.boletaNom.acoli[pos] = comprado->alcolicas.nombre;
                    seleccionado->person.boletaPre.acoli[pos] = comprado->alcolicas.precio;
                }
            }
            else
            {
                actual = actual->sig;
            }
            if (actual == NULL)
            {
                cout << "No encontrado ";
                break;
            }
        }
    }
}
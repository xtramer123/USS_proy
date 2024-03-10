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
void comDul();
void comSal();
void comAli();
void comHo();
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
                    seleccionado->person.boletaCanti.noAlc[pos] = cant;
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
                    seleccionado->person.boletaCanti.acoli[pos] = cant;
                }
                break;
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

void comDul()
{
    nodoDUL *comprado = NULL;
    nodoDUL *actual = primeroD;
    string codigo;
    short cant, stock, precio;
    mostDUL();
    if (actual != NULL)
    {
        cout << "Ingresa codigo del snack a comprar: ";
        cin >> codigo;
        while (actual != NULL)
        {
            if (actual->snDul.codigo == codigo)
            {
                cout << "Snack comprado " << endl;
                cout << "Nombre: " << actual->snDul.nombre << endl;
                cout << "Precio: $" << actual->snDul.precio << endl;
                cout << "Peso: " << actual->snDul.kilos << "Kg" << endl;
                cout << "Stock: " << actual->snDul.stock << endl;
                stock = actual->snDul.stock;
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
                    precio = comprado->snDul.precio;
                    seleccionado->person.deuda += (precio * cant);
                    comprado->snDul.stock -= cant;
                    short pos = seleccionado->person.cantidad.snDul;
                    seleccionado->person.cantidad.snDul++;
                    seleccionado->person.boletaNom.dul[pos] = comprado->snDul.nombre;
                    seleccionado->person.boletaPre.dul[pos] = comprado->snDul.precio;
                    seleccionado->person.boletaCanti.dul[pos] = cant;
                }
                break;
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

void comSal()
{
    nodoSAL *comprado = NULL;
    nodoSAL *actual = primeroSA;
    string codigo;
    short cant, stock, precio;
    mostSAL();
    if (actual != NULL)
    {
        cout << "Ingresa codigo del snack a comprar: ";
        cin >> codigo;
        while (actual != NULL)
        {
            if (actual->snSAL.codigo == codigo)
            {
                cout << "Snack comprado " << endl;
                cout << "Nombre: " << actual->snSAL.nombre << endl;
                cout << "Precio: $" << actual->snSAL.precio << endl;
                cout << "Peso: " << actual->snSAL.kilos << "Kg" << endl;
                cout << "Stock: " << actual->snSAL.stock << endl;
                stock = actual->snSAL.stock;
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
                    precio = comprado->snSAL.precio;
                    seleccionado->person.deuda += (precio * cant);
                    comprado->snSAL.stock -= cant;
                    short pos = seleccionado->person.cantidad.snSal;
                    seleccionado->person.cantidad.snSal++;
                    seleccionado->person.boletaNom.sal[pos] = comprado->snSAL.nombre;
                    seleccionado->person.boletaPre.sal[pos] = comprado->snSAL.precio;
                    seleccionado->person.boletaCanti.sal[pos] = cant;
                }
                break;
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

void comAli()
{
    nodoAlimentos *comprado = NULL;
    nodoAlimentos *actual = primeroAi;
    string codigo;
    short cant, stock, precio;
    most_alim();
    if (actual != NULL)
    {
        cout << "Ingresa codigo del alimento a comprar: ";
        cin >> codigo;
        while (actual != NULL)
        {
            if (actual->pr_al.codigo == codigo)
            {
                cout << "Snack comprado " << endl;
                cout << "Nombre: " << actual->pr_al.nombre << endl;
                cout << "Precio: $" << actual->pr_al.precio << endl;
                cout << "Peso: " << actual->pr_al.kilos << "Kg" << endl;
                cout << "Stock: " << actual->pr_al.stock << endl;
                stock = actual->pr_al.stock;
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
                    precio = comprado->pr_al.precio;
                    seleccionado->person.deuda += (precio * cant);
                    comprado->pr_al.stock -= cant;
                    short pos = seleccionado->person.cantidad.pAli;
                    seleccionado->person.cantidad.pAli++;
                    seleccionado->person.boletaNom.ali[pos] = comprado->pr_al.nombre;
                    seleccionado->person.boletaPre.ali[pos] = comprado->pr_al.precio;
                    seleccionado->person.boletaCanti.ali[pos] = cant;
                }
                break;
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

void comHo()
{
    nodoHogar *comprado = NULL;
    nodoHogar *actual = primeroHo;
    string codigo;
    short cant, stock, precio;
    most_hog();
    if (actual != NULL)
    {
        cout << "Ingresa codigo del alimento a comprar: ";
        cin >> codigo;
        while (actual != NULL)
        {
            if (actual->pr_hogar.codigo == codigo)
            {
                cout << "Snack comprado " << endl;
                cout << "Nombre: " << actual->pr_hogar.nombre << endl;
                cout << "Precio: $" << actual->pr_hogar.precio << endl;
                cout << "Stock: " << actual->pr_hogar.stock << endl;
                stock = actual->pr_hogar.stock;
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
                    precio = comprado->pr_hogar.precio;
                    seleccionado->person.deuda += (precio * cant);
                    comprado->pr_hogar.stock -= cant;
                    short pos = seleccionado->person.cantidad.pHog;
                    seleccionado->person.cantidad.pHog++;
                    seleccionado->person.boletaNom.hog[pos] = comprado->pr_hogar.nombre;
                    seleccionado->person.boletaPre.hog[pos] = comprado->pr_hogar.precio;
                    seleccionado->person.boletaCanti.hog[pos] = cant;
                }
                break;
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
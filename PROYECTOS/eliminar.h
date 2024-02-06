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

void delet_Ali()
{
    string code;
    nodoAlimentos *borrar = primeroAi;
    nodoAlimentos *anterior;
    nodoAlimentos *siguiente;
    most_alim();
    if (borrar != NULL)
    {
        cout << "Ingresa codigo: ";
        cin >> code;
        while (borrar != NULL)
        {
            if (borrar->pr_al.codigo == code)
            {
                if (borrar == primeroAi)
                {
                    primeroAi = primeroAi->sig;
                    if (primeroAi == NULL)
                    {
                        ultimoAi = primeroAi;
                    }
                    else
                    {
                        primeroAi->ant = NULL;
                    }
                    delete borrar;
                    break;
                }
                else
                {
                    if (borrar == ultimoAi)
                    {
                        ultimoAi = ultimoAi->ant;
                        ultimoAi->sig = NULL;
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
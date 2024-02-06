#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;
void agregarClients();
void deletClients();
void mostClients();
void editClient();
void elegirCl();
struct datos
{
    string nombre;
    string apellido;
    short edad;
    float deuda;
    string dni;
};
struct nodoClient
{
    datos person;
    nodoClient *sig;
    nodoClient *ant;
} *primerC = NULL, *ultimoC = NULL;

void agregarClients()
{
    nodoClient *nuevo = new nodoClient;
    fflush(stdin);
    cout << "Ingresa nombre: ";
    getline(cin, nuevo->person.nombre);
    fflush(stdin);
    cout << "Ingresa apellido: ";
    getline(cin, nuevo->person.apellido);
    fflush(stdin);
    cout << "Ingresa DNI: ";
    cin >> nuevo->person.dni;
    cout << "Ingresa edad: ";
    cin >> nuevo->person.edad;
    nuevo->person.deuda = 0;
    if (primerC == NULL)
    {
        primerC = nuevo;
        primerC->ant = NULL;
        primerC->sig = NULL;
        ultimoC = primerC;
    }
    else
    {
        ultimoC->sig = nuevo;
        nuevo->ant = ultimoC;
        nuevo->sig = NULL;
        ultimoC = nuevo;
    }
    system("pause");
    system("cls");
    fflush(stdin);
}

void mostClients()
{
    short i = 1;
    nodoClient *actual = primerC;
    if (actual != NULL)
    {
        while (actual != NULL)
        {
            cout << "\nCliente [" << i << "] " << endl;
            cout << "Nombre: " << actual->person.nombre << endl;
            cout << "Apellido: " << actual->person.apellido << endl;
            cout << "DNI: " << actual->person.dni << endl;
            cout << "Edad: " << actual->person.edad << endl;
            cout << "Deuda: $" << actual->person.deuda << endl;
            actual = actual->sig;
        }
    }
    else
    {
        cout << "NO hay clientes agregados " << endl;
        system("pause");
        system("cls");
    }
}

void deletClients()
{
    nodoClient *borrar = primerC;
    nodoClient *anterior;
    nodoClient *siguiente;
    string dni;
    mostClients();
    if (borrar != NULL)
    {
        cout << "Ingresar DNI: ";
        cin >> dni;
        while (borrar != NULL)
        {
            if (borrar->person.dni == dni)
            {
                if (borrar == primerC)
                {
                    primerC = primerC->sig;
                    if (primerC == NULL)
                    {
                        ultimoC = primerC;
                    }
                    else
                    {
                        primerC->ant = NULL;
                    }
                    delete borrar;
                    break;
                }
                else
                {
                    if (borrar == ultimoC)
                    {
                        ultimoC = ultimoC->ant;
                        ultimoC->sig = NULL;
                    }
                    else
                    {
                        anterior = borrar->ant;
                        anterior = borrar->sig;
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
                cout << "No encontrado" << endl;
                system("pause");
                system("cls");
            }
        }
    }
}

void elegirCl()
{
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
                actual = actual->sig;
            }
            i++;
            actual = actual->sig;
            if (actual == NULL)
            {
                cout << "No encontrado " << endl;
                break;
            }
        }
    }
}

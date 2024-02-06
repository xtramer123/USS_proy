#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;
void agregarClients();
void deletClients();
void mostClients();
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
    cin >> nuevo->person.apellido;
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

void deletClients()
{
}

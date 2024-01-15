#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

// CUERPO DE PRODUCTOS EN GENERAL
struct bodyProd
{
    string nombre;
    float litros;
    float precio;
    unsigned short stock;
    string codigo;
    float kilos;
};
// structs o nodos de bebidas
struct nodoBeb
{
    bodyProd bebidas;
    nodoBeb *sig;
    nodoBeb *ant;
} *primeroB = NULL, *ultimoB = NULL;
// nodo alcoholicas
struct nodoAl
{
    bodyProd alcolicas;
    nodoAl *sig;
    nodoAl *ant;
} *primeroAh = NULL, *ultimoAh = NULL;
// variables globales
short cantbeb = 0;
short cantAL = 0;
// declarando funciones
void menu();
void menuAg();
void agBeb();
void agAL();
void comprarBEB();
void comprarAL();

void agBeb()
{
    fflush(stdin);
    string nombre;
    // string raiz que tendra la 1° del cod de prod.
    char code1[10] = "PB_N-";
    // string secun. que sera la cant convertida en texto.
    string code2 = to_string(cantbeb);
    nodoBeb *nuevo = new nodoBeb();
    fflush(stdin);
    cout << "Ingresa Nombre de bebida " << cantbeb + 1 << ": ";
    getline(cin, nuevo->bebidas.nombre);
    nombre = nuevo->bebidas.nombre;
    fflush(stdin);
    cout << "Ingresa precio de bebida " << nombre << ": ";
    cin >> nuevo->bebidas.precio;
    cout << "Ingresa litros de bebida " << nombre << ": ";
    cin >> nuevo->bebidas.litros;
    cout << "Ingresa Stock de bebida " << nombre << ": ";
    cin >> nuevo->bebidas.stock;
    // ahora code 1 es la raiz + la sec.
    strcat(code1, code2.c_str());
    // el codigo final es el code 1 concatenado.
    nuevo->bebidas.codigo = code1;
    cout << "CODIGO GENERADO AUTOMATICAMENTE: " << nuevo->bebidas.codigo << endl;
    // cambiamos la cantidad y el string , 2 pajaros de un tiro
    if (primeroB == NULL)
    {
        primeroB = nuevo;
        primeroB->ant = NULL;
        primeroB->sig = NULL;
        ultimoB = primeroB;
    }
    else
    {
        ultimoB->sig = nuevo;
        nuevo->ant = ultimoB;
        nuevo->sig = NULL;
        ultimoB = nuevo;
    }
    cantbeb++;
    system("Pause");
    system("cls");
}

void comprarBEB()
{
    nodoBeb *actual = primeroB;
    short i = 1;
    while (actual != NULL)
    {
        cout << "\nBEBIDA  " << i << endl;
        cout << "Nombre: " << actual->bebidas.nombre << endl;
        cout << "Precio: $" << actual->bebidas.precio << endl;
        cout << "Litros: " << actual->bebidas.litros << "L" << endl;
        cout << "Stock: " << actual->bebidas.stock << endl;
        cout << "Codigo de compra: " << actual->bebidas.codigo << endl;
        i++;
        actual = actual->sig;
    }
}

void comprarAL()
{
    nodoAl *alco = primeroAh;
    short i = 1;
    while (alco != NULL)
    {
        cout << "\nBEBIDA  " << i << endl;
        cout << "Nombre: " << alco->alcolicas.nombre << endl;
        cout << "Precio: $" << alco->alcolicas.precio << endl;
        cout << "Litros: " << alco->alcolicas.litros << "L" << endl;
        cout << "Stock: " << alco->alcolicas.stock << endl;
        cout << "Codigo de compra: " << alco->alcolicas.codigo << endl;
        i++;
        alco = alco->sig;
    }
}

void agAL()
{
    fflush(stdin);
    string nombre;
    // string raiz que tendra la 1° del cod de prod.
    char code1[10] = "PB_AL-";
    // string secun. que sera la cant convertida en texto.
    string code2 = to_string(cantAL);
    nodoAl *nuevoAL = new nodoAl();
    fflush(stdin);
    cout << "Ingresa Nombre de bebida alcoholica " << cantAL + 1 << ": ";
    getline(cin, nuevoAL->alcolicas.nombre);
    nombre = nuevoAL->alcolicas.nombre;
    fflush(stdin);
    cout << "Ingresa precio de bebida " << nombre << ": ";
    cin >> nuevoAL->alcolicas.precio;
    cout << "Ingresa litros de bebida " << nombre << ": ";
    cin >> nuevoAL->alcolicas.litros;
    cout << "Ingresa Stock de bebida " << nombre << ": ";
    cin >> nuevoAL->alcolicas.stock;
    // ahora code 1 es la raiz + la sec.
    strcat(code1, code2.c_str());
    // el codigo final es el code 1 concatenado.
    nuevoAL->alcolicas.codigo = code1;
    cout << "CODIGO GENERADO AUTOMATICAMENTE: " << nuevoAL->alcolicas.codigo << endl;
    // cambiamos la cantidad y el string , 2 pajaros de un tiro
    if (primeroAh == NULL)
    {
        primeroAh = nuevoAL;
        primeroAh->ant = NULL;
        primeroAh->sig = NULL;
        ultimoAh = primeroAh;
    }
    else
    {
        ultimoAh->sig = nuevoAL;
        nuevoAL->sig = NULL;
        nuevoAL->ant = ultimoAh;
        ultimoAh = nuevoAL;
    }
    cantAL++;
    system("Pause");
    system("cls");
}

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
            comprarBEB();
            break;
        case 2:
            comprarAL();
            break;
        case 3:
            break;
        case 4:
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
            break;
        case 4:
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

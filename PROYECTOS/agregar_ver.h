#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;
// hola xd
//  CUERPO DE PRODUCTOS EN GENERAL c
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
// nodo snack dulce
struct nodoDUL
{
    bodyProd snDul;
    nodoDUL *sig;
    nodoDUL *ant;
} *primeroD = NULL, *ultimoD = NULL;
// nodo snack salado
struct nodoSAL
{
    bodyProd snSAL;
    nodoSAL *sig;
    nodoSAL *ant;
} *primeroSA = NULL, *ultimoSA = NULL;

struct nodoAlimentos
{
    bodyProd pr_al;
    nodoAlimentos *sig;
    nodoAlimentos *ant;
} *primeroAi = NULL, *ultimoAi = NULL;

struct nodoHogar
{
    bodyProd pr_hogar;
    nodoHogar *sig;
    nodoHogar *ant;
} *primeroHo = NULL, *ultimoHo = NULL;

// variables globales
short cantbeb = 0;
short cantAL = 0;
short dulce = 0;
short salado = 0;
short alimento = 0;
short Hogar = 0;
// declarando funciones
void menu();
void menuCOM();
void MenuEdit();
void menuAg();
void agBeb();
void agAL();
void mostBEB();
void mostALCO();
void mostSAL();
void mostDUL();
void agSAL();
void agDUL();
void ag_alimentos();
void ag_prodHogar();
void menuDEL();
void delet_beb();
void delet_alco();
void delet_sal();
void delet_dulce();
void delet_Ali();
void delet_Hog();
// agregando
void agBeb()
{
    if (primeroB == NULL)
        cantbeb = 0;
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
void agAL()
{
    if (primeroAh == NULL)
        cantAL = 0;
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

// snack salado
void agSAL()
{
    if (primeroSA == NULL)
        salado = 0;
    fflush(stdin);
    string nombre;
    // string raiz que tendra la 1° del cod de prod.
    char code1[15] = "SN_SAL-";
    // string secun. que sera la cant convertida en texto.
    string code2 = to_string(salado);
    nodoSAL *nuevo_sal = new nodoSAL();
    fflush(stdin);
    cout << "Ingresa Nombre del snack salado " << salado + 1 << ": ";
    getline(cin, nuevo_sal->snSAL.nombre);
    nombre = nuevo_sal->snSAL.nombre;
    fflush(stdin);
    cout << "Ingresa precio del snack " << nombre << ": ";
    cin >> nuevo_sal->snSAL.precio;
    cout << "Ingresa peso del snack " << nombre << ": ";
    cin >> nuevo_sal->snSAL.kilos;
    cout << "Ingresa Stock del snack " << nombre << ": ";
    cin >> nuevo_sal->snSAL.stock;
    // ahora code 1 es la raiz + la sec.
    strcat(code1, code2.c_str());
    // el codigo final es el code 1 concatenado.
    nuevo_sal->snSAL.codigo = code1;
    cout << "CODIGO GENERADO AUTOMATICAMENTE: " << nuevo_sal->snSAL.codigo << endl;
    // cambiamos la cantidad y el string , 2 pajaros de un tiro
    if (primeroSA == NULL)
    {
        primeroSA = nuevo_sal;
        primeroSA->ant = NULL;
        primeroSA->sig = NULL;
        ultimoSA = primeroSA;
    }
    else
    {
        ultimoSA->sig = nuevo_sal;
        nuevo_sal->ant = ultimoSA;
        nuevo_sal->sig = NULL;
        ultimoSA = nuevo_sal;
    }
    salado++;
    system("Pause");
    system("cls");
}
// snack dulce
void agDUL()
{
    if (primeroD == NULL)
        dulce = 0;
    string nombre;
    char code1[15] = "SN_DUL-";
    string code2 = to_string(dulce);
    nodoDUL *nuevo_dulce = new nodoDUL();
    fflush(stdin);
    cout << "Ingresa nombre del snack dulce " << dulce + 1 << " :";
    getline(cin, nuevo_dulce->snDul.nombre);
    nombre = nuevo_dulce->snDul.nombre;
    cout << "Ingresa precio de " << nombre << " :";
    cin >> nuevo_dulce->snDul.precio;
    cout << "Ingresa peso de " << nombre << " :";
    cin >> nuevo_dulce->snDul.kilos;
    cout << "Ingresa stock de " << nombre << " :";
    cin >> nuevo_dulce->snDul.stock;
    strcat(code1, code2.c_str());
    nuevo_dulce->snDul.codigo = code1;
    cout << "Codigo generado :" << code1 << endl;
    if (primeroD == NULL)
    {
        primeroD = nuevo_dulce;
        primeroD->ant = NULL;
        primeroD->sig = NULL;
        ultimoD = primeroD;
    }
    else
    {
        ultimoD->sig = nuevo_dulce;
        nuevo_dulce->ant = ultimoD;
        nuevo_dulce->sig = NULL;
        ultimoD = nuevo_dulce;
    }
    dulce++;
    system("pause");
    system("cls");
    fflush(stdin);
}

void ag_alimentos()
{
    if (primeroAi == NULL)
        alimento = 0;
    string nombre;
    char code1[20] = "PR_ALIM-";
    string code2 = to_string(alimento);
    nodoAlimentos *nuevo = new nodoAlimentos;
    fflush(stdin);
    cout << "Ingresa nombre de producto alimenticio: ";
    getline(cin, nuevo->pr_al.nombre);
    nombre = nuevo->pr_al.nombre;
    cout << "Ingresa precio de " << nombre << ": ";
    cin >> nuevo->pr_al.precio;
    cout << "Ingresa Stock de " << nombre << ": ";
    cin >> nuevo->pr_al.stock;
    cout << "Ingresa peso de " << nombre << ": ";
    cin >> nuevo->pr_al.kilos;
    strcat(code1, code2.c_str());
    nuevo->pr_al.codigo = code1;
    cout << "Codigo generado: " << code1 << endl;
    if (primeroAi == NULL)
    {
        nuevo->sig = NULL;
        nuevo->ant = NULL;
        primeroAi = nuevo;
        ultimoAi = nuevo;
    }
    else
    {
        ultimoAi->sig = nuevo;
        nuevo->sig = NULL;
        nuevo->ant = ultimoAi;
        ultimoAi = nuevo;
    }
    alimento++;
    system("pause");
    system("cls");
    fflush(stdin);
}

void ag_prodHogar()
{
    if (primeroHo == NULL)
        Hogar = 0;
    string nombre;
    char code1[20] = "PR_HOG-";
    string code2 = to_string(Hogar);
    nodoHogar *nuevo = new nodoHogar;
    fflush(stdin);
    cout << "Ingresa nombre del producto del hogar: ";
    getline(cin, nuevo->pr_hogar.nombre);
    nombre = nuevo->pr_hogar.nombre;
    cout << "Ingresa precio de " << nombre << ": ";
    cin >> nuevo->pr_hogar.precio;
    cout << "Ingresa stock de " << nombre << ": ";
    cin >> nuevo->pr_hogar.stock;
    strcat(code1, code2.c_str());
    nuevo->pr_hogar.codigo = code1;
    cout << "Codigo del producto: " << code1 << endl;
    if (primeroHo == NULL)
    {
        nuevo->sig = NULL;
        nuevo->ant = NULL;
        primeroHo = nuevo;
        ultimoHo = primeroHo;
    }
    else
    {
        ultimoHo->sig = nuevo;
        nuevo->sig = NULL;
        nuevo->ant = ultimoHo;
        ultimoHo = nuevo;
    }
    Hogar++;
    system("pause");
    system("cls");
    fflush(stdin);
}

// comprando
void mostBEB()
{
    nodoBeb *actual = ultimoB;
    short i = 1;
    if (actual != NULL)
    {
        while (actual != NULL)
        {
            cout << "\nBEBIDA  " << i << endl;
            cout << "Nombre: " << actual->bebidas.nombre << endl;
            cout << "Precio: $" << actual->bebidas.precio << endl;
            cout << "Litros: " << actual->bebidas.litros << "L" << endl;
            cout << "Stock: " << actual->bebidas.stock << endl;
            cout << "Codigo de compra: " << actual->bebidas.codigo << endl;
            i++;
            actual = actual->ant;
        }
    }
    else
    {
        cout << "No has agregado ningun producto" << endl;
        system("pause");
        system("cls");
    }
}

void mostALCO()
{
    nodoAl *alco = ultimoAh;
    short i = 1;
    if (alco != NULL)
    {
        while (alco != NULL)
        {
            cout << "\nBEBIDA  " << i << endl;
            cout << "Nombre: " << alco->alcolicas.nombre << endl;
            cout << "Precio: $" << alco->alcolicas.precio << endl;
            cout << "Litros: " << alco->alcolicas.litros << "L" << endl;
            cout << "Stock: " << alco->alcolicas.stock << endl;
            cout << "Codigo de compra: " << alco->alcolicas.codigo << endl;
            i++;
            alco = alco->ant;
        }
    }
    else
    {
        cout << "No has agregado ningun producto" << endl;
        system("pause");
        system("cls");
    }
}

void mostSAL()
{
    nodoSAL *saladito = primeroSA;
    short i = 1;
    if (saladito != NULL)
    {
        while (saladito != NULL)
        {
            cout << "\nSNACK  " << i << endl;
            cout << "Nombre: " << saladito->snSAL.nombre << endl;
            cout << "Precio: $" << saladito->snSAL.precio << endl;
            cout << "Peso: " << saladito->snSAL.kilos << "Kg." << endl;
            cout << "Stock: " << saladito->snSAL.stock << endl;
            cout << "Codigo de compra: " << saladito->snSAL.codigo << endl;
            i++;
            saladito = saladito->sig;
        }
    }
    else
    {
        cout << "No has agregado ningun producto" << endl;
        system("pause");
        system("cls");
    }
}

void mostDUL()
{
    nodoDUL *dulcecito = primeroD;
    short i = 1;
    if (dulcecito != NULL)
    {
        while (dulcecito != NULL)
        {
            cout << "\nSNACK  " << i << endl;
            cout << "Nombre: " << dulcecito->snDul.nombre << endl;
            cout << "Precio: $" << dulcecito->snDul.precio << endl;
            cout << "Peso: " << dulcecito->snDul.kilos << "Kg." << endl;
            cout << "Stock: " << dulcecito->snDul.stock << endl;
            cout << "Codigo de compra: " << dulcecito->snDul.codigo << endl;
            i++;
            dulcecito = dulcecito->sig;
        }
    }
    else
    {
        cout << "No has agregado ningun producto" << endl;
        system("pause");
        system("cls");
    }
}

void most_alim()
{
    nodoAlimentos *actual = primeroAi;
    short i = 1;
    if (actual != NULL)
    {
        while (actual != NULL)
        {
            cout << "\nALIMENTO  " << i << endl;
            cout << "Nombre: " << actual->pr_al.nombre << endl;
            cout << "Precio: $" << actual->pr_al.precio << endl;
            cout << "Peso: " << actual->pr_al.kilos << "Kg." << endl;
            cout << "Stock: " << actual->pr_al.stock << endl;
            cout << "Codigo de compra: " << actual->pr_al.codigo << endl;
            i++;
            actual = actual->sig;
        }
    }
    else
    {
        cout << "No has agregado ningun producto" << endl;
        system("pause");
        system("cls");
    }
}
void most_hog()
{
    short i = 1;
    nodoHogar *actual = primeroHo;
    if (actual != NULL)
    {
        while (actual != NULL)
        {
            cout << "\nPROD. HOGAR  " << i << endl;
            cout << "Nombre: " << actual->pr_hogar.nombre << endl;
            cout << "Precio: $" << actual->pr_hogar.precio << endl;
            cout << "Stock: " << actual->pr_hogar.stock << endl;
            cout << "Codigo de compra: " << actual->pr_hogar.codigo << endl;
            i++;
            actual = actual->sig;
        }
    }
    else
    {
        cout << "No has agregado ningun producto" << endl;
        system("pause");
        system("cls");
    }
}

#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;
// hola xd
//  CUERPO DE PRODUCTOS EN GENERAL
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

// variables globales
short cantbeb = 0;
short cantAL = 0;
short dulce = 0;
short salado = 0;
short alimento = 0;
short Hogar = 0;
// declarando funciones
void menu();
void menuAg();
void agBeb();
void agAL();
void mostBEB();
void mostALCO();
void mostSAL();
void mostDUL();
void agSAL();
void agDUL();
void menuDEL();
void delet_beb();
void delet_alco();
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
    nodoAl *alco = primeroAh;
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
            alco = alco->sig;
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
            if ((actual->bebidas.codigo == code) && (actual == primeroB))
            { // esto quiere decir q queremos elimianr el primer elemento
                primeroB = primeroB->sig;
                if (primeroB == NULL)
                    ultimoB = NULL;
                delete actual;
                break;
            }
            else
            {
                actual = actual->sig;
                ante = actual->ant;
                sigue = actual->sig;
            }
            if ((actual->bebidas.codigo == code) && (actual != primeroB))
            {
                if (sigue != NULL)
                {
                    ante->sig = sigue;
                    sigue->ant = ante;
                }
                else
                {
                    ante->sig = NULL;
                    ultimoB = ante;
                }
                delete actual;
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
            if ((borrar->alcolicas.codigo == code) && (borrar == primeroAh))
            { // en caso sea el primero
                primeroAh = primeroAh->sig;
                if (primeroAh == NULL) // en caso el primero sea el ultimo
                    ultimoAh = primeroAh;
                delete borrar;
                break;
            }
            else
            {
                borrar = borrar->sig;
                anterior = borrar->ant;
                siguiente = borrar->sig;
            }
            if ((borrar->alcolicas.codigo == code) && (borrar != primeroAh))
            {
                if (siguiente == NULL)
                {
                    anterior->sig = NULL;
                    ultimoAh = anterior;
                }
                else
                {
                    anterior->sig = siguiente;
                    siguiente->ant = anterior;
                }
                delete borrar;
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
            agDUL();
            break;
        case 4:
            agSAL();
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

void menuDEL()
{
    short dec;
    bool band = true;
    do
    {
        cout << "\n**** MENU DE ELIMINAR ****" << endl;
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
            delet_beb();
            break;
        case 2:

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

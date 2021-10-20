#include <iostream>
using namespace std;

struct administracion
{
    string perfil;
    string nombre;
    int ID;
};

administracion solicitarDatos()
{
    administracion p;
    cout << "NOMBRE DEL USUARIO: ";
    getline(cin, p.nombre);
    cout << "CARGO: ";
    getline(cin, p.perfil);
    cout << "ID: ";
    cin >> p.ID;
    cin.ignore();

    return p;
}

void mostrarDatosDelUsuario(administracion p)
{
    cout << "NOMBRE DEL USUARIO: " << p.nombre << ","
         << " ";
    cout << "CARGO: " << p.perfil << ","
         << " ";
    cout << "ID: " << p.ID << endl;
}

typedef administracion A;

struct nodo
{
    A dato;
    nodo *sig;
    nodo *ant;
};

class listaDoble
{
private:
    nodo *pInicio;

public:
    listaDoble();
    ~listaDoble();
    void insertarFront(A);
    void insertarBack(A);
    void mostrar();
    void mostrarAlReves();
    void eliminar(A);
};

listaDoble::listaDoble()
{
    pInicio = NULL;
}

listaDoble::~listaDoble()
{
    nodo *p;
    while (pInicio)
    {
        p = pInicio;
        pInicio = pInicio->sig;
        delete p;
    }
}

void listaDoble::insertarFront(A dato)
{
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    nuevo->sig = pInicio;
    if (pInicio != NULL)
        pInicio->ant = nuevo;
    pInicio = nuevo;
}

void listaDoble::insertarBack(A dato)
{
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    if (!pInicio)
    {
        pInicio = nuevo;
        pInicio->sig = pInicio->ant = NULL;
    }
    else
    {
        nodo *saltarin = pInicio;
        while (saltarin->sig != NULL)
            saltarin = saltarin->sig;
        saltarin->sig = nuevo;
        nuevo->ant = saltarin;
        nuevo->sig = NULL;
    }
}

void listaDoble::mostrar(void)
{
    nodo *saltarin = pInicio;
    while (saltarin != NULL)
    {
        mostrarDatosDelUsuario(saltarin->dato);
        saltarin = saltarin->sig;
    }
}

void listaDoble::mostrarAlReves(void)
{
    if (!pInicio)
        return;
    nodo *p = pInicio;
    nodo *q = NULL;
    while (p)
    {
        q = p;
        p = p->sig;
    }
    while (q)
    {
        mostrarDatosDelUsuario(q->dato);
        q = q->ant;
    }
}

void listaDoble::eliminar(A datoB)
{
    if (!pInicio)
    {
        cout << "Actualmente no hay Datos." << endl;
    }
    else
    {
        nodo *saltarin = pInicio;
        while (saltarin && (saltarin->dato).ID != datoB.ID)
            saltarin = saltarin->sig;
        if (!saltarin)
            cout << "El Dato no está en la lista" << endl;
        else
        {
            if (!saltarin->ant && saltarin->sig)
            {
                pInicio = pInicio->sig;
                pInicio->ant = NULL;
                delete saltarin;
            }
            else if (saltarin->ant && !saltarin->sig)
            {
                saltarin->ant->sig = NULL;
                delete saltarin;
            }
            else if (saltarin->ant && saltarin->sig)
            {
                saltarin->ant->sig = saltarin->sig;
                saltarin->sig->ant = saltarin->ant;
                delete saltarin;
            }
            else
            {
                pInicio = NULL;
                delete saltarin;
            }
            cout << "Dato Eliminado exitosamente!" << endl;
        }
    }
}

int menu()
{
    int opcion = 0;
    cout << endl
         << "1) Insertar datos al Principio." << endl;
    cout << "2) Insertar datos al final." << endl;
    cout << "3) Mostrar en orden." << endl;
    cout << "4) Mostrar en orden(al reves)." << endl;
    cout << "5) Eliminar(a elegir)." << endl;
    cout << "6) Salir." << endl;
    cout << "Opcion: ";
    cin >> opcion;
    cin.ignore();
    return opcion;
}

int main()
{
    listaDoble admin;

    bool continuar = true;
    administracion A;
    administracion datoRef;
    do
    {
        switch (menu())
        {
        case 1:
            A = solicitarDatos();
            admin.insertarFront(A);
            cout << "Datos Guardados Existosamente!" << endl;
            break;
        case 2:
            A = solicitarDatos();
            admin.insertarBack(A);
            cout << "Datos Guardados Exitosamente!" << endl;
            break;
        case 3:
            admin.mostrar();
            break;
        case 4:
            admin.mostrarAlReves();
            break;
        case 5:
            A = solicitarDatos();
            admin.eliminar(A);
            break;
        case 6:
            continuar = false;
            break;
        default:
            cout << "Opcion no valida, favor intente de nuevo." << endl;
        }
    } while (continuar);

    return 0;
}
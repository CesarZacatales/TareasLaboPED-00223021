#include <iostream>

using namespace std;

struct administracion
{
    string nombre;
    string raza;
    double peso;
    int edad, ID;
};

administracion solicitarDatos()
{
    administracion p;
    cout << "NOMBRE DEL DUENIO: "; getline(cin, p.nombre);
    cout << "RAZA: "; getline(cin, p.raza);
    cout << "Peso: "; cin >> p.peso; cin.ignore();
    cout << "ID: "; cin >> p.ID; cin.ignore();

    return p;
}

void mostrarDatos(administracion p)
{
    cout << "NOMBRE DEL DUEÑO: " << p.nombre << endl;
    cout << "RAZA: " << p.raza << endl;
    cout << "Peso: " << p.peso << endl;
    cout << "ID: " << p.ID << endl;
}

typedef administracion A;

struct nodo
{
    A dato;
    nodo *sig;
    nodo *ant;
};

class listaCirc
{
    private:
    nodo *pInicio;

    public:
    listaCirc();
    ~listaCirc();
    void insertar(A);
    void mostrar();
    void eliminar(A);
};

listaCirc::listaCirc()
{
    pInicio = NULL;
}

listaCirc::~listaCirc()
{
    cout << "Destructor ejecutándose" << endl;
    if(pInicio)
    {
      nodo *saltarin = pInicio; 
      pInicio = saltarin->sig;
        saltarin = NULL;
        delete pInicio;
    }
}

void listaCirc::insertar(A dato)
{
      nodo *nuevo;

    nuevo = new nodo;
    nuevo->dato = dato;
    if(!pInicio){
        pInicio = nuevo;
        pInicio->sig = pInicio;
    }
    else{
        nuevo->sig = pInicio;
        nodo *saltarin = pInicio;
        while(saltarin->sig != pInicio){
            saltarin = saltarin->sig;
        }
        saltarin->sig = nuevo;
        pInicio = nuevo;
    }
}

void listaCirc::mostrar()
{
  nodo *saltarin;

    cout << endl;
    if(pInicio){
        saltarin = pInicio;
        do{
           mostrarDatos(saltarin->dato);
            saltarin = saltarin->sig;
        }while(saltarin != pInicio);
    }
}

void listaCirc::eliminar(A datoB)
{
    if(!pInicio){ 
        cout << "Actualmente no hay usuarios." << endl;
    }
    else{ 
        nodo *saltarin = pInicio;
        while(saltarin && (saltarin->dato).ID != datoB.ID)
            saltarin = saltarin->sig;
        if(!saltarin)
            cout << "El usuario no está en la lista" << endl;
        else{  
            if(!saltarin->ant && saltarin->sig){ 
                pInicio = pInicio->sig;
                pInicio->ant = NULL;
                delete saltarin;
            }
            else
                if(saltarin->ant && !saltarin->sig){
                    saltarin->ant->sig = NULL;
                    delete saltarin;
                }
                else
                    if(saltarin->ant && saltarin->sig){
                        saltarin->ant->sig = saltarin->sig;
                        saltarin->sig->ant = saltarin->ant;
                        delete saltarin;
                    }
                    else{
                        pInicio = NULL;
                        delete saltarin;
                    }
            cout << "Mascota eliminada exitosamente!" << endl;
        }
    }
}

int menu()
{
    int opcion = 0;
    cout << endl
         << "1) Insertar datos." << endl;
    cout << "2) Mostrar." << endl;
    cout << "3) Eliminar(a elegir)." << endl;
    cout << "4) Salir." << endl;
    cout << "Opcion: ";
    cin >> opcion;
    cin.ignore();
    return opcion;
}

int main()
{
    listaCirc admin;

    bool continuar = true;
    administracion A;
    int datoRef;
    do
    {
        switch (menu())
        {
        case 1:
            A = solicitarDatos();
            admin.insertar(A);
            cout << "Datos Guardados Existosamente!" << endl;
            break;
        case 2:
            admin.mostrar();
            break;
        case 3:
            A = solicitarDatos();
            admin.eliminar(A);
            break;
        case 4:
            continuar = false;
            break;
        default:
            cout << "Opcion no valida, favor intente de nuevo." << endl;
        }
    } while (continuar);

    return 0;
}
/*Escriba un programa que muestre un menu que permita administrar una lista  lineal simple con datos sobre personas. 
debera desplegar un menu con las siguientes opciones:
1) Llenar la lista
2) eliminar a una persona
3) mostrar a todas las personas
4) salir

Para cada persona ingresar su carnet, nombre, apellido, edad, numero de telefono y correo electronico.*/

#include <iostream>

using namespace std;

struct nodo
{
    int carne, edad, telefono;
    nodo *siguiente;
    char nombres[20], apellidos[20], correo[20];
};

typedef struct nodo *PrincipioDeLista;

class ListaSimple
{
private:
    nodo *PuntoDeInicio;

public:
    ListaSimple();
    void Menu(void);
    void LlenarLista(PrincipioDeLista &Lista);
    void EliminarDeLista(PrincipioDeLista &Lista);
    void MostrarLista(PrincipioDeLista aux2);
};

ListaSimple::ListaSimple(void)
{
    PuntoDeInicio = NULL;
}

void Menu(void)
{
    cout << endl
         << endl;
    cout << "\t ADMINISTACION DE REGISTROS" << endl;
    cout << endl;
    cout << "1. LLENAR REGISTRO CON UNA NUEVA PERSONA" << endl;
    cout << "2. ELIMINAR UNA PERSONA DEL REGISTRO" << endl;
    cout << "3. MOSTRAR A TODAS LAS PERSONAS DEL REGISTRO" << endl;
    cout << "4. SALIR" << endl;
    cout << endl;
    cout << "\t Ingrese una opcion: ";
}

void ListaSimple::LlenarLista(PrincipioDeLista &Lista)
{
    PrincipioDeLista aux1, aux2 = new (struct nodo);
    cout << endl;
    cin.ignore();
    cout << "\t REGISTRAR UNA PERSONA ";
    cout << endl
         << endl;
    cout << "CARNE DE LA PERSONA: ";
    cin >> aux2->carne;
    cin.ignore();
    cout << "NOMBRES: ";
    cin.getline(aux2->nombres, 20);
    cout << "APELLIDOS: ";
    cin.getline(aux2->apellidos, 20);
    cout << "EDAD: ";
    cin >> aux2->edad;
    cin.ignore();
    cout << "NUMERO DE TELEFONO: ";
    cin >> aux2->telefono;
    cin.ignore();
    cout << "CORREO ELECTRONICO: ";
    cin.getline(aux2->correo, 20);

    aux2->siguiente = NULL;

    if (Lista == NULL)
    {

        Lista = aux2;
    }
    else
    {

        aux1 = Lista;

        while (aux1->siguiente != NULL)
        {

            aux1 = aux1->siguiente;
        }

        aux1->siguiente = aux2;
    }
}

void ListaSimple::EliminarDeLista(PrincipioDeLista &Lista)
{
    int codigo;
    PrincipioDeLista aux2, aux1;
    aux2 = Lista;

    cout << endl;
    cout << "\tELIMINAR UNA PERSONA" << endl
         << endl;
    cout << "INGRESE EL CARNE DE LA PERSONA A ELIMINAR:";
    cin >> codigo;
    cout << endl;

    while (aux2 != NULL)
    {

        if (aux2->carne == codigo)
        {

            if (aux2 == Lista)
                Lista = Lista->siguiente;

            else
                aux1->siguiente = aux2->siguiente;

            delete (aux2);

            cout << "PERSONA ELIMINADA :)" << endl;

            return;
        }
        else
        {

            aux1 = aux2;
            aux2 = aux2->siguiente;
        }
    }
    if (aux2 == NULL)
        cout << "CARNE INCORRECTO :(" << endl;
}
/*En esta funcion de eliminar de la lista simple se compara si nuesta lista aun no esta vacia y si no esta vacia se 
va corriendo cada nodo con su informacion y se compara el n° de carne para poder eliminar, despues de eliminar se pasa 
al siguiente nodo con su informacion.*/

void ListaSimple::MostrarLista(PrincipioDeLista aux2)
{

    int i = 1;

    while (aux2 != NULL)
    {
        cout << endl;
        cout << "\tDATOS DE LA PERSONA " << i << " " << endl
             << endl;
        cout << "CARNE: " << aux2->carne << endl;
        ;
        cout << "NOMBRES: " << aux2->nombres << endl;
        cout << "APELLIDOS: " << aux2->apellidos << endl;
        cout << "EDAD: " << aux2->edad << endl;
        cout << "TELEFONO: " << aux2->telefono << endl;
        cout << "CORREO ELECTRONICO: " << aux2->correo << endl;
        aux2 = aux2->siguiente;

        i++;
    }
}

int main(void)
{
    PrincipioDeLista Lista = NULL;
    int opcion;
    ListaSimple objListaSimple;

    do
    {
        Menu();
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            objListaSimple.LlenarLista(Lista);
            break;
        case 2:
            if (Lista == NULL)
            {
                cout << "NO HAY PERSONA REGISTRADAS" << endl;
            }
            else
            {
                objListaSimple.EliminarDeLista(Lista);
            }
            break;
        case 3:
            if (Lista == NULL)
            {
                cout << "NO HAY PERSONA REGISTRADAS" << endl;
            }
            else
            {
                objListaSimple.MostrarLista(Lista);
            }
            break;
        case 4:
            return 0;
            break;
        default:
            cout << "INGRESE UNA OPCION VALIDA" << endl;
            break;
        }
    } while (opcion != 5);

    return 0;
}
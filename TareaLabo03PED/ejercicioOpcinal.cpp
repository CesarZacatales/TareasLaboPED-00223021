#include <iostream>

using namespace std;

struct nodo
{
    int dato;
    char tipoDePupusa[25];
    char soda[25];
    char ingredientes[25];
    nodo *sig;
    nodo *pLista;
};
typedef struct nodo *pLista;

class listaSimple
{
private:
    nodo *pInicio;

public:
    listaSimple();
    void llenarLista(pLista &lista);
    void mostrarLista(pLista uax2);
};

listaSimple::listaSimple(void)
{
    pInicio = NULL;
}

void listaSimple::llenarLista(pLista &lista)
{
    pLista aux1, aux2 = new(struct nodo);

    cout << "cuantas pupusas desean: ";
    cin >> aux2->dato;
    cin.ignore();
    cout << "Tipo de masa (maiz o arroz): ";
    cin.getline(aux2->tipoDePupusa, 25);
    cout << "Soda (coca-cola o tropical): ";
    cin.getline(aux2->soda, 25);
    cout << "Ingrediente (loroco, frijol o ayote): ";
    cin.getline(aux2->ingredientes, 25);
    
    aux2->sig = NULL;

    if(lista == NULL)
    {
      lista = aux2;
    }
    else
    {

        aux1 = lista;

        while (aux1->sig != NULL)
        {

            aux1 = aux1->sig;
        }

        aux1->sig = aux2;
    }
    
    cout << endl;
}

void listaSimple::mostrarLista(pLista aux2)
{
    while(aux2 != NULL)
    {
        cout << endl;
        cout << "Pupusas: " << aux2->dato << endl;
        cout << "Tipo de masa: " << aux2->tipoDePupusa << endl;
        cout << "soda: " << aux2->soda << endl;
        cout << "Ingrediente: " << aux2->ingredientes << endl;

        aux2 = aux2->sig;
    } 
}

int main(void)
{
    int pedidos;
    pLista lista = NULL;
    listaSimple objlistaSimple;
    cout << endl;
    cout << "\t ADMINSTRACION DE PEDIDOS DE PUPUSAS" << endl << endl;
    cout << "cuantos Pedidos haran: ";
    cin >> pedidos;

    for(int i = 0; i < pedidos; i++){
    cout << endl;
    cout << "\t Ingresa tu pedido: " << endl << endl;
    objlistaSimple.llenarLista(lista);
    }
    

    cout << "\t Pedidos actualmente: " << endl;
    objlistaSimple.mostrarLista(lista);

    cout << endl;
    return 0;
}
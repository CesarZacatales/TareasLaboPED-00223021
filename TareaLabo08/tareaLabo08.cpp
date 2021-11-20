#include <iostream>

using namespace std;

struct nodo
{
    int dato;
    nodo *hijoDer;
    nodo *hijoIzq;
};

class ABB
{
private:
    nodo *pAbb;

public:
    ABB();
    ~ABB();
    void insertar();
    void insNodoAbb(nodo **, int);
    void mostrarInOrden();
    void mostrarInOrdenAuxRec(nodo *);
    void mostrarPreorden();
    void mostrarPreOrdenAuxRec(nodo *);
    void mostrarPostOrden();
    void mostrarPostOrdenAuxRec(nodo *);
    void buscarLlave(int);
    bool buscarLlaveAux(nodo *, int);
    void eliminar(int);
    void eliminarAux(nodo **, int);
};

ABB::ABB()
{
    pAbb = NULL;
}
 
ABB::~ABB()
{
    cout << "...Programa Ejecutandose..." << endl;
}
void ABB::insertar()
{
    int dato;
    string confirmacion = {" "};
    do
    {
        cout << "Desea Ingresar una llave: ";
        cin >> confirmacion;
        if (confirmacion == "si" || confirmacion =="SI" || confirmacion =="Si")
        {
            cout << "Digite la llave: ";
            cin >> dato;
            insNodoAbb(&pAbb, dato);
        }
    } while (confirmacion == "si" || confirmacion == "SI" || confirmacion =="Si");
}

void ABB::insNodoAbb(nodo **p, int dato)
{
    if(!(*p))
    {
        (*p) = new nodo;
        (*p)->dato = dato;
        (*p)->hijoIzq = NULL;
        (*p)->hijoDer = NULL;
    }
    else 
        if(dato < (*p)->dato)
            insNodoAbb(&((*p)->hijoIzq), dato);
        else 
            if(dato > (*p)->dato)
                insNodoAbb(&((*p)->hijoDer), dato);
            else
                cout << "la llave ya se encuentra en el arbol :D" << endl;
}

void ABB::mostrarInOrden()
{
    mostrarInOrdenAuxRec(pAbb);
}

void ABB::mostrarInOrdenAuxRec(nodo *p)
{
    if (p != NULL)
    {
        mostrarInOrdenAuxRec(p->hijoIzq);
        cout << p->dato << " ";
        mostrarInOrdenAuxRec(p->hijoDer);
    }
}

void ABB::mostrarPreorden()
{
    mostrarPreOrdenAuxRec(pAbb);
}

void ABB::mostrarPreOrdenAuxRec(nodo *p)
{
    if(p != NULL)
    {
        cout << p->dato << " ";
        mostrarPreOrdenAuxRec(p->hijoIzq);
        mostrarPreOrdenAuxRec(p->hijoDer);
    }
}

void ABB::mostrarPostOrden()
{
    mostrarPostOrdenAuxRec(pAbb);
}

void ABB::mostrarPostOrdenAuxRec(nodo *p)
{
    if(p != NULL)
    {
        mostrarPostOrdenAuxRec(p->hijoIzq);
        mostrarPostOrdenAuxRec(p->hijoDer);
        cout << p->dato << " ";
    }
}

void ABB::buscarLlave(int llave)
{
    if(buscarLlaveAux(pAbb,llave))
        cout << "la llave " << llave << " fue encontrada en el arbol :D " << endl;
    else
        cout << "la llave " << llave <<" no fue encontrada en el arbol :c " << endl;
}

bool ABB::buscarLlaveAux(nodo *p, int llave)
{
    if(p == NULL)
        return false;
    else
        if(p->dato == llave)
        return true;
    else
        if(p->dato > llave)
        return buscarLlaveAux(p->hijoIzq, llave);
    else
        if(p->dato < llave)
        return buscarLlaveAux(p->hijoDer, llave);
}

void ABB::eliminar(int dato)
{
    eliminarAux(&pAbb, dato);
}

void ABB::eliminarAux(nodo **r, int dato)
{
    nodo *p;

    if (!(*r))
        cout << "la llave no esta en el arbol" << endl;
    else 
        if(dato < (*r)->dato)
        eliminarAux(&((*r)->hijoIzq), dato);
        else 
            if(dato > (*r)->dato)
                eliminarAux(&((*r)->hijoDer), dato);
            else
            {
                if(!((*r)->hijoIzq) && !((*r)->hijoDer))
                {
                    p = *r;
                    *r = NULL;
                }
                else 
                    if(!((*r)->hijoIzq) && (*r)->hijoDer)
                    {
                        p = *r;
                        *r = (*r)->hijoDer;
                    }  
                    else 
                        if((*r)->hijoIzq && !((*r)->hijoDer))
                        {
                            p = *r;
                            *r = (*r)->hijoIzq;
                        }
                        else
                            if((*r)->hijoIzq && (*r)->hijoDer)
                            {
                                p = (*r)->hijoIzq;
                                if(!p->hijoDer)
                                {
                                    (*r)->dato = p->dato;
                                    (*r)->hijoIzq = p->hijoIzq;
                                }
                                else
                                {
                                    nodo *q;
                                    while(p->hijoDer)
                                    {
                                        q = p;
                                        p = p->hijoDer;
                                    }
                                    (*r)->dato = p->dato;
                                    q->hijoDer = p->hijoIzq;
                                }
                            }
                delete p;
            }
}

int main()
{
    int llave, dato;
    cout <<"\nADMINISTRACION DE UN ARBOL BINARIO DE BUSQUEDA\n\n";

    ABB objAbb;
    
    cout << "INSERTAR LLAVES EN EL ARBOL:\n";
    cout << "para ingresar llaves escriba 'SI' || 'si' || 'Si' ^ para salir escriba 'no' " << endl;
    objAbb.insertar();

    cout << endl;
    cout << "MOSTRANDO LLAVES EN IN-ORDEN:\n";
    objAbb.mostrarInOrden();
    
    cout << endl;
    cout << "MOSTRANDO LLAVES EN PRE-ORDEN:\n";
    objAbb.mostrarPreorden();

    cout << endl;
    cout << "MOSTRANDO LLAVES EN POST-ORDEN:\n";
    objAbb.mostrarPostOrden();

    cout << endl << endl;
    cout << "BUSCAR LLAVE EN EL ARBOL:\n";
    cout << "Ingrese la llave a buscar: ";
    cin >> llave;
    objAbb.buscarLlave(llave);

    cout << endl;
    cout << "ELIMINAR UNA  LLAVE DEL ARBOL:\n";
    cout << "Ingrese la llave a eliminar: ";
    cin >> dato;
    objAbb.eliminar(dato);

    cout << endl;
    cout << "MOSTRANDO LLAVES EN IN-ORDEN:\n";
    objAbb.mostrarInOrden();

    cout << endl;
    cout << "MOSTRANDO LLAVES EN PRE-ORDEN:\n";
    objAbb.mostrarPreorden();

    cout << endl;
    cout << "MOSTRANDO LLAVES EN POST-ORDEN:\n";
    objAbb.mostrarPostOrden();

    cout << endl;
    return 0;
}
#include <iostream>
#include <stdlib.h>

using namespace std;

struct nodo
{
    int nFil, nCol;
    nodo *sigCol, *sigFil;
    int dato;
};

class hojaCalc
{
    private:
    int totFil;
    int totCol;
    nodo *pHE;

    public:
    hojaCalc(int, int);
    void insertarNodo(void);
    void imprimir(void);
    void sumarCol(int);
};

hojaCalc::hojaCalc(int totFil, int totCol)
{
    nodo *nuevo, *s;
    int i;
    
    pHE = new nodo;

    this->totFil = totFil;
    this->totCol = totCol;
    pHE->nFil = 0;
    pHE->nCol = 0;
    pHE->sigFil = pHE;
    pHE->sigCol = pHE;
    pHE->dato = 0;

    s = pHE;
    for(i = 1; i <= totCol;i++)
    {
        nuevo = new nodo;
        s->sigCol = nuevo;
        nuevo->dato = 0;
        nuevo->nCol = i;
        nuevo->nFil = 0;
        nuevo->sigFil = nuevo;
        s = s->sigCol;
    };
    nuevo->sigCol = pHE;

    s = pHE;
    for (i = 1; i <= totFil; i++)
    {
        nuevo = new nodo;
        s->sigFil = nuevo;
        nuevo->dato = 0;
        nuevo->nFil = i;
        nuevo->nCol = 0;
        nuevo->sigCol = nuevo;
        s = s->sigFil;
    };
    nuevo->sigFil = pHE;

}

void hojaCalc::insertarNodo()
{int fila, columna;

    cout << "Insercion de nodos en la hoja electronica." << endl;
    cout << "Finalice introduciendo ceros:" << endl
         << endl;
    do
    {
        cout << "Fila: ";
        cin >> fila;
        cout << "Columna: ";
        cin >> columna;
        
        if (fila >= 1 && fila <= totFil && columna >= 1 && columna <= totCol)
        {

            nodo *nuevo = new nodo;

            cout << "Entero a almacenar: ";
            cin >> nuevo->dato;
            nuevo->nFil = fila;
            nuevo->nCol = columna;

            nodo *pFil = pHE;
            nodo *pCol = pHE;
            int i;


            for (i = 1; i <= fila; i++) 
                pFil = pFil->sigFil;
            while ((pFil->sigCol->nCol < columna) && (pFil->sigCol->nCol != 0)) 
                pFil = pFil->sigCol;

            for (i = 1; i <= columna; i++) 
                pCol = pCol->sigCol;
            while ((pCol->sigFil->nFil < fila) && (pCol->sigFil->nFil != 0)) 
                pCol = pCol->sigFil;


            nuevo->sigCol = pFil->sigCol;
            pFil->sigCol = nuevo;

            nuevo->sigFil = pCol->sigFil;
            pCol->sigFil = nuevo;
            cout << "El nodo se ha insertado" << endl
                 << endl;
        }
        else
            cout << "Hubicacion no valida para nuevo dato" << endl
                 << endl;
    } while (fila != 0 || columna != 0);
}

void hojaCalc::imprimir(void)
{
   cout << "Para cada nodo se muestra: fila, columna, dato." << endl;
    cout << "La hoja electronica es:" << endl;
    nodo *s = pHE;
    int i;

    do
    {
        do
        {
            cout << s->nFil << ',' << s->nCol << ',' << s->dato << '\t';
            s = s->sigCol;
        } while (s->nCol != 0);
        cout << endl;
        s = s->sigFil;
    } while (s->nFil != 0);
}

void hojaCalc::sumarCol(int columna)
{
      nodo *s = pHE;
   do{
       if(s->nCol == columna){
           int sum = 0;
           do{
               sum += s->dato;
               s=s->sigFil;
           }while(s->nFil != 0);
           cout <<"Suma de la columna "<< columna <<" es: "<< sum << endl;
           break;
       }
       s =s->sigCol;
   }while(s->nCol != 0);
}

int main(void)
{
    nodo *s;
    int totFilas, totColumnas, fil, col, i, columna;

    cout << endl;
    cout << "FUNCIONES IMPLEMENTADAS PARA ADMINISTRAR UNA HOJA DE CALCULO" << endl
         << endl;

    cout << "Para inicializar la hoja de calculo proporcione la" << endl;
    cout << "cantidad de filas y columnas que contendra:" << endl
         << endl;
    cout << "Total de filas: ";
    cin >> totFilas;
    cout << "Total de columnas: ";
    cin >> totColumnas;

    hojaCalc hojaCalc(totFilas, totColumnas);

    hojaCalc.imprimir();

    hojaCalc.insertarNodo();

    hojaCalc.imprimir();
    cout << endl;
    cout << "ingrese el numero de columna a sumar: ";
    cin >> columna;
    hojaCalc.sumarCol(columna);

    cout << endl
         << endl;
    return 0;
}
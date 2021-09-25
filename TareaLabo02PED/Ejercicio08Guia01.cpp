/*Elabore una función que, dado un número entero que se obtiene desde teclado, realice
un conteo como el siguiente:
Suponiendo que el valor ingresado es 3:
1
2
3
2
1*/

#include <iostream>

using namespace std;

void realizarConteo(int);

int main()
{
    int numero = 0;
    cout << endl;
    cout << "INGRESE UN NUMERO ENTERO: ";
    cin >> numero;
    cout << "conteo " << endl;
    realizarConteo(numero);
}

void realizarConteo(int numero)
{
    for (int i = 1; i <= numero; i++)
    {
        cout << i << endl;
    }

    if (numero > 1)
    {
        cout << numero - 1 << endl;
        realizarConteo(numero - 2);
    }
}
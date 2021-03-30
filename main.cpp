#include <iostream>
#include <vector>
#include "listasimple.h"
#include "listadoble.h"

using namespace std;

int main()
{
    /*
    cout << "Hello World!" << endl;
    ListaSimple lista;
    lista.push_back(TipoDato("algo"));
    lista.push_back(TipoDato("algo mas"));

    auto print = [](TipoDato& dato){
        cout << pos << ": " << dato.name << std::endl;
    };
    lista.for_each(print);

    cout << lista.size() << endl;

    cout << "He llegado hasta aqui." << endl;
    */

    ListaSimple films;
    films.push_back(TipoDato{"Citizen Kane", 1941, 5});
    films.push_back(TipoDato{"Into the wild", 2007, 5});
    films.push_back(TipoDato{"Avengers", 2005, 5});
    films.push_front(TipoDato{"Yoquese", 2500, 5});
    //films.push_front(TipoDato{});
    // ... add more films

    //films.sort();

    films.for_each([](TipoDato& dato) {
        std::cout << "Nombre: " << dato.film << "   Year: " << dato.year << "    Estrellas: " << dato.number_stars << std::endl;
    });
    cout << endl;

    //films.swap(2,4);//no hace nada

    /*films.pop_back();//Funciona
    films.pop_front();//Funciona
    films.clear();*/
    //films.erase(2);
    /*films.insert(TipoDato{"blublublu", 1941, 5}, 2);
    films.for_each([](TipoDato& dato) {
        std::cout << "Nombre: " << dato.film << "   Year: " << dato.year << "    Estrellas: " << dato.number_stars << std::endl;
    });*/

    ListaDoble dobles;
    dobles.push_back(TipoDato{"Primero", 321, 3});
    dobles.push_back(TipoDato{"Segundo", 123, 8});
    dobles.push_front(TipoDato{"Tercero", 213, 5});

    dobles.for_each([](TipoDato& dato){
        std::cout << "Nombre: " << dato.film << "   Year: " << dato.year << "    Estrellas: " << dato.number_stars << std::endl;
    });

    /*
    ListaSimple films;
    films.push_back(TipoDato{"Citizen Kane", 1941, 5});
    films.push_back(TipoDato{"Into the wild", 2007, 5});
    // ... add more films

    // Store the 'positions' of those films
    std::vector<int> positions;
    films.enumerate([](int pos, TipoDato& dato) {
        if (dato.number_stars < 3) {
            positions.push_back(pos);
        }
    });

    // Now remove the films at those positions
    // ATTENTION!!! Why we need to iterate in reverse order?
    for (int i = positions.size(); i>0; i--) {
        int pos = positions.at(i-1);
        films.erase(pos);
    }

    // Print and check
    */
    return 0;
}

#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include "elementolistadoble.h"
#include <functional>

class ListaDoble
{
public:
    ListaDoble();
    ListaDoble(const TipoDato& dato);

    // Iterate
    void for_each(std::function<void (TipoDato&)> action) const;
    void enumerate(std::function<void (int, TipoDato&)> action) const;

    // Size-related methods
    int size() const;
    bool empty() const;

    // Access to data
    TipoDato& frnt() const;
    TipoDato& bck() const;
    TipoDato& at(int pos) const;

    // Insertion
    void push_back(const TipoDato& dato);
    void push_front(const TipoDato& dato);
    void insert(const TipoDato& dato, int pos);

    // Removal
    void pop_back();
    void pop_front();
    void clear();
    void erase(int pos);

    // Other methods
    void swap(int pos1, int pos2);
    int search(const TipoDato& dato) const;
    void sort();
protected:
    std::shared_ptr<ElementoListaDoble> front;
    std::shared_ptr<ElementoListaDoble> back;
};

#endif // LISTADOBLE_H

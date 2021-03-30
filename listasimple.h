#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H

#include "elementolistasimple.h"
#include <functional>

class ListaSimple
{
public:
    ListaSimple();
    ListaSimple(const TipoDato& dato);

    void for_each(std::function<void(TipoDato&)> action) const;
    void enumerate(std::function<void (int, TipoDato&)> action) const;

    int size() const;
    bool empty() const;

    void insert(const TipoDato& dato, int pos);

    TipoDato& frnt() const;
    TipoDato& bck() const;
    TipoDato& at(int pos) const;

    void push_back(const TipoDato& dato);
    void push_front(const TipoDato& dato);

    void pop_back();
    void pop_front();
    void clear();
    void erase(int pos);

    void swap(int pos1, int pos2);
    int find(const TipoDato& dato) const;

    void sort();
    bool is_sorted() const;
    //protected:
private:
    std::shared_ptr<ElementoListaSimple> front = nullptr;
    std::shared_ptr<ElementoListaSimple> back = nullptr;
};

#endif // LISTASIMPLE_H

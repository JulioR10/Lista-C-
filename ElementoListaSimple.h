#ifndef ELEMENTOLISTASIMPLE_H
#define ELEMENTOLISTASIMPLE_H

#include <memory>
#include "tipodato.h"

class ElementoListaSimple
{
public:
    TipoDato dato;
    std::shared_ptr <ElementoListaSimple> next = nullptr;
public:
    ElementoListaSimple(const TipoDato & dato);
    //TipoDato get_dato() const;
};

#endif // ELEMENTOLISTASIMPLE_H

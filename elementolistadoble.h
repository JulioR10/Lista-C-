#ifndef ELEMENTOLISTADOBLE_H
#define ELEMENTOLISTADOBLE_H

#include <memory>
#include "tipodato.h"

class ElementoListaDoble
{
public:
    TipoDato dato;
    std::shared_ptr <ElementoListaDoble> next = nullptr;
    std::shared_ptr <ElementoListaDoble> prev = nullptr;
public:
    ElementoListaDoble(const TipoDato & dato);
};

#endif // ELEMENTOLISTADOBLE_H

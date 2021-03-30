#include "listadoble.h"

ListaDoble::ListaDoble() : front{nullptr}, back{nullptr}
{

}

ListaDoble::ListaDoble(const TipoDato &dato)
{
    front = std::make_shared<ElementoListaDoble>(ElementoListaDoble{dato});
    back = front;
}

void ListaDoble::for_each(std::function<void (TipoDato &)> action) const
{
    std::shared_ptr<ElementoListaDoble> iterator = front;
    while(iterator != nullptr){
        action(iterator->dato);//Call the action
        iterator = iterator->next;
    }
}

void ListaDoble::enumerate(std::function<void (int, TipoDato &)> action) const
{
    std::shared_ptr<ElementoListaDoble> iterator = front;
    int id = 0;
    while(iterator->next != nullptr){
        action(id, iterator->dato);//Call the action
        iterator = iterator->next;
        id++;
    }
}

int ListaDoble::size() const
{
    auto iterator = front;
    int num{0};
    while(iterator != nullptr){
        iterator = iterator->next;
        num++;
    }
    return num;
}

bool ListaDoble::empty() const
{
    return this->size() == 0;
}

TipoDato &ListaDoble::frnt() const
{
    return front->dato;
}

TipoDato &ListaDoble::bck() const
{
    return back->dato;
}

TipoDato &ListaDoble::at(int pos) const
{
    std::shared_ptr<ElementoListaDoble> iterator = front;
    int p{0};
    while(iterator != nullptr){
        if(p == pos){
            return iterator->dato;
        }
        iterator = iterator->next;
        p++;
    }
}

void ListaDoble::push_back(const TipoDato &dato)
{
    std::shared_ptr<ElementoListaDoble> elem = std::make_shared<ElementoListaDoble>(ElementoListaDoble{dato});
    if(front == nullptr){
        front = elem;
        back = elem;
    }else{
        back->next = elem;
        back = elem;
    }
}

void ListaDoble::push_front(const TipoDato &dato)
{
    std::shared_ptr<ElementoListaDoble> elem = std::make_shared<ElementoListaDoble>(ElementoListaDoble{dato});
    if(front == nullptr){
        front = elem;
        back = elem;
    }else{
        elem->next = front;
        front = elem;
    }
}

void ListaDoble::insert(const TipoDato &dato, int pos)
{
    if (pos == 0) { // This is a particular scenario
        this->push_front(dato);
        return;
    }

    // Create the element we are going to insert
    auto elem = std::make_shared<ElementoListaDoble>(ElementoListaDoble{dato});

    // Search for the position where we are going to insert
    auto iterator = front;
    int idx = 0;
    while (idx != pos) {
        iterator = iterator->next;
        idx++;
    }

    // Now assign the pointers properly
    elem->next = iterator;
    elem->prev = iterator->prev;
    elem->next->prev = elem;
    elem->prev->next = elem;
}

void ListaDoble::pop_back()
{
    if (front != back) {
        // Take the element before the latest one
        auto prevprev = back->prev;
        // The next element now is 'nullptr'
        prevprev->next = nullptr;

        // Update the value of 'back'
        back = prevprev;
    } else { // If there is only one element in the list
        this->clear(); // Just clear the list
    }
}

void ListaDoble::pop_front()
{
    front = front->next;
    front->prev = nullptr;
    if(front == nullptr){
        back = nullptr;
    }
}

void ListaDoble::clear()
{

}

void ListaDoble::erase(int pos)
{

}

void ListaDoble::swap(int pos1, int pos2)
{

}

int ListaDoble::search(const TipoDato &dato) const
{

}

void ListaDoble::sort()
{

}

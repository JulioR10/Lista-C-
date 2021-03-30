#include "listasimple.h"

ListaSimple::ListaSimple() : front{nullptr}, back{nullptr}
{

}

ListaSimple::ListaSimple(const TipoDato & dato)
{
    front = std::make_shared<ElementoListaSimple>(ElementoListaSimple{dato});
    back = front;
    // both are pointing to the same element
}

void ListaSimple::push_back(const TipoDato &dato)
{
    std::shared_ptr<ElementoListaSimple> elem = std::make_shared<ElementoListaSimple>(ElementoListaSimple{dato});
    if(front == nullptr){
        front = elem;
        back = elem;
    }else{
        back->next = elem;
        back = elem;
    }
}

void ListaSimple::push_front(const TipoDato &dato)
{
    std::shared_ptr<ElementoListaSimple> elem = std::make_shared<ElementoListaSimple>(ElementoListaSimple{dato});
    if(front == nullptr){
        front = elem;
        back = elem;
    }else{
        elem->next = front;
        front = elem;
    }
}

void ListaSimple::pop_back()
{
    std::shared_ptr<ElementoListaSimple> iterator = front;
    while(iterator != nullptr){
        if(iterator->next == back){
            back = iterator;
            iterator->next = nullptr;
        }
        iterator = iterator->next;
    }
}

void ListaSimple::pop_front()
{
    front = front->next;
    if(front == nullptr){
        back = nullptr;
    }
}

void ListaSimple::clear()
{
    while(back != front){
        front = front->next;
    }
    front = back = nullptr;
}

void ListaSimple::erase(int pos)
{
    std::shared_ptr<ElementoListaSimple> iterator = front;
    std::shared_ptr<ElementoListaSimple> iterator2 = front->next;
    int er{1};
    while(iterator != nullptr){
        if(er == pos){
            iterator->next = iterator2;
        }
        iterator = iterator->next;
        iterator2 = iterator2->next;
        er++;
    }
}

void ListaSimple::swap(int pos1, int pos2)
{
    std::shared_ptr<ElementoListaSimple> iterator1 = front;
    std::shared_ptr<ElementoListaSimple> i1 = front;
    std::shared_ptr<ElementoListaSimple> iterator2 = front;
    std::shared_ptr<ElementoListaSimple> i2 = front;
    std::shared_ptr<ElementoListaSimple> aux = front;
    int er1{0};
    int er2{0};
    while(iterator1 != nullptr){
        if(er1 == pos1){
            i1 = iterator1;
        }
        iterator1 = iterator1->next;
        er1++;
    }
    while(iterator2 != nullptr){
        if(er2 == pos2){
            i2 = iterator2;
        }
        iterator2 = iterator2->next;
        er2++;
    }
    aux = i1;
    i1 = i2;
    i2 = aux;
}

int ListaSimple::find(const TipoDato &dato) const
{
    std::shared_ptr<ElementoListaSimple> iterator = front;
    int pos{1};
    while(iterator != nullptr){
        if(iterator->dato.film == dato.film){
            return pos;
        }
        iterator = iterator->next;
        pos++;
    }
    return 0;
}
//no se que hacen)
void ListaSimple::sort()
{

}

bool ListaSimple::is_sorted() const
{

}

void ListaSimple::for_each(std::function<void (TipoDato&)> action) const
{
    std::shared_ptr<ElementoListaSimple> iterator = front;
    while(iterator != nullptr){
        action(iterator->dato);//Call the action
        iterator = iterator->next;
    }
}

void ListaSimple::enumerate(std::function<void (int, TipoDato &)> action) const
{
    //Iterate the list as usual
    std::shared_ptr<ElementoListaSimple> iterator = front;
    int id = 0;
    while(iterator->next != nullptr){
        action(id, iterator->dato);//Call the action
        iterator = iterator->next;
        id++;
    }
}

int ListaSimple::size() const
{
    auto iterator = front;
    int num{0};
    while(iterator != nullptr){
        iterator = iterator->next;
        num++;
    }
    return num;
}

bool ListaSimple::empty() const
{
    return this->size() == 0;
}

void ListaSimple::insert(const TipoDato &dato, int pos)
{
    std::shared_ptr<ElementoListaSimple> iterator = front;
    std::shared_ptr<ElementoListaSimple> elem = std::make_shared<ElementoListaSimple>(ElementoListaSimple{dato});
    auto marca = front->next;
    int p {1};
    while(iterator->next != nullptr){
        if(pos == p){
            marca = iterator->next;
            iterator->next = elem;
            iterator = iterator->next;
            elem->next = marca;
        }
        iterator = iterator->next;
        p++;
    }
}

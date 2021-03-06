#include "IteratorLP.h"
#include "Lista.h"
#include <exception>

IteratorLP::IteratorLP(const Lista& l):lista(l) {
	/* de adaugat */
    current = lista.first;
}

void IteratorLP::prim(){
	/* de adaugat */
    current = lista.first;
}

void IteratorLP::urmator(){
	/* de adaugat */
    if(!valid())
        throw std::exception();
    current = lista.list.next[current];
}

bool IteratorLP::valid() const{
	/* de adaugat */
    if(current == -1 || current == lista.first_free)
	    return false;
    return true;
}

TElem IteratorLP::element() const{
	/* de adaugat */
    if(!valid())
        throw std::exception();
    return lista.list.value[current];
}

void IteratorLP::anterior() {
    if(!valid())
        throw std::exception();


    if(current == lista.first){
        current = -1;
        return;
    }

    auto temp = lista.first;

    while(lista.list.next[temp] != current)
        temp = lista.list.next[temp];

    current = temp;

}



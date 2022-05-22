#include "IteratorColectie.h"
#include "Colectie.h"


IteratorColectie::IteratorColectie(const Colectie& c): col(c) {
	/* de adaugat */
    prim();
}

void IteratorColectie::prim() {
	/* de adaugat */
    poz = -1;
    urmator();
}


void IteratorColectie::urmator() {
	/* de adaugat */
    if(poz == col.hash){
        throw std::exception();
    }
    ++poz;
    while(col.list.element[poz] == sad && poz < col.hash){
        ++poz;
    }
}


bool IteratorColectie::valid() const {
    return poz != col.hash;
}



TElem IteratorColectie::element() const {
    if(poz == col.hash){
        throw std::exception();
    }
	return col.list.element[poz];
}

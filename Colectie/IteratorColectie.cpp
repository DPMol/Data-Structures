#include "IteratorColectie.h"
#include "Colectie.h"


IteratorColectie::IteratorColectie(const Colectie& c): col(c) {
	/* de adaugat */
    curent = -1;
    deplasare();
}

void IteratorColectie::deplasare() {
    curent++;
    while (curent < col.cp && col.e[curent] == NULL_TELEM) {
        curent++;
    }
}

void IteratorColectie::prim() {
    curent = -1;
    deplasare();
}


void IteratorColectie::urmator() {
    deplasare();
}


bool IteratorColectie::valid() const {
	/* de adaugat */
    return curent < col.cp;
}



TElem IteratorColectie::element() const {
    return col.e[curent];
}

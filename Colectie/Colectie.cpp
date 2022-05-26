#include "Colectie.h"
#include "IteratorColectie.h"
#include <exception>
#include <iostream>

using namespace std;

#define NMAX 900000

//Complexitate: O(cp)
void Colectie::act_primLiber() {
    primLiber++;
    while (primLiber < cp && e[primLiber] != NULL_TELEM) {
        primLiber++;
    }
}

//Complexitate: 0(1)
TElem Colectie::hashCode(TElem e) const {
    return abs(e);
}

//Complexitate: 0(1)
TElem Colectie::d(TElem e) const {
    return hashCode(e) % cp;
}

Colectie::Colectie(int cap) {
    cp = cap;
    n = 0;
    e = new TElem[cap];
    urm = new int[cap];
    for (int i = 0; i < cap; i++) {
        e[i] = NULL_TELEM;
        urm[i] = -1;
    }
    primLiber = 0;
}

//Complexitate: 0(NMAX)
Colectie::Colectie() {
    cp = NMAX;
    n = 0;
    e = new TElem[NMAX];
    urm = new int[NMAX];
    for (int i = 0; i < NMAX; i++) {
        e[i] = NULL_TELEM;
        urm[i] = -1;
    }
    primLiber = 0;
}

//Complexitate: 0(cp)
void Colectie::redim() {
    Colectie m2(cp*2);
    int i;
    for (i = 0; i < cp; i++) {
        if (e[i] != NULL_TELEM) {
            m2.adauga(e[i]);
        }
    }

    delete[] e, urm;

    cp = cp * 2;
    e = m2.e;
    urm = m2.urm;
    e = new TElem[cp];
    urm = new int[cp];
    for (i = 0; i < cp; i++) {
        auto v = m2.urm[i];
        e[i] = m2.e[i];
        urm[i] = v;
    }
    primLiber = -1;

    act_primLiber();
}

void Colectie::adauga(TElem elem) {
    if (primLiber >= cp) {
        redim();
    }
    int i = d(elem), j;
    if (e[i] == NULL_TELEM) {
        e[i] = elem;
        if (primLiber == i) {
            act_primLiber();
        }
    }
    else {
        while (i != -1) {
            j = i;
            i = urm[i];
        }
        urm[j] = primLiber;
        e[primLiber] = elem;
        act_primLiber();
    }
    n++;
}


bool Colectie::sterge(TElem elem) {
	/* de adaugat */
    int i, j, prec_j, prec_i=-1;
    for (i = d(elem); i != -1; prec_i = i, i = urm[i]) {
        if (e[i] == elem) {
            break;
        }
    }
    if (i == -1) {
        return false;
    }
    while (1) {
        for (j = urm[i], prec_j = i; j != -1 && d(e[j]) != i; prec_j = j, j = urm[j]);
        if (j != -1) {
            e[i] = e[j];
            i = j;
            prec_i = prec_j;
            continue;
        }
        if (prec_i != -1) {
            urm[prec_i] = urm[i];
        }
        e[i] = NULL_TELEM;
        urm[i] = -1;
        n--;
        return true;
    }
}


bool Colectie::cauta(TElem elem) const {
    int i;
    for (i = 0; i < cp; i++) {
        if (e[i] == elem) {
            return true;
        }
    }
    return false;
}

int Colectie::nrAparitii(TElem elem) const {
    int c = 0;
    auto poz = d(elem);
    while(poz != -1){
        if(e[poz] == elem)
            c++;
        poz = urm[poz];
    }
    return c;
}


int Colectie::dim() const {
	/* de adaugat */
    return n;
}


bool Colectie::vida() const {
	/* de adaugat */
    return n == 0;
}

IteratorColectie Colectie::iterator() const {
	return  IteratorColectie(*this);
}


Colectie::~Colectie() {
    delete[] e, urm;
}

int Colectie::del_all() {
    int con = 0;
    auto c = iterator();

    while(c.valid()){
        auto n = nrAparitii(c.element());
        if( n > 1){
            while(n>0){
                con++;
                sterge(c.element());
                n--;
            }
        }
        c.urmator();
    }
    return con;
}


/*
Pre: c-colectie
Post: c-colectie, fara elementele ce apart de mai multe ori; con, numarul de elemente sterse
Subalgoritm del_all(c^io, con):
    con <- 0;
	it <- iterator(c)
    cat timp(valid(it))
        n <- nrApartitii(c,element(it))
        daca(n>1)
            cat timp(n >0)
                con++
                sterge(c, element(it));
                n--
            sf cat timp
        sf daca
        urmator(it)
    sf cat timp
    del_all <- con
sf subalgortim


*/

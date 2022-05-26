#include "Colectie.h"
#include "IteratorColectie.h"
#include <exception>
#include <iostream>

using namespace std;

void Colectie::alloc(int new_hash){
	auto* old_next = list.next;
    auto* old_element =  list.element;
    list.next = new int[new_hash];
    list.element = new TElem[new_hash];
    size = 0;
    for(int i = 0; i <new_hash; i++){
        list.next[i] = sad;
        list.element[i] = sad;
    }
    first_free = 0;

	for(int i = 0;i < hash;i++){
		if(old_element[i] != sad){
            adauga(old_element[i]);
        }
	}

	hash = new_hash;
	delete[] old_next;
	delete[] old_element;
}

Colectie::Colectie() {
	/* de adaugat */
	hash = 500000;
    size = 0;
    list.next = new int[hash];
    list.element = new TElem[hash];
    for (int i = 0; i < hash; i++) {
        list.next[i] = sad;
        list.element[i] = sad;
    }
    first_free = 0;

}


void Colectie::adauga(TElem elem) {
	/* de adaugat */

	auto poz = get_hash(elem);
    if(size == hash){
        this->alloc(hash*2);
    }
    if(list.element[poz] == sad){
        list.element[poz] = elem;
        if(poz == first_free){
            update_first_free();
        }
    }else{
        while(list.next[poz] != sad){
            poz = list.next[poz];
        }
        list.next[poz] = first_free;
        list.element[first_free] = elem;
        update_first_free();
    }
    size++;
}


bool Colectie::sterge(TElem elem) {
    int i, j, prec_j, prec_i=sad;
    for (i = get_hash(elem); i != sad; prec_i = i, i = list.next[i]) {
        if (list.element[i] == elem) {
            break;
        }
    }
    if (i == sad) {
        return false;
    }
    while (1) {
        for (j = list.next[i], prec_j = i; j != sad && get_hash(list.element[j]) != i; prec_j = j, j = list.next[j]);
        if (j != sad) {
            list.element[i] = list.element[j];
            i = j;
            prec_i = prec_j;
            continue;
        }
        if (prec_i != sad) {
            list.next[prec_i] = list.next[i];
        }
        list.element[i] = sad;
        list.next[i] = sad;
        size--;
        return true;
    }
}


bool Colectie::cauta(TElem elem) const {
	/* de adaugat */
    auto poz = get_hash(elem);
    while(poz != sad){
        if(list.element[poz] == elem){
            return true;
        }
        poz = list.next[poz];
    }
	return false;
}

int Colectie::nrAparitii(TElem elem) const {
    int c = 0;
    auto poz = get_hash(elem);
    while(poz != sad){
        if(list.element[poz] == elem)
            c++;
        poz = list.next[poz];
    }
	return c;
}


int Colectie::dim() const {
	/* de adaugat */
	return size;
}


bool Colectie::vida() const {
	/* de adaugat */
	return size == 0;
}

IteratorColectie Colectie::iterator() const {
	return  IteratorColectie(*this);
}


Colectie::~Colectie() {
	/* de adaugat */
    delete[] list.next;
    delete[] list.element;
}

void Colectie::update_first_free() {
    first_free = 0;
    while(first_free<hash && list.element[first_free] != sad){
        first_free++;
    }
}

int Colectie::get_hash(const TElem e) const{
    return abs(e%hash);
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



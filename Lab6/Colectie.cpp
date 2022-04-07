#include "Colectie.h"
#include "IteratorColectie.h"
#include <exception>
#include <iostream>

using namespace std;

void Colectie::alloc(int new_hash){
	auto* new_next = new int[new_hash];
	auto* new_element = new struct nod[new_hash];
	for(int i = 0;i < hash;i++){
		new_next[i] = list.next[i];
		new_element[i].value = list.element[i].value;
		new_element[i].key = list.element[i].key;
	}
	first_free = hash;
	for(int i = hash; i <new_hash-1; i++)
		new_next[i] = i + 1;
	new_next[new_hash-1] = -1;
	hash = new_hash;
	delete[] list.next;
	delete[] list.element;
	list.next = new_next;
	list.element = new_element;
}

Colectie::Colectie() {
	/* de adaugat */
	hash = 0;
	size = 0;
	first_free = 0;
	list.next = nullptr;
	list.element = nullptr;
	alloc(50);
}


void Colectie::adauga(TElem elem) {
	/* de adaugat */
	auto poz = elem % hash;

	if(list.element[poz].key == -1)
}


bool Colectie::sterge(TElem elem) {
	/* de adaugat */
	return false;
}


bool Colectie::cauta(TElem elem) const {
	/* de adaugat */
	return false;
}

int Colectie::nrAparitii(TElem elem) const {
	/* de adaugat */
	return 0;
}


int Colectie::dim() const {
	/* de adaugat */
	return 0;
}


bool Colectie::vida() const {
	/* de adaugat */
	return true;
}

IteratorColectie Colectie::iterator() const {
	return  IteratorColectie(*this);
}


Colectie::~Colectie() {
	/* de adaugat */
}



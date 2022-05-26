#pragma once

#include "MDO.h"


class IteratorMDO{
	friend class MDO;
private:

	//constructorul primeste o referinta catre Container
	//iteratorul va referi primul element din container
	explicit IteratorMDO(const MDO& dictionar);

	//contine o referinta catre containerul pe care il itereaza
	const MDO& dict;

    int poz, el;
	/* aici e reprezentarea  specifica a iteratorului */


public:

		//reseteaza pozitia iteratorului la inceputul containerului
		void prim();//O(h)

		//muta iteratorul in container
		// arunca exceptie daca iteratorul nu e valid
		void urmator();//O(h^2)

		//verifica daca iteratorul e valid (indica un element al containerului)
		bool valid() const;//O(1)

		//returneaza valoarea elementului din container referit de iterator
		//arunca exceptie daca iteratorul nu e valid
		TElem element() const;//O(1)
};


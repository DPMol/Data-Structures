#pragma once

#include "DO.h"

class Iterator{
	friend class DO;
private:
	//constructorul primeste o referinta catre Container
	//iteratorul va referi primul element din container
	explicit Iterator(const DO& dictionar);

	//contine o referinta catre containerul pe care il itereaza
	const DO& dict;
	/* aici e reprezentarea specifica a iteratorului */

    struct DO::node *current;


public:

		//reseteaza pozitia iteratorului la inceputul containerului
        //O(1)
		void prim();

		//muta iteratorul in container
		// arunca exceptie daca iteratorul nu e valid
        //O(1)
		void urmator();

		//verifica daca iteratorul e valid (indica un element al containerului)
        //O(1)
		bool valid() const;

		//returneaza valoarea elementului din container referit de iterator
		//arunca exceptie daca iteratorul nu e valid
        //O(1)
		TElem element() const;
};


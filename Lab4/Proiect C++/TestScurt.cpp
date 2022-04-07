#include "TestScurt.h"

#include <assert.h>
#include <exception>

#include <iostream>
#include "Lista.h"
#include "IteratorLP.h"



using namespace std;

void testAll(){
	Lista lista = Lista();

	assert(lista.dim() == 0);
	assert(lista.vida());

    lista.adaugaSfarsit(1);

    assert(lista.dim() == 1);
    assert(!lista.vida());

    IteratorLP itp = lista.prim();

    itp.anterior();
    assert(!itp.valid());
    try{
        itp.anterior();
        assert(false);
    }
    catch(exception&){
        assert(true);
    }
    IteratorLP it = lista.cauta(1);

    assert(it.valid());
    assert(it.element() == 1);
    it.urmator();
    assert(!it.valid());
    it.prim();
    assert(it.valid());
    assert(it.element() == 1);

    assert(lista.sterge(it) == 1);

    assert(lista.dim() == 0);
    assert(lista.vida());

    lista.adaugaInceput(1);
    assert(lista.dim() == 1);
    assert(!lista.vida());

}


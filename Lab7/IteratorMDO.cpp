#include "IteratorMDO.h"
#include "MDO.h"

IteratorMDO::IteratorMDO(const MDO& d) : dict(d){
	prim();
}

void IteratorMDO::prim(){
	/* de adaugat */

    poz = dict.min(dict.rad);
    el = 0;
}

void IteratorMDO::urmator(){
    if(!valid())
        throw exception();
	/* de adaugat */
    el++;
    if(el >= dict.list[poz].el->v.size()){
        poz = dict.succesor(poz);
        el = 0;
    }
}

bool IteratorMDO::valid() const{
	/* de adaugat */
	return poz != -1;
}

TElem IteratorMDO::element() const{
	/* de adaugat */
    if(!valid())
        throw exception();
	return pair <TCheie, TValoare>  (dict.list[poz].el->c, dict.list[poz].el->v[el]);
}



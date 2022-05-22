#include "IteratorMDO.h"
#include "MDO.h"
#include <iostream>
#include <vector>

#include <exception>
using namespace std;

MDO::MDO(Relatie r):rel(r) {
	/* de adaugat */
    rad = -1;
    size = 0;
    capacity = 50;
    list = new node_list[50];
    first_free = 0;
}

void MDO::alloc(int new_cap){
    auto new_list = new node_list[new_cap];

    for(int i = 0 ; i < capacity ; i++){
        new_list[i] = list[i];
        list[i].el = nullptr;
    }

    first_free = capacity;
    capacity = new_cap;
    delete[] list;
    list = new_list;
}

int MDO::find(int nod, TCheie key) const {


    if(list[nod].el->c == key)
        return nod;

    if(rel(key, list[nod].el->c)){
        if(list[nod].stanga == -1)
            return nod;
        return find(list[nod].stanga, key);
    }
    else {
        if (list[nod].dreapta == -1)
            return nod;
        return find(list[nod].dreapta, key);
    }

}

void MDO::adauga(TCheie c, TValoare v) {
	/* de adaugat */
    size++;
    if(rad == -1){
        rad = first_free;
        list[first_free].el = new node(c, v);
        update_free();
        return;
    }

    auto poz = find(rad, c);


    if(list[poz].el->c == c){
        list[poz].el->v.push_back(v);
        return;
    }

    if(first_free == capacity)
        alloc(2 * capacity);

    list[first_free].el = new node(c, v);

    if(rel(c, list[poz].el->c))
        list[poz].stanga = first_free;
    else
        list[poz].dreapta = first_free;

    update_free();
}

vector<TValoare> MDO::cauta(TCheie c) const {
	/* de adaugat */
    if(rad == -1){
        return {};
    }

    auto poz = find(rad, c);


    if(list[poz].el->c == c)
        return list[poz].el->v;

	return {};
}

bool MDO::sterge(TCheie c, TValoare v){
    if(rad == -1){
        return false;
    }
    auto nod = find(rad, c);
    if(list[nod].el->c != c)
        return false;

    auto poz = std::find(list[nod].el->v.begin(), list[nod].el->v.end(), v);
    if(poz == list[nod].el->v.end())
        return false;
    size--;

    list[nod].el->v.erase(poz);

    if(!list[nod].el->v.empty())
        return true;

    //cout<<nod<<" "<<list[nod].stanga<<" "<<list[nod].dreapta<<endl;

    if(list[nod].stanga == -1 && list[nod].dreapta == -1){
        delete list[nod].el;
        if(nod == rad)
            rad = -1;
        return true;
    }
    if(list[nod].stanga != -1 && list[nod].dreapta != -1){
        auto last = nod;
        auto temp = list[nod].dreapta;
        while(list[temp].stanga != -1){
            last = temp;
            temp = list[temp].stanga;
        }
        delete list[nod].el;
        if(last == nod){
            list[nod].el = list[temp].el;
            list[nod].dreapta = list[temp].dreapta;
        }
        else{
            list[nod].el = list[temp].el;
            list[last].stanga = list[temp].stanga;
        }
        list[temp].el = nullptr;
        list[temp].stanga = -1;
        list[temp].dreapta = -1;
        return true;
    }
    else{
        auto last = nod;
        int temp;
        if(list[nod].stanga == -1){
            temp = list[nod].dreapta;
        }
        else{
            temp = list[nod].stanga;
        }
        while(list[temp].stanga != -1){
            last = temp;
            temp = list[temp].stanga;
        }
        delete list[nod].el;

        if(last == nod){
            list[nod].el = list[temp].el;
            list[nod].dreapta = list[temp].dreapta;
        }
        else{
            list[nod].el = list[temp].el;
            list[last].stanga = list[temp].stanga;
        }
        list[temp].stanga = -1;
        list[temp].dreapta = -1;
        list[temp].el = nullptr;
    }
    return true;
}

//bool MDO::sterge(TCheie c, TValoare v) {
//    if(rad == -1)
//        return false;
//    return del(rad, c, v);
//}

int MDO::dim() const {
	/* de adaugat */
	return size;
}

bool MDO::vid() const {
	/* de adaugat */
	return size == 0;
}

IteratorMDO MDO::iterator() const {
	return IteratorMDO(*this);
}

MDO::~MDO() {
	/* de adaugat */
    delete[] list;
}

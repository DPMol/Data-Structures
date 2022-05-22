#pragma once

#include <vector>
#include <iostream>
#include <algorithm>

typedef int TCheie;
typedef int TValoare;

#include <utility>
typedef std::pair<TCheie, TValoare> TElem;

using namespace std;

class IteratorMDO;

typedef bool(*Relatie)(TCheie, TCheie);

class MDO {
	friend class IteratorMDO;
    private:

    Relatie rel;
    typedef struct node{
        TCheie c;
        vector<TValoare> v;

        node(TCheie c, TValoare v) : c(c){this->v.push_back(v);};
    } node;

    typedef struct node_list{
      int stanga{-1}, dreapta{-1};
      node* el{nullptr};

      ~node_list(){
          //delete el;
      }
    } node_list;

    int capacity, size;
    node_list* list;
    int rad;
    int first_free;

    void alloc(int);

    int find(int, TCheie) const;

    int parinte(int nod) const{
        if(nod == rad){
            return -1;
        }
        auto poz = rad;
        auto c = list[nod].el->c;
        //cout<<poz<<endl;
        while(list[poz].dreapta != nod && list[poz].stanga != nod){
//            cout<<poz<<" "<<list[poz].stanga<<" "<<list[poz].dreapta<<endl;
//            cout<<c<<" "<<list[poz].el->c<<endl;
            if(rel(c, list[poz].el->c)) {
                poz = list[poz].stanga;
            }
            else
                poz = list[poz].dreapta;
        }

        return poz;
    }

    int succesor(int nod) const{
        if(list[nod].dreapta != -1){
            return min(list[nod].dreapta);
        }
        auto p = parinte(nod);

        while(p != -1 && nod == list[p].dreapta){
            //cout<<"galati"<<endl;
            nod = p;
            p = parinte(nod);
        }
        return p;
    }

    int min(int p) const {
        if(p == -1)
            return -1;
        while(list[p].stanga != -1)
            p = list[p].stanga;
        return p;
    }

    bool del(int, TCheie, TValoare);

    void update_free(){
        first_free = 0;
        while(first_free < capacity && list[first_free].el != nullptr)
            first_free++;
    }

    public:

	// constructorul implicit al MultiDictionarului Ordonat
	MDO(Relatie r);

	// adauga o pereche (cheie, valoare) in MDO
	void adauga(TCheie c, TValoare v);

	//cauta o cheie si returneaza vectorul de valori asociate
	vector<TValoare> cauta(TCheie c) const;

	//sterge o cheie si o valoare 
	//returneaza adevarat daca s-a gasit cheia si valoarea de sters
	bool sterge(TCheie c, TValoare v);

	//returneaza numarul de perechi (cheie, valoare) din MDO 
	int dim() const;

	//verifica daca MultiDictionarul Ordonat e vid 
	bool vid() const;

	// se returneaza iterator pe MDO
	// iteratorul va returna perechile in ordine in raport cu relatia de ordine
	IteratorMDO iterator() const;

	// destructorul 	
	~MDO();

};

#pragma once

#define NULL_TELEM 7483647
typedef int TElem;

class IteratorColectie;

class Colectie
{
	friend class IteratorColectie;

private:
    int cp;
    int n;
    TElem* e;
    int* urm;
    int primLiber;

    void act_primLiber();//O(cp)
    TElem hashCode(TElem e) const;//O(1)
    TElem d(TElem e) const;//O(1)
    void redim();//O(cp)
public:
		//constructorul implicit
		Colectie();//O(NMAX)
        Colectie(int);//O(cp)

		//adauga un element in colectie
		void adauga(TElem e);//O(1)

        int del_all();//O(n)

		//sterge o aparitie a unui element din colectie
		//returneaza adevarat daca s-a putut sterge
		bool sterge(TElem e);//O(1)

		//verifica daca un element se afla in colectie
		bool cauta(TElem elem) const;//O(1)

		//returneaza numar de aparitii ale unui element in colectie
		int nrAparitii(TElem elem) const;//O(1)


		//intoarce numarul de elemente din colectie;
		int dim() const;//O(1)

		//verifica daca colectia e vida;
		bool vida() const;//O(1)

		//returneaza un iterator pe colectie
		IteratorColectie iterator() const;

		// destructorul colectiei
		~Colectie();

};


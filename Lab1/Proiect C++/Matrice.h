#pragma once

typedef int TElem;


#define NULL_TELEMENT 0

class Matrice {

private:
	/* aici e reprezentarea */

    // numar de linii si coloane
	int n,m;

	//vector linii
	int *row;

	//vector coloane
	int *column;

	//vector valori
	int *value;

    //lungimea listelor de valori si linii
    int len;

    void valid_poz(int i, int j) const;

    int check_poz(int i, int j) const;

public:

	//constructor
	//se arunca exceptie daca nrLinii<=0 sau nrColoane<=0
	Matrice(int nrLinii, int nrColoane);//Complexitate O(m);


	//destructor
	~Matrice(){};//O(1)

	//returnare element de pe o linie si o coloana
	//se arunca exceptie daca (i,j) nu e pozitie valida in Matrice
	//indicii se considera incepand de la 0
	TElem element(int i, int j) const;//O(n)



	// returnare numar linii
	int nrLinii() const;//O(1)

	// returnare numar coloane
	int nrColoane() const;//O(1)


	// modificare element de pe o linie si o coloana si returnarea vechii valori
	// se arunca exceptie daca (i,j) nu e o pozitie valida in Matrice
	TElem modifica(int i, int j, TElem);//O(n)

};








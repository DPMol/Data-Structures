#include "Matrice.h"
#include <iostream>
#include <exception>

using namespace std;

Matrice::Matrice(int m, int n) {
	/* de adaugat */

	//numar linii + coloane
	this->n = m;
	this->m = n;

	//vector linii
    row = new int[0];
    column = new int[m+1];
    value = new TElem [0];

    //vector coloane
	for(int i=0;i<=n;i++)
		column[i] = 0;

	//vector valori
    len = 0;
}

int Matrice::check_poz(int i, int j) const{
    for(int k = column[j]; k < column[j+1]; k++)
        if(row[k] == i)
            return k;
    return -1;
}

void Matrice::valid_poz(int i, int j) const{
    if(i < 0 || i >= n)
        throw exception();
    if(j < 0 || j >= m)
        throw exception();
}

int Matrice::nrLinii() const{
	/* de adaugat */
	return n;
}


int Matrice::nrColoane() const{
	/* de adaugat */
	return m;
}


TElem Matrice::element(int i, int j) const{
	/* de adaugat */
    int poz;
	//varificare validitate i,j
    valid_poz(i, j);
    poz = check_poz(i, j);

	if(poz != -1)
        return value[poz];
	//altfel returnam elementul null
	return NULL_TELEMENT;
}



TElem Matrice::modifica(int i, int j, TElem e) {
	/* de adaugat */

	//varificare validitate i,j
    valid_poz(i,j);
    int poz, ret;
    if(e != NULL_TELEMENT){
        poz = check_poz(i,j);
        if(poz != -1){
            ret = value[poz];
            value[poz] = e;
            return ret;
        }
        else{
            for(auto k = j+1; k<=m; k++)
                *(column+k) = *(column+k) + 1;

            len++;
            int *newrow = new int[len] , *newvalue = new TElem[len];

            for(poz = 0;poz < column[j];poz++){
                newrow[poz] = row[poz];
                newvalue[poz] = value[poz];
            }

            newrow[poz] = i;
            newvalue[poz] = e;

            for(poz++;poz<len;poz++){
                newrow[poz] = row[poz-1];
                newvalue[poz] = value[poz-1];
            }

            delete[] row;
            delete[] value;

            row = newrow;
            value = newvalue;

            return NULL_TELEMENT;
        }
    }
    else{
        poz = check_poz(i,j);
        if(poz >= 0){
            ret = value[poz];
            for(auto k = j+1; k<=m; k++)
                *(column+k) = *(column+k) - 1;

            len--;
            int *newrow = new int[len] , *newvalue = new TElem[len],k;

            for(k=0;k<poz;k++){
                newrow[k] = row[k];
                newvalue[k] = value[k];
            }

            for(k = poz ;k < len;k++){
                newrow[k] = row[k+1];
                newvalue[k] = value[k+1];
            }

            delete[] row;
            delete[] value;

            row = newrow;
            value = newvalue;

            return ret;
        }
        else
            return NULL_TELEMENT;
    }
}



#ifndef MATRICE_H
#define MATRICE_H
#include <string>
#include "MatCreuse.h"
#include "MatPleine.h"

class Matrice
{
	bool plein;
	int nb_val;
	int nb_l;
	int nb_c;
	MatPleine* matPleine;
	MatCreuse* matCreuse;
public:
	Matrice();
	Matrice(int, int);
	~Matrice();

	void Convertir();
	void Afficher();
	void NM(int,int);
    Matrice& operator=(Matrice&);
    Matrice& operator+(Matrice&);
    Matrice& operator-(Matrice&);
    Matrice& operator*(Matrice&);
	Matrice& operator+(double &x);
	Matrice& operator-(double& x);
	Matrice& operator*(double& x);
	Matrice& operator/(double& x);
	void Charger(std::string);

};
#endif

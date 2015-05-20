#ifndef ___MATPLEINE_H___
#define ___MATPLEINE_H___
#include "MatCreuse.h"
#include <string>
#include <fstream>

class MatCreuse;

class MatPleine
{
	int nb_l;
	int nb_c;
	double ** tableau;
	friend class Matrice;
	friend class MatCreuse;

public:
	MatPleine(int,int);
	~MatPleine();
	void Destruction();
	int Remplissage();
	void Afficher();
	
	MatPleine& operator=(MatPleine&);
    MatPleine& operator=(MatCreuse&);
    
    friend MatPleine& operator+(MatPleine&,MatPleine&);
    friend MatPleine& operator-(MatPleine&,MatPleine&);
    friend MatPleine& operator*(MatPleine&,MatPleine&);

    friend MatPleine& operator+(MatPleine&,const int&);
    friend MatPleine& operator-(MatPleine&,const int&);
    friend MatPleine& operator*(MatPleine&,const int&);
    friend MatPleine& operator/(MatPleine&, const int&);


    void Sauvegarde();
    void Charger(std::fstream&,int,int);
    int Total_Cases();
    MatPleine& Generateur_Aleat();
    MatPleine& Transpose();

};






#endif

/**
* \file Matrice.h
* \author GELOCRRG
* \version 1.0
* \date 28 mai 2015
* \brief Gestionnaire de matrices
*/


#ifndef MATRICE_H
#define MATRICE_H
#include <string>
#include "MatCreuse.h"
#include "MatPleine.h"

/** \class Matrice
   * \brief Classe gèrant la matrice
   *
   *  La classe gère les matrices en fonction de si elles sont pleines ou creuses
   */

class Matrice
{
	bool plein;
	int nb_val;
	int nb_l;
	int nb_c;
	MatPleine* matPleine;
	MatCreuse* matCreuse;
public:

	/**
     	*  \brief Constructeur
     	*
     	*  Constructeur de la classe Matrice.
     	*/
	Matrice();
	
	/**
     	*  \brief Constructeur
     	*
     	*  Constructeur de la classe Matrice avec dimensions en arguments.
     	*/
	Matrice(int, int);
	
	/**
     	*  \brief Destructeur
     	*
     	*  Destructeur de la classe Matrice.
     	*/
	~Matrice();

	/**
     	*  \brief Conversion
     	*
     	*  Consvertit une matrice pleine en matrice creuse et inversement.
     	*/
	void Convertir();
	
	/**
     	*  \brief Affichage de la matrice
     	*
     	*  Affiche la matrice pleine ou creuse.
     	*/
	void Afficher();
	
	/**
     	*  \brief Crée une nouvelle matrice
     	*
     	*  .
     	*/
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

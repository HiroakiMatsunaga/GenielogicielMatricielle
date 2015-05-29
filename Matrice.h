//!
//! \file Matrice.h
//! \author GELOCRRG
//! \version 1.0
//! \date 28 mai 2015
//! \brief Gestionnaire de matrices
//!


#ifndef MATRICE_H
#define MATRICE_H
#include <string>
#include "MatCreuse.h"
#include "MatPleine.h"

//! \class Matrice
   //! \brief Classe gèrant la matrice
   //!
   //!  La classe gère les matrices en fonction de si elles sont pleines ou creuses
   //!

class Matrice
{
	bool plein;
	int nb_val;
	int nb_l;
	int nb_c;
	MatPleine* matPleine;
	MatCreuse* matCreuse;
public:

	//!
     	//!  \brief Constructeur
     	//!
     	//!  Constructeur de la classe Matrice.
     	//!
	Matrice();
	
	//!
     	//!  \brief Constructeur
     	//!
     	//!  Constructeur de la classe Matrice avec dimensions en arguments.
     	//!
	Matrice(int, int);
	
	//!
     	//!  \brief Destructeur
     	//!
     	//!  Destructeur de la classe Matrice.
     	//!
	~Matrice();

	//!
     	//!  \brief Conversion
     	//!
     	//!  Consvertit une matrice pleine en matrice creuse et inversement.
     	//!
	void Convertir();
	
	//!
     	//!  \brief Affichage de la matrice
     	//!
     	//!  Affiche la matrice pleine ou creuse.
     	//!
	void Afficher();
	
	//!
     	//!  \brief Crée une nouvelle matrice
     	//!
     	//!  .Crée une matrice creuse et pleine.
     	//!
	void NM(int,int);
	
	//!
     	//!  \brief Opérateur = entre deux matrices
     	//!
     	//!  Etablit l'égalité entre deux matrices.
     	//!
    Matrice& operator=(Matrice&);
    
    //!
     //!  \brief Opérateur + entre deux matrices
     //!
     //!  Effectue la somme entre deux matrices.
     //!
    Matrice& operator+(Matrice&);
    
    //!
     //!  \brief Opérateur - entre deux matrices
     //!
     //!  Effectue la différence entre deux matrices.
     //!
    Matrice& operator-(Matrice&);
    
    //!
     //!  \brief Opérateur * entre deux matrices
     //!
     //!  Effectue le produit entre deux matrices.
     //!
    Matrice& operator*(Matrice&);
    
    //!
     //!  \brief Opérateur + entre une matrice et un entier
     //!
    //!  Effectue la somme entre une matrice et un entier.
     //!
	Matrice& operator+(double &x);
	
	//!
     	//!  \brief Opérateur - entre une matrice et un entier
     	//!
     	//!  Effectue la différence entre une matrice et un entier.
     	//!
	Matrice& operator-(double& x);
	
	//!
     	//!  \brief Opérateur * entre une matrice et un entier
     	//!
     	//!  Effectue le produit entre une matrice et un entier.
     	//!
	Matrice& operator*(double& x);
	
	//!
     	//!  \brief Opérateur / entre une matrice et un entier
	//!
     	//!  Effectue le quotient entre une matrice et un entier.
     	//!
	Matrice& operator/(double& x);
	
	//!
     	//!  \brief Transposé d'une matrice
	//!
     	//!  Effectue la transposé d'une matrice.
     	//!
	Matrice& Transpose();
	
	//!
     	//!  \brief Charger un fichier
     	//!
     	//!  Chargement du fichier dont le nom est passé en argument.
     	//!
	void Charger(std::string);

};
#endif

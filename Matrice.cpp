/**
* \file Matrice.cpp
* \author GELOCRRG
* \version 1.0
* \date 28 mai 2015
* \brief Gère l'aiguillage de la matrice vers matpleine ou matcreuse.
* \details Cette classe appelle, en fonction de la matrice utilisée, la classe matpleine ou matcreuse
* 	   pour effectuer les manipulations demandées sur cette matrice.
*/

#include <iostream>
#include <fstream>
#include "Matrice.h"
#include "MatCreuse.h"
#include "MatPleine.h"
using namespace std;

/**
* \brief Initialise la matrice.
* \details Mise à 0 des paramètres.
* \param nb_l Taille de la matrice.
* \param nb_c Taille de la matrice.
* \param nb_val Le nombre de valeur non nulle.
*/

Matrice::Matrice()
{
    nb_l=0;
    nb_c=0;
    nb_val=0;
}

/**
* \brief Fixe la taille de la matrice et la remplit.
* \details Passage en argument de la dimension de la matrice et appelle de la fonction matpleine pour la remplir.
* \param nbl Taille de la matrice.
* \param nbc Taille de la matrice.
* \param plein Booléen indiquant si la matrice est pleine ou creuse.
* \param matPleine issu de la classe MatPleine.
*/

Matrice::Matrice(int nbl, int nbc)
{
	if (nbl>0 && nbc>0)
	{
	    nb_l=nbl;
	    nb_c=nbc;
		//Générer une matrice pleine
        plein=true;
		matPleine=new MatPleine(nbl,nbc);
		//Remplir cette Matrice en comptant le nombre de valeurs
		nb_val=matPleine->Remplissage();
		//Convertir si besoin
		if((nb_val/(nbl*nbc)<=0.3))
			Convertir();
	}

	else
	{
		cerr<<"Construction impossible"<<endl;
	}

}

/**
* \brief Crée la matrice dans les deux autres classes.
* \details La matrice est créée dans les deux autres classes pour être manipulé ensuite.
* \param matCreuse issu de la classe MatCreuse.
*/

void Matrice::NM(int nbl, int nbc)
{
    if (nbl>0 && nbc>0)
    {
        nb_l=nbl;
        nb_c=nbc;
    }

    nb_val=0;
    matPleine=new MatPleine(nb_l,nb_c);
    matCreuse=new MatCreuse(nb_l, nb_c);
}

/**
* \brief Destructeur de la Matrice.
* \details Détruit la matrice pleine ou creuse selon si elle est pleine ou creuse.
*/

Matrice::~Matrice()
{
	if(plein)
        matPleine->Destruction();
	else
		matCreuse->Destruction();
}

/**
* \brief Convertit la matrice de pleine à creuse ou de creuse à pleine.
* \details Si la matrice est pleine, la convertit en matrice creuse et détruit la matrice pleine et inversement.
*/

void Matrice::Convertir()
{
	if(plein)
	{
		matCreuse=new MatCreuse(matPleine->nb_l, matPleine->nb_c);
		*matCreuse=*matPleine;
		matPleine->Destruction();
		plein=false;
	}

	else
	{
		matPleine=new MatPleine(matCreuse->nb_l, matCreuse->nb_c);
		*matPleine=*matCreuse;
		matCreuse->Destruction();
		plein=true;
	}
}

/**
* \brief Appelle la fonction Afficher de MatPleine ou MatCreuse.
* \details Si la fonction est pleine, appelle la fonction Afficher de MatPleine et inversement.
*/

void Matrice::Afficher()
{
    if(plein)
    {
        matPleine->Afficher();
    }
    else
    {
        matCreuse->Afficher();
    }
}

/**
* \brief Appelle l'opérateur nécessaire pour effectuer l'égalité.
* \details Appelle l'opérateur = correspondant à deux matrices pleines, deux matrices creuses,
* \	   une pleine et une creuse ou une creuse et une pleine.
*/

Matrice& Matrice::operator=(Matrice& A)
{

    if(plein && A.plein)
    {
        *matPleine=*(A.matPleine);
    }

    else if(plein)
    {
        *matPleine=*(A.matCreuse);
        Convertir();
    }

    else if(A.plein)
    {
        *matCreuse=*(A.matPleine);
        Convertir();
    }

    else
    {
        *matCreuse=*(A.matCreuse);
    }
    plein=A.plein;
    return* this;
}

/**
* \brief Appelle l'opérateur nécessaire pour effectuer la somme de deux matrices.
* \details Appelle l'opérateur + correspondant à deux matrices pleines, deux matrices creuses,
* \	   une pleine et une creuse ou une creuse et une pleine puis la stocke dans une matrice temporaire
* \	   qui est retourné à la fin.
* \param M_temp Matrice temporaire.
* \return La matrice temporaire contenant le résultat de l'opération est retournée.
*/

Matrice& Matrice::operator+(Matrice& A)
{
    Matrice* M_temp=new Matrice;
    M_temp->NM(A.nb_l, A.nb_c);
    if(plein && A.plein)
    {
        M_temp->plein=true;
        *(M_temp->matPleine)=*matPleine+*(A.matPleine);
        nb_val=M_temp->matPleine->Total_Cases();
        
    }
    else if(plein)
    {
        M_temp->plein=true;
        A.Convertir();
        *(M_temp->matPleine)=*matPleine+*(A.matPleine);
    }
    else if(A.plein) 
    {
        M_temp->plein=A.plein;
        A.Convertir();
        *(M_temp->matCreuse)=*matCreuse+*(A.matCreuse);
    }
    else
    {
        M_temp->plein=false;
        *(M_temp->matCreuse)=*matCreuse+*(A.matCreuse);
    }
    return *M_temp;
}

/**
* \brief Appelle l'opérateur nécessaire pour effectuer la différence entre deux matrices.
* \details Appelle l'opérateur - correspondant à deux matrices pleines, deux matrices creuses,
* \	   une pleine et une creuse ou une creuse et une pleine puis la stocke dans une matrice temporaire
* \	   qui est retourné à la fin.
* \param M_temp Matrice temporaire.
* \return La matrice temporaire contenant le résultat de l'opération est retournée.
*/

Matrice& Matrice::operator-(Matrice& A)
{
    Matrice* M_temp=new Matrice;
    M_temp->NM(A.nb_l, A.nb_c);
    if(plein && A.plein)
    {
        M_temp->plein=true;
        *(M_temp->matPleine)=*matPleine-*(A.matPleine);
    }
    else if(plein)
    {
        M_temp->plein=true;
        A.Convertir();
        *(M_temp->matPleine)=*matPleine-*(A.matPleine);
    }
    else if(A.plein)
    {
        M_temp->plein=A.plein;
        A.Convertir();
        *(M_temp->matCreuse)=*matCreuse-*(A.matCreuse);
    }
    else
    {
        M_temp->plein=false;
        *(M_temp->matCreuse)=*matCreuse-*(A.matCreuse);
    }
    return* M_temp;
}

/**
* \brief Appelle l'opérateur nécessaire pour effectuer le produit de deux matrices.
* \details Appelle l'opérateur * correspondant à deux matrices pleines, deux matrices creuses,
* \	   une pleine et une creuse ou une creuse et une pleine puis la stocke dans une matrice temporaire
* \	   qui est retourné à la fin.
* \param M_temp Matrice temporaire.
* \return La matrice temporaire contenant le résultat de l'opération est retournée.
*/

Matrice& Matrice::operator*(Matrice& A)
{
    Matrice* M_temp=new Matrice;
    M_temp->NM(A.nb_l, A.nb_c);
    if(plein && A.plein)
    {
        M_temp->plein=true;
        *(M_temp->matPleine)=*matPleine**(A.matPleine);
    }
    else if(plein)
    {
        M_temp->plein=true;
        A.Convertir();
        *(M_temp->matPleine)=*matPleine**(A.matPleine);
    }
    else if(A.plein)
    {
        M_temp->plein=A.plein;
        A.Convertir();
        *(M_temp->matCreuse)=*matCreuse**(A.matCreuse);
    }
    else
    {
        M_temp->plein=false;
        *(M_temp->matCreuse)=*matCreuse**(A.matCreuse);
    }
    return* M_temp;
}

/**
* \brief Appelle l'opérateur nécessaire pour effectuer la somme entre une matrice et un entier.
* \details Appelle l'opérateur + correspondant à matrice pleine ou creuse puis la stocke dans une matrice temporaire
* \	   qui est retourné à la fin.
* \param M_temp Matrice temporaire.
* \param x L'entier utilisé dans l'opération.
* \return La matrice temporaire contenant le résultat de l'opération est retournée.
*/

Matrice& Matrice::operator+(double& x)
{
    Matrice* M_temp=new Matrice;
    M_temp->NM(nb_l, nb_c);
    if(plein)
    {
        M_temp->plein=true;
        *(M_temp->matPleine)=*matPleine+x;
    }
    else
    {
        M_temp->plein=false;
        *(M_temp->matCreuse)=*matCreuse+x;
    }
    return* M_temp;
}

/**
* \brief Appelle l'opérateur nécessaire pour effectuer la différence entre une matrice et un entier.
* \details Appelle l'opérateur - correspondant à matrice pleine ou creuse puis la stocke dans une matrice temporaire
* \	   qui est retourné à la fin.
* \param M_temp Matrice temporaire.
* \param x L'entier utilisé dans l'opération.
* \return La matrice temporaire contenant le résultat de l'opération est retournée.
*/

Matrice& Matrice::operator-(double& x)
{
    Matrice* M_temp=new Matrice;
    M_temp->NM(nb_l, nb_c);
    if(plein)
    {
        M_temp->plein=true;
        *(M_temp->matPleine)=*matPleine-x;
    }
    else
    {
        M_temp->plein=false;
        *(M_temp->matCreuse)=*matCreuse-x;
    }
    return* M_temp;
}

/**
* \brief Appelle l'opérateur nécessaire pour effectuer le produit entre une matrice et un entier.
* \details Appelle l'opérateur * correspondant à matrice pleine ou creuse puis la stocke dans une matrice temporaire
* \	   qui est retourné à la fin.
* \param M_temp Matrice temporaire.
* \param x L'entier utilisé dans l'opération.
* \return La matrice temporaire contenant le résultat de l'opération est retournée.
*/

Matrice& Matrice::operator*(double& x)
{
    Matrice* M_temp=new Matrice;
    M_temp->NM(nb_l, nb_c);
    if(plein)
    {
        M_temp->plein=true;
        *(M_temp->matPleine)=*matPleine*x;
    }
    else
    {
        M_temp->plein=false;
        *(M_temp->matCreuse)=*matCreuse*x;
    }
    return* M_temp;
}

/**
* \brief Appelle l'opérateur nécessaire pour effectuer le quotient entre une matrice et un entier.
* \details Appelle l'opérateur / correspondant à matrice pleine ou creuse puis la stocke dans une matrice temporaire
* \	   qui est retourné à la fin.
* \param M_temp Matrice temporaire.
* \param x L'entier utilisé dans l'opération.
* \return La matrice temporaire contenant le résultat de l'opération est retournée.
*/

Matrice& Matrice::operator/(double& x)
{
    Matrice* M_temp=new Matrice;
    M_temp->NM(nb_l, nb_c);
    if(plein)
    {
        M_temp->plein=true;
        *(M_temp->matPleine)=*matPleine/x;
    }
    else
    {
        M_temp->plein=false;
        *(M_temp->matCreuse)=*matCreuse/x;
    }
    return* M_temp;
}

/**
* \brief Appelle la fonction nécessaire pour obtenir la transposé d'une matrice.
* \details Appelle la fonction Transpose correspondante à matrice pleine ou creuse puis la stocke dans une matrice temporaire
* \	   qui est retourné à la fin.
* \param M_temp Matrice temporaire.
* \return La matrice temporaire contenant le résultat de l'opération est retournée.
*/

Matrice& Matrice::Transpose()
{
	Matrice* M_temp=new Matrice;
	if(plein)
	{
		M_temp->matPleine.Transpose();
	}
	else
	{
		M_temp->matCreuse.Transpose();
	}
	return M_temp;
}

/**
* \brief Appelle la fonction Charger correspondante.
* \details Si la matrice est pleine, la fonction Charger de matrice pleine est appelée
* \	   sinon c'est celle de la matrice creuse qui est appelée.
* \param nom string contenant le nom du fichier
* \param chemin string contenant le chemin à suivre pour trouver le fichier
* \param fichier Le fichier à charger.
*/

void Matrice::Charger(string nom)
{
    string chemin="sauvegardes"+nom;
    fstream fichier;
    fichier.open(chemin.c_str(), ios::in);

    int nb_lignes, nb_colonnes;

    fichier>>nb_lignes>>nb_colonnes>>nb_val;
    if(nb_val/(nb_lignes*nb_colonnes)>0.3)
    {
        matPleine->Charger(fichier, nb_l, nb_c);
    }
    else
    {
        matCreuse->Charger(fichier, nb_l, nb_c);
    }
}

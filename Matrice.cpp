#include <iostream>
#include <fstream>
#include "Matrice.h"
#include "MatCreuse.h"
#include "MatPleine.h"
using namespace std;

Matrice::Matrice()
{
    nb_l=0;
    nb_c=0;
    nb_val=0;
}

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

Matrice::~Matrice()
{
	if(plein)
        matPleine->Destruction();
	else
		matCreuse->Destruction();
}

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

Matrice& Matrice::operator=(Matrice& A)
{

    if(plein && A.plein)
    {
        *matPleine=*(A.matPleine);
    }

    else if(plein)
    {
        *matPleine=*(A.matCreuse);
    }

    else if(A.plein)
    {
        *matCreuse=*(A.matPleine);
    }

    else
    {
        *matCreuse=*(A.matCreuse);
    }
    plein=A.plein;
    return* this;
}

Matrice& Matrice::operator+(Matrice& A)
{

    /*
    Manque opérateur matpleine vers matcreuse et matcreuse vers matpleine

    */
    Matrice* M_temp=new Matrice;
    M_temp->NM(A.nb_l, A.nb_c);
    if(plein && A.plein)
    {
        M_temp->plein=true;
        *(M_temp->matPleine)=*matPleine+*(A.matPleine);
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

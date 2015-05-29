/**
* \file MatPleine.cpp
* \author GELOCRRG
* \version 1.0
* \date 28 mai 2015
* \brief Gère les matrices pleines.
* \details Cette classe crée, remplit et effectue les opérations possibles sur les matrices pleines
*/

#include <iostream>
#include <stdlib.h> 
#include <string>
#include <time.h>
#include <fstream>
#include <limits>
#include "MatPleine.h"
#include "MatCreuse.h"
using namespace std;

/**
* \brief Crée la matrice pleine.
* \details Passage en paramètre de la dimension de la matrice et création d'un tableau.
* \param nbl Taille de la matrice.
* \param nbc Taille de la matrice.
* \param tableau La matrice.
*/

MatPleine::MatPleine(int nbl, int nbc)
{
	nb_l = nbl;
	nb_c = nbc;

	tableau = new double*[nb_l];
	for(int i=0; i<nb_l; i++)
		tableau[i]=new double[nb_c];
}

/**
* \brief Destructeur matrice pleine.
* \details Appelle la fonction qui détruit la matrice pleine.
*/

MatPleine::~MatPleine()
{
	Destruction();
}

/**
* \brief Détruit la matrice pleine.
* \details Détruit le tableau ligne par ligne.
*/

void MatPleine::Destruction()
{
	for(int i=0; i<nb_l; i++)
		delete[] tableau[i];
}

/**
* \brief Remplit la matrice pleine.
* \details Entrée des valeurs contenues dans la matrice par l'utilisateur.
* \param nb_val Compteur du nombre de valeurs non nulles entrées dans la matrice.
* \return Le nombre de valeurs non nulles de la matrice.
*/

int MatPleine::Remplissage()
{
        int nb_val=0;
        cout<<"Donner les valeurs contenues dans la matrice dans l'ordre:"<<endl;
        for (int i=0;i<nb_l;i++)
    {
                for (int j=0;j<nb_c;j++)
        {
            cin>>tableau[i][j];
            while(!cin.good())
            {
                cerr << "Merci d'entrer un nombre valide"<<endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin>>tableau[i][j];
            }
                        if(tableau[i][j]!=0)
                        {
                                nb_val+=1;
                        }
                }
                cout<<endl;
        }
        return nb_val;
}

/**
* \brief Affiche la matrice pleine.
* \details Affiche la matrice proprement.
*/

void MatPleine::Afficher()
{
        for(int i=0; i<nb_l; i++)
    {
                for(int j=0; j<nb_c; j++)
                {
                        cout<<tableau[i][j]<<"|";
                }
                cout<<endl;
        }
}



//_________________OPERATEURS____________________

/**
* \brief Opérateur = entre deux matrices pleines.
* \details Copie une matrice pleine dans une autre.
* \param m La matrice que l'on copie.
* \return La copie de la matrice passée en argument.
*/

MatPleine& MatPleine::operator=(MatPleine& m)
{
	nb_l = m.nb_l;
	nb_c = m.nb_c;

	tableau = new double*[nb_l];
	for(int i=0; i<nb_l; i++)
		tableau[i]=new double[nb_c];

	for(int i=0; i<nb_l; i++)
	{
		for(int j=0; j<nb_c; j++)
		{
			tableau[i][j] = m.tableau[i][j];
		}
	}
	return *this;
}

/**
* \brief Operateur + entre deux matrices pleines.
* \details Effectue la somme de deux matrices pleines de même taille.
* \param MP1 Première matrice de la somme.
* \param MP2 Deuxième matrice de la somme.
* \param M_temp Matrice temporaire contenant la somme des deux matrices.
* \return Le Résultat de la somme contenu dans une matrice temporaire.
*/

MatPleine& operator + (MatPleine& MP1, MatPleine& MP2)
{
	MatPleine* M_temp = new MatPleine(MP1.nb_l, MP2.nb_c);
	
	if((MP1.nb_l != MP2.nb_l) || (MP1.nb_c != MP2.nb_c))
	{
		cerr<<"Somme impossible, problème de taille."<<endl;
		M_temp->nb_l = 0;
		M_temp->nb_c = 0;
		M_temp->tableau = NULL;
	}

	else
	{
		M_temp->nb_l = MP1.nb_l;
		M_temp->nb_c = MP1.nb_c;

		for (int i=0; i<MP1.nb_l; i++)
		{
			for(int j=0; j<MP1.nb_c; j++)
				M_temp->tableau[i][j] = MP1.tableau[i][j] + MP2.tableau[i][j];
		}
	}
	
	return *M_temp;
}

/**
* \brief Operateur - entre deux matrices pleines.
* \details Effectue la différence de deux matrices pleines de même taille.
* \param MP1 Première matrice de la différence.
* \param MP2 Deuxième matrice de la différence.
* \param M_temp Matrice temporaire contenant la différence des deux matrices.
* \return Le Résultat de la différence contenu dans une matrice temporaire.
*/

MatPleine& operator - (MatPleine& MP1, MatPleine& MP2)
{
	MatPleine* M_temp = new MatPleine(MP1.nb_l, MP2.nb_c);
	
	if((MP1.nb_l != MP2.nb_l) || (MP1.nb_c != MP2.nb_c))
	{
		cerr<<"Somme impossible, problème de taille."<<endl;
		M_temp->nb_l = 0;
		M_temp->nb_c = 0;
		M_temp->tableau = NULL;
	}

	else
	{
		M_temp->nb_l = MP1.nb_l;
		M_temp->nb_c = MP1.nb_c;

		for (int i=0; i<MP1.nb_l; i++)
		{
			for(int j=0; j<MP1.nb_c; j++)
				M_temp->tableau[i][j] = MP1.tableau[i][j] - MP2.tableau[i][j];
		}
	}
	
	return *M_temp;
}

/**
* \brief Operateur * entre deux matrices pleines.
* \details Effectue le produit de deux matrices pleines de même taille.
* \param MP1 Première matrice du produit.
* \param MP2 Deuxième matrice du produit.
* \param M_temp Matrice temporaire contenant le produit des deux matrices.
* \return Le Résultat du produit contenu dans une matrice temporaire.
*/

MatPleine& operator * (MatPleine& MP1, MatPleine& MP2)
{
	MatPleine* M_temp = new MatPleine(MP1.nb_l, MP2.nb_c);
	
	if(MP1.nb_c != MP2.nb_l)
	{
		cerr<<"Produit impossible, problème de taille."<<endl;
		M_temp->nb_l = 0;
		M_temp->nb_c = 0;
		M_temp->tableau = NULL;
	}

	else
	{
		for(int i=0; i<MP1.nb_l; i++)
		{
			for(int j=0; j<MP2.nb_c; j++)
			{
				M_temp->tableau[i][j]=0;
				
				for(int k=0; k<MP1.nb_c; k++)
				{
					M_temp->tableau[i][j] += MP1.tableau[i][k] * MP2.tableau[k][j];
				}
			}
		}

		M_temp->nb_l = MP1.nb_l;
		M_temp->nb_c = MP2.nb_c;
	}
	
	return *M_temp;
}

/**
* \brief Operateur + entre une matrice pleine et un entier.
* \details Effectue la somme d'une matrice pleine et d'un entier.
* \param MP1 Matrice de la somme.
* \param x Entier de la somme.
* \param M_temp Matrice temporaire contenant la somme.
* \return Le Résultat de la somme contenu dans une matrice temporaire.
*/

MatPleine& operator + (MatPleine& MP1, double& x)
{
	MatPleine* M_temp = new MatPleine(MP1.nb_l, MP1.nb_c);

	M_temp->nb_l = MP1.nb_l;
	M_temp->nb_c = MP1.nb_c;

	for (int i=0; i<MP1.nb_l; i++)
	{
		for(int j=0; j<MP1.nb_c; j++)
			M_temp->tableau[i][j] = MP1.tableau[i][j] + x;
	}
	
	return *M_temp;
}

/**
* \brief Operateur - entre une matrice pleine et un entier.
* \details Effectue la différence d'une matrice pleine et d'un entier.
* \param MP1 Matrice de la différence.
* \param x Entier de la différence.
* \param M_temp Matrice temporaire contenant la différence.
* \return Le Résultat de la différence contenu dans une matrice temporaire.
*/

MatPleine& operator - (MatPleine& MP1, double& x)
{
	MatPleine* M_temp = new MatPleine(MP1.nb_l, MP1.nb_c);

	M_temp->nb_l = MP1.nb_l;
	M_temp->nb_c = MP1.nb_c;

	for (int i=0; i<MP1.nb_l; i++)
	{
		for(int j=0; j<MP1.nb_c; j++)
			M_temp->tableau[i][j] = MP1.tableau[i][j] - x;
	}
	
	return *M_temp;
}

/**
* \brief Operateur * entre une matrice pleine et un entier.
* \details Effectue le produit d'une matrice pleine et d'un entier.
* \param MP1 Matrice du produit.
* \param x Entier du produit.
* \param M_temp Matrice temporaire contenant le produit.
* \return Le Résultat du produit contenu dans une matrice temporaire.
*/

MatPleine& operator * (MatPleine& MP1, double& x)
{
	MatPleine* M_temp = new MatPleine(MP1.nb_l, MP1.nb_c);

	M_temp->nb_l = MP1.nb_l;
	M_temp->nb_c = MP1.nb_c;

	for (int i=0; i<MP1.nb_l; i++)
	{
		for(int j=0; j<MP1.nb_c; j++)
			M_temp->tableau[i][j] = MP1.tableau[i][j] * x;
	}
	
	return *M_temp;
}

/**
* \brief Operateur / entre une matrice pleine et un entier.
* \details Effectue le quotient d'une matrice pleine et d'un entier.
* \param MP1 Matrice du quotient.
* \param x Entier du quotient.
* \param M_temp Matrice temporaire contenant le quotient.
* \return Le Résultat du quotient contenu dans une matrice temporaire.
*/

MatPleine& operator / (MatPleine& MP1, double& x)
{
	MatPleine* M_temp = new MatPleine(MP1.nb_l, MP1.nb_c);

	M_temp->nb_l = MP1.nb_l;
	M_temp->nb_c = MP1.nb_c;

	for (int i=0; i<MP1.nb_l; i++)
	{
		for(int j=0; j<MP1.nb_c; j++)
			M_temp->tableau[i][j] = MP1.tableau[i][j] / x;
	}
	
	return *M_temp;
}

/**
* \brief Operateur = entre une matrice pleine et une matrice creuse.
* \details Copie d'une matrice creuse dans une matrice pleine.
* \param MC Matrice creuse.
* \return La matrice pleine remplacé par le contenu de la matrice creuse.
*/

MatPleine& MatPleine::operator=(MatCreuse& MC)
{
	nb_l = MC.nb_l;
	nb_c = MC.nb_c;

	tableau = new double*[nb_l];
	for(int i=0; i<nb_l; i++)
		tableau[i]=new double[nb_c];

	for(int i=0; i<nb_l; i++)
	{
		for(int j=0; j<nb_c; j++)
		{
			tableau[i][j] = MC.Valeur(i,j);
		}
	}
	return *this;
}

/**
* \brief Operateur + entre un entier et une matrice pleine.
* \details Somme une matrice pleine et un entier.
* \param MC Matrice pleine.
* \return Le résultat de la somme.
*/

MatPleine& operator+(double& x, MatPleine& MC)
{
	return MC+x;
}

/**
* \brief Operateur - entre un entier et une matrice pleine.
* \details Différence entre un matrice pleine et un entier.
* \param MC Matrice pleine.
* \return Le résultat de la différence.
*/

MatPleine& operator-(double& x, MatPleine& MC)
{
	return MC-x;
}

/**
* \brief Operateur * entre un entier et une matrice pleine.
* \details Produit entre un matrice pleine et un entier.
* \param MC Matrice pleine.
* \return Le résultat du produit.
*/

MatPleine& operator*(double& x, MatPleine& MC)
{
	return MC*x;
}

// addition

/**
* \brief Operateur + entre une matrice pleine et une matrice creuse.
* \details Effectue la somme d'une matrice pleine et d'une matrice creuse.
* \param MP Matrice pleine.
* \param MC Matrice creuse
* \return Une matrice temporaire contenant la somme des deux matrices.
*/

MatPleine& operator + (MatPleine& MP, MatCreuse& MC)
{
	MatPleine* M_temp = new MatPleine(MP.nb_l, MC.nb_c);
	
	if((MP.nb_l != MC.nb_l) || (MP.nb_c != MC.nb_c))
	{
		cerr<<"Somme impossible, problème de taille."<<endl;
		M_temp->nb_l = 0;
		M_temp->nb_c = 0;
		M_temp->tableau = NULL;
	}

	else
	{
		M_temp->nb_l = MP.nb_l;
		M_temp->nb_c = MP.nb_c;

		for (int i=0; i<MP.nb_l; i++)
		{
			for(int j=0; j<MP.nb_c; j++)
				M_temp->tableau[i][j] = MP.tableau[i][j] + MC.Valeur(i,j);
		}
	}
	return *M_temp;
}

/**
* \brief Operateur + entre une matrice creuse et une matrice pleine.
* \details Renvoie la somme d'une matrice pleine et d'une matrice creuse.
* \param MP Matrice pleine.
* \param MC Matrice creuse
* \return La somme d'une matrice pleine et d'une matrice creuse.
*/

MatPleine& operator + (MatCreuse& MC, MatPleine& MP)
{
	return MP+MC;
}



// soustraction

/**
* \brief Operateur - entre une matrice pleine et une matrice creuse.
* \details Effectue la différence entre une matrice pleine et une matrice creuse.
* \param MP Matrice pleine.
* \param MC Matrice creuse
* \return Une matrice temporaire contenant la différence entre les deux matrices.
*/

MatPleine& operator - (MatPleine& MP, MatCreuse& MC)
{
	MatPleine* M_temp = new MatPleine(MP.nb_l, MC.nb_c);
	
	if((MP.nb_l != MC.nb_l) || (MP.nb_c != MC.nb_c))
	{
		cerr<<"Somme impossible, problème de taille."<<endl;
		M_temp->nb_l = 0;
		M_temp->nb_c = 0;
		M_temp->tableau = NULL;
	}

	else
	{
		M_temp->nb_l = MP.nb_l;
		M_temp->nb_c = MP.nb_c;

		for (int i=0; i<MP.nb_l; i++)
		{
			for(int j=0; j<MP.nb_c; j++)
				M_temp->tableau[i][j] = MP.tableau[i][j] - MC.Valeur(i,j);
		}
	}
	return *M_temp;
}

/**
* \brief Operateur - entre une matrice creuse et une matrice pleine.
* \details Effectue la différence entre une matrice creuse et d'une matrice pleine.
* \param MP Matrice pleine.
* \param MC Matrice creuse
* \return Une matrice temporaire contenant la différence entre les deux matrices.
*/

MatPleine& operator - (MatCreuse& MC, MatPleine& MP)
{
	MatPleine* M_temp = new MatPleine(MP.nb_l, MC.nb_c);
	
	if((MP.nb_l != MC.nb_l) || (MP.nb_c != MC.nb_c))
	{
		cerr<<"Somme impossible, problème de taille."<<endl;
		M_temp->nb_l = 0;
		M_temp->nb_c = 0;
		M_temp->tableau = NULL;
	}

	else
	{
		M_temp->nb_l = MP.nb_l;
		M_temp->nb_c = MP.nb_c;

		for (int i=0; i<MP.nb_l; i++)
		{
			for(int j=0; j<MP.nb_c; j++)
				M_temp->tableau[i][j] = MC.Valeur(i,j) - MP.tableau[i][j];
		}
	}
	return *M_temp;
}



// multiplication

/**
* \brief Operateur * entre une matrice pleine et une matrice creuse.
* \details Effectue le produit d'une matrice pleine et d'une matrice creuse.
* \param MP Matrice pleine.
* \param MC Matrice creuse
* \return Une matrice temporaire contenant le produit des deux matrices.
*/

MatPleine& operator * (MatPleine& MP, MatCreuse& MC)
{
	MatPleine* M_temp = new MatPleine(MP.nb_l, MC.nb_c);
	
	if(MP.nb_c != MC.nb_l)
	{
		cerr<<"Produit impossible, problème de taille."<<endl;
		M_temp->nb_l = 0;
		M_temp->nb_c = 0;
		M_temp->tableau = NULL;
	}

	else
	{
		for(int i=0; i<MP.nb_l; i++)
		{
			for(int j=0; j<MC.nb_c; j++)
			{
				M_temp->tableau[i][j]=0;
				
				for(int k=0; k<MP.nb_c; k++)
				{
					M_temp->tableau[i][j] += MP.tableau[i][k] * MC.Valeur(k,j);
				}
			}
		}

		M_temp->nb_l = MP.nb_l;
		M_temp->nb_c = MC.nb_c;
	}
	
	return *M_temp;
}

/**
* \brief Operateur * entre une matrice creuse et une matrice pleine.
* \details Effectue le produit d'une matrice creuse et d'une matrice pleine.
* \param MP Matrice pleine.
* \param MC Matrice creuse
* \return Une matrice temporaire contenant le produit des deux matrices.
*/

MatPleine& operator * (MatCreuse& MC, MatPleine& MP)
{
	MatPleine* M_temp = new MatPleine(MC.nb_l, MP.nb_c);
	
	if(MC.nb_c != MP.nb_l)
	{
		cerr<<"Produit impossible, problème de taille."<<endl;
		M_temp->nb_l = 0;
		M_temp->nb_c = 0;
		M_temp->tableau = NULL;
	}

	else
	{
		for(int i=0; i<MC.nb_l; i++)
		{
			for(int j=0; j<MP.nb_c; j++)
			{
				M_temp->tableau[i][j]=0;
				
				for(int k=0; k<MC.nb_c; k++)
				{
					M_temp->tableau[i][j] += MC.Valeur(i,k) * MP.tableau[k][j];
				}
			}
		}

		M_temp->nb_l = MC.nb_l;
		M_temp->nb_c = MP.nb_c;
	}
	
	return *M_temp;
}


//_______________FIN OPERATEURS________________

/**
* \brief Sauvegarde une matrice pleine.
* \details Sauvegarde une matrice pleine dans un fichier dont on donne le nom
* \	   et qui est placé dans le dossier sauvegardes.
*/

void MatPleine::Sauvegarde()
{
	int valeurs_non_nulles = 0;
	valeurs_non_nulles = Total_Cases();
    string chemin;
    string nomfichier;
    cout<<"Donner le nom du fichier:"<<endl;
    cin>>nomfichier;
    chemin="./sauvegardes/"+nomfichier;
    fstream fichier;
    fichier.open(chemin.c_str(),ios::out | ios::trunc);
    fichier<<nb_l<<endl<<nb_c<<endl<<valeurs_non_nulles<<endl;
    for (int i=0; i<nb_l; i++)
	{
		for(int j=0;j<nb_c;j++)
		{
			fichier<<i<<"\t"<<j<<"\t"<<tableau[i][j]<<endl;
		}
    }
    fichier.close();
    cout<<"fin"<<endl;
}

/**
* \brief Compteur du nombre de cases non nulles d'une matrice pleine.
* \details Comptes le nombre de cases non nulle d'une matrice pleine en la parcourant.
* \param somme Sert de compteur.
* \return somme.
*/

int MatPleine::Total_Cases()
{
	int somme = 0;
	for(int i=0; i<nb_l; i++)
	{
		for(int j=0; j<nb_c; j++)
		{
			if(tableau[i][j] != 0)
				somme++;
		}
	}
	return somme;
}

/**
* \brief Charger une matrice pleine.
* \details Effectue le chargement d'une matrice contenue dans un fichier pour la copier dans une matrice pleine.
* \param fichier Le fichier en cours de chargement.
*/

void MatPleine::Charger(fstream& fichier, int nbl, int nbc)
{

	nb_l=nbl;
	nb_c=nbc;

    tableau = new double*[nb_l];

	for (int i=0; i<nb_l; i++)
    {
    	tableau[i] = new double[nb_c];
        for(int j=0; j<nb_c;j++)
        {
        	int a,b;
        	fichier>>a;
        	fichier>>b;
        	fichier>>tableau[i][j];
        }
	}

}

/**
* \brief Génère aléatoirement le contenu d'une matrice pleine.
* \details Remplit une matrice pleine de manière aléatoire.
* \return La matrice temporaire qui a été remplie est retournée.
*/

MatPleine& MatPleine::Generateur_Aleat()
{
	int a=100, b=500;
	double c=-100.0;
	double d=100.0;
	int lignes = 0, colonnes = 0;
	
	srand(time(NULL)); // initialisation de rand
	lignes = rand()%(b-a)+a;
	colonnes = rand()%(b-a)+a;

	MatPleine* M_temp = new MatPleine(lignes,colonnes);

	for(int i=0; i<M_temp->nb_l; i++)
	{
		for(int j=0; j<M_temp->nb_c; j++)
		{
			M_temp->tableau[i][j] = (rand()/(double)RAND_MAX )*(d-c)+c;
		}
	}
	return *M_temp;
}

/**
* \brief Transposé d'une matrice pleine.
* \details Effectue la transposé d'une matrice pleine.
* \return Une matrice temporaire contenant la transposé.
*/

MatPleine& MatPleine::Transpose()
{
    MatPleine* M_temp=new MatPleine(nb_l, nb_c);
    
    M_temp->nb_l=nb_c;
    M_temp->nb_c=nb_l;
    
    for (int i = 0; i < nb_l; i++)
    {
        for (int j = 0; j < nb_c; j++)
        {
            M_temp->tableau[i][j] = tableau[j][i];
        }
    }
    return *M_temp;
}

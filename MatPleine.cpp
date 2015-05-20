#include <iostream>
#include <stdlib.h> 
#include <string>
#include <time.h>
#include <fstream>
#include <limits>
#include "MatPleine.h"
#include "MatCreuse.h"
using namespace std;

MatPleine::MatPleine(int nbl, int nbc)
{
	nb_l = nbl;
	nb_c = nbc;

	tableau = new double*[nb_l];
	for(int i=0; i<nb_l; i++)
		tableau[i]=new double[nb_c];
}

MatPleine::~MatPleine()
{
	Destruction();
}

void MatPleine::Destruction()
{
	for(int i=0; i<nb_l; i++)
		delete[] tableau[i];
}

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


MatPleine& operator + (MatPleine& MP1, const int& x)
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

MatPleine& operator - (MatPleine& MP1, const int& x)
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

MatPleine& operator * (MatPleine& MP1, const int& x)
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

MatPleine& operator / (MatPleine& MP1, const int& x)
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

//_______________FIN OPERATEURS________________

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

//!
 //! \file          MatCreuse.cpp
 //! \author      GELOCRRG
 //! \version   1.0
 //! \date       20 mai 2015
 //! \brief       Gère l'utilisation des matrices creuses.
 //! \details    Cette classe
 //!

#include <iostream>
#include <cmath>
#include "MatCreuse.h"
#include "MatPleine.h"
using namespace std;



/*_______________________________________ CONSTRUCTION _____________________________________*/


//!
//! \brief Affectation des valeurs des cases creuses.
//! \param valeur Valeur entrée dans la matrice.
//! \param numligne Coordonnée de la valeur.
//! \param numcolonne Coordonnée de la valeur.
//!
 
CaseCreuse* Nb_C(double valeur, int numligne, int numcolonne)
{
    CaseCreuse* cr = new CaseCreuse;
    
    cr->val = valeur;
    cr->ilig = numligne;
    cr->icol = numcolonne;
    cr->sl = NULL;
    cr->sc = NULL;
    
    return cr;
}

//!
//! \brief Création d'une nouvelle matrice creuse.
//! \details Création d'une matrice creuse avec les dimensions en arguments
//! \param tailleligne Nombre de lignes de la matrice creuse.
//! \param taillecolonne Nombre de colonne de la matrice creuse.
//!

void MatCreuse::NM(int tailleligne, int taillecolonne)
{
    nb_l=tailleligne; 
    nb_c=taillecolonne;
    Lig= new CaseCreuse*[nb_l];
    Col= new CaseCreuse*[nb_c];
    for (int i = 0; i < nb_l; ++i)
    {
        Lig[i]=NULL;
    }
    for (int j = 0; j < nb_c; ++j)
    {
        Col[j]=NULL;
    }
} 

//!
//! \brief Constructeur.
//! \details Création d'une matrice creuse initialisé sans valeurs.
//!

MatCreuse::MatCreuse()
{
    nb_l=0;
    nb_c=0;
    Lig=NULL;
    Col=NULL;
}

//!
//! \brief Constructeur.
//! \details Création d'une matrice creuse avec les dimensions en arguments
//! \param tailleligne Nombre de lignes de la matrice creuse.
//! \param taillecolonne Nombre de colonne de la matrice creuse.
//!

MatCreuse::MatCreuse(int tailleligne, int taillecolonne)
{
    if(tailleligne != 0 && taillecolonne != 0) NM(tailleligne,taillecolonne);
}

//!
//! \brief Constructeur.
//! \details Constructeur par recopie.
//! \param M Matrice creuse copiée.
//!

MatCreuse::MatCreuse(const MatCreuse &M)
{
    NM(M.nb_l,M.nb_c);
    
    CaseCreuse* tmp=new CaseCreuse;

    for(int i = 0;i<nb_l;i++)
    { 
        tmp=M.Lig[i];

        for(int j=0;j<nb_c;j++)
        {
            if(tmp!=NULL) {Insertion(i,j,tmp->val);tmp=tmp->sl;}
            else Insertion(i,j,0);
            
        }
    }
}

//!
//! \brief Destructeur.
//! \details Destructeur de matrice creuse.
//!

MatCreuse::~MatCreuse()
{
    Destruction();
}

//!
//! \brief Destruction de matrices creuses.
//! \details Appelée par le destructeur pour remplacer les valeurs par 0 et détruire les tableaux.
//!

void MatCreuse::Destruction()
{
    for(int i = 0;i<nb_l;i++) //Suppression de toutes les cases
    {
        for(int j=0;j<nb_c;j++)
        {
            Insertion(i,j,0);
        }
    }

    delete[] Lig; //Suppression des tableaux
    delete[] Col;
}


/*_______________________________________ DIVERS _____________________________________*/

//!
//! \brief Affichage.
//! \details Affiche une matrice creuse.
//!

void MatCreuse::Afficher()
{
    cout<<endl;
    if(nb_l == 0 || nb_c == 0)
        cout<<"Pas de matrice "<<endl;
    else
    {
        for(int i=0; i<nb_l; i++)
        {
            double* T = new double[nb_c];
            
            for(int j=0; j<nb_c; j++)
                T[j] = 0;
            CaseCreuse* c = Lig[i];
            while(c != NULL)
            {
                T[c->icol] = c->val;
                c = c->sl;
            }
            for(int k=0; k<nb_c; k++)
            {
                if(T[k] != 0)
                {
                    cout<<T[k]<<"\t";
                }
                else
                    cout<<'_'<<"\t";
            }
            delete[] T;
            cout<<endl;
        }
    }

    cout<<endl;

}

//!
//! \brief Génèrateur de cases creuses.
//! \details Génère des cases creuses si possible et les renvoie.
//! \param temp Case creuse générée temporairement.
//! \return Retourne temp si la case creuse a été créée et 0 sinon.
//!

double MatCreuse::Valeur(int i, int j)
{
    if(Lig[i] == NULL || Col[j] == NULL)
        return 0;
    CaseCreuse* temp = new CaseCreuse;
    temp = Lig[i];
    while(temp->sl != NULL && temp->icol != j)
        temp = temp->sl;
    if(temp->icol == j)
        return temp->val;
    
    return 0;
}

//!
//! \brief Insertion de valeurs dans la matrice creuse.
//! \details Génère une case creuse de valeur v et l'insère dans la matrice creuse.
//! \param v Valeur de la case creuse.
//!

void MatCreuse::Insertion(int i, int j, double v)
{
    if(nb_c == 0 || nb_l == 0) return;
    if(v==0)
    {
        if(Valeur(i,j)!=0)
        {
            CaseCreuse* temp = new CaseCreuse;
            CaseCreuse* precl = new CaseCreuse;
            CaseCreuse* precc = new CaseCreuse;
            temp = Lig[i];
            precl=Lig[i];
            precc=Col[j];

            while(temp->sl != NULL && temp->icol != j)
                temp = temp->sl;

            while(precl->sl != NULL && precl->sl->val != temp->val)
                precl = precl->sl;

            while(precc->sc != NULL && precc->sc->val != temp->val)
                precc = precc->sc;

            if(temp!=Lig[i]) precl->sl=temp->sl;
            else Lig[i]=temp->sl;

            if(temp!=Col[j]) precc->sc=temp->sc;
            else Col[j]=temp->sc;

            delete temp;
            
        }

        return;
    }

    CaseCreuse* c = new CaseCreuse;
    c = Nb_C(v, i, j);
    CaseCreuse* tmp = new CaseCreuse;
    CaseCreuse* prec = new CaseCreuse;
    CaseCreuse* suiv = new CaseCreuse;
    if(Lig[i] == NULL)
        Lig[i] = c;
    else
    {
        tmp = Lig[i];
        if(c->icol < tmp->icol)
        {
            Lig[i] = c;
            c->sl = tmp;
        }
        else if(c->icol == tmp->icol)
        {
            tmp->val = v;
        }
            
        else
        {
            while(tmp != NULL && tmp->icol < c->icol)
            {
                prec = tmp;
                tmp = tmp->sl;
            }
            if(c->icol == prec->icol)
                prec->val = v;
    
            else
            {
                suiv = prec->sl;
                prec->sl = c;
                c->sl = suiv;
            }
        }
    }
    if(Col[j] == NULL)
        Col[j] = c;
    else
    {
        tmp = Col[j];
        if(c->ilig < tmp->ilig)
        {
            Col[j] = c;
            c->sc = tmp;
        }
        else if(c->ilig == tmp->ilig)
            tmp->val = v;
        else
        {    
            while(tmp != NULL && tmp->ilig < c->ilig)
            {
                prec = tmp;
                tmp = tmp->sc;
            }
            if(c->ilig == prec->ilig)
                prec->val = v;
            else
            {
                suiv = prec->sc;
                prec->sc = c;
                c->sc = suiv;
            }
        }
    }

}

/*_______________________________________ OPERATEURS _____________________________________*/

//!
//! \brief Opérateur = entre deux matrices creuses.
//! \details Copie une matrice creuse dans une autre matrice creuse.
//! \param MC Matrice creuse à copier.
//! \return La copie de MC.
//!

MatCreuse& MatCreuse::operator=(MatCreuse& MC)
{
    NM(MC.nb_l,MC.nb_c);
    
    CaseCreuse* tmp=new CaseCreuse;

    for(int i = 0;i<nb_l;i++)
    { 
        tmp=MC.Lig[i];
        for(int j=0;j<nb_c;j++)
        {
            if(tmp!=NULL) 
            {
                Insertion(tmp->ilig,tmp->icol,tmp->val);
                i=tmp->ilig;
                j=tmp->icol;
                tmp=tmp->sl;
            }
            else Insertion(i,j,0);
        }
    }

    return *this;
}

//!
//! \brief Opérateur = entre une matrice creuse et une matrice pleine.
//! \details Copie une matrice pleine dans une matrice creuse.
//! \param MP Matrice pleine à copier.
//! \return La copie de MP.
//!

MatCreuse& MatCreuse::operator=(MatPleine& MP)
{
    NM(MP.nb_l,MP.nb_c);

    for (int i = 0; i < nb_l; ++i)
    {
        for (int j = 0; j < nb_c; ++j)
        {
            Insertion(i,j,MP.tableau[i][j]);
        }
    }

    return *this;
}

//!
//! \brief Opérateur + entre deux matrices creuses.
//! \details Effectue la somme de deux matrices creuses.
//! \param MC1 Première matrice de la somme.
//! \param MC2 Deuxième matrice de la somme
//! \return La somme dans une matrice temporaire.
//!

MatCreuse& operator+(MatCreuse& MC1, MatCreuse& MC2)
{
    MatCreuse* M_temp= new MatCreuse(MC1.nb_l,MC2.nb_c);
    bool changeM=true, changeN=true;

    if(MC2.nb_l == MC1.nb_l && MC2.nb_c == MC1.nb_c)
    {
        CaseCreuse* tMp=new CaseCreuse;
        CaseCreuse* tNp=new CaseCreuse;

        for(int i = 0;i<MC1.nb_l;i++)
        { 
            tMp=MC2.Lig[i];
            tNp=MC1.Lig[i];
            for(int j=0;j<MC1.nb_c;j++)
            {

                if(tMp==NULL && tNp !=NULL)
                {
                    M_temp->Insertion(tNp->ilig,tNp->icol,tNp->val);
                    j=tNp->icol;
                    changeM=false;
                    changeN=true;
                }

                else if(tMp!=NULL && tNp ==NULL)
                {
                    M_temp->Insertion(tMp->ilig,tMp->icol,tMp->val);
                    j=tMp->icol;
                    changeN=false;
                    changeM=true;

                }

                else if(tMp==NULL && tNp == NULL)
                {
                    M_temp->Insertion(i,j,0);
                    changeM=false;
                    changeN=false;
                }

                else 
                {
                    if(tMp->icol==tNp->icol)
                    {
                        M_temp->Insertion(tMp->ilig,tMp->icol,(tMp->val+tNp->val));
                        j=tMp->icol;
                        changeM=true;
                        changeN=true;

                    }

                    else if(tMp->icol<tNp->icol)
                    {
                        M_temp->Insertion(tMp->ilig,tMp->icol,tMp->val);
                        j=tMp->icol;
                        changeN=false;
                        changeM=true;
                    }

                    else 
                    {
                        M_temp->Insertion(tNp->ilig,tNp->icol,tNp->val);
                        j=tNp->icol;
                        changeM=false;
                        changeN=true;
                    }
                }
                if(changeM) tMp=tMp->sl;
                if(changeN) tNp=tNp->sl;
            }
        }
    }

    else
    {
        cout<<"Erreur, tailles de matrices différentes"<<endl;
        M_temp->nb_l=0;
        M_temp->nb_c=0;
        M_temp->Lig=NULL;
        M_temp->Col=NULL;
    }

    return *M_temp;
}


//!
//! \brief Opérateur - entre deux matrices creuses.
//! \details Effectue la différence entre deux matrices creuses.
//! \param MC1 Première matrice de la différence.
//! \param MC2 Deuxième matrice de la différence.
//! \return Retourne le résultat de la différence dans une matrice temporaire.
//!

MatCreuse& operator-(MatCreuse& MC1, MatCreuse& MC2)
{
    MatCreuse* M_temp= new MatCreuse(MC1.nb_l,MC1.nb_c);
    bool changeM=true, changeN=true;

    if(MC2.nb_l == MC1.nb_l && MC2.nb_c == MC1.nb_c)
    {
        CaseCreuse* tMp=new CaseCreuse;
        CaseCreuse* tNp=new CaseCreuse;

        for(int i = 0;i<MC1.nb_l;i++)
        { 
            tMp=MC2.Lig[i];
            tNp=MC1.Lig[i];
            for(int j=0;j<MC1.nb_c;j++)
            {

                if(tMp==NULL && tNp !=NULL)
                {
                    M_temp->Insertion(tNp->ilig,tNp->icol,tNp->val);
                    j=tNp->icol;
                    changeM=false;
                    changeN=true;
                }

                else if(tMp!=NULL && tNp ==NULL)
                {
                    M_temp->Insertion(tMp->ilig,tMp->icol,-(tMp->val));
                    j=tMp->icol;
                    changeN=false;
                    changeM=true;

                }

                else if(tMp==NULL && tNp == NULL)
                {
                    M_temp->Insertion(i,j,0);
                    changeM=false;
                    changeN=false;
                }

                else 
                {
                    if(tMp->icol==tNp->icol)
                    {
                        M_temp->Insertion(tMp->ilig,tMp->icol,(tNp->val-tMp->val));
                        j=tMp->icol;
                        changeM=true;
                        changeN=true;

                    }

                    else if(tMp->icol<tNp->icol)
                    {
                        M_temp->Insertion(tMp->ilig,tMp->icol,-(tMp->val));
                        j=tMp->icol;
                        changeN=false;
                        changeM=true;
                    }

                    else 
                    {
                        M_temp->Insertion(tNp->ilig,tNp->icol,tNp->val);
                        j=tNp->icol;
                        changeM=false;
                        changeN=true;
                    }
                }
                if(changeM) tMp=tMp->sl;
                if(changeN) tNp=tNp->sl;
            }
        }
    }

    else
    {
        cout<<"Erreur, tailles de matrices différentes"<<endl;
        M_temp->nb_l=0;
        M_temp->nb_c=0;
        M_temp->Lig=NULL;
        M_temp->Col=NULL;
    }

    return *M_temp;
}


/*
M est en haut
la matrice appelante est a gauche
      M M
      M M
      M M
N N N x x      OK
N N N x x

      M M
      M M
      M M      OK
N N N x x

    M M M
    M M M
N N x x x       OK
N N x x x

      M M
      M M     NOT OK
N N N
N N N

*/

//!
//! \brief Opérateur * entre deux matrices creuses.
//! \details Effectue le produit entre deux matrices creuses.
//! \param MC1 Première matrice du produit.
//! \param MC2 Deuxième matrice du produit.
//! \return Retourne le résultat du produit dans une matrice temporaire.
//!

MatCreuse& operator*(MatCreuse& MC1, MatCreuse& MC2)
{
    MatCreuse* M_temp= new MatCreuse(MC1.nb_l,MC2.nb_c);
    bool changeM=true, changeN=true;

    if(MC1.nb_c==MC2.nb_l)
    {
        CaseCreuse* tMp=new CaseCreuse;
        CaseCreuse* tNp=new CaseCreuse;
        double somme=0;
        int i=0,ind_col=0, ind_lig=0;
        tMp=MC2.Col[0];
        tNp=MC1.Lig[0];

        while(i<(MC1.nb_l*MC2.nb_c))
        {
            somme=0;
            for(int j=0;j<MC1.nb_l;j++)
            {                
                if(tMp==NULL && tNp==NULL)
                {
                    changeM=false;
                    changeN=false;
                    j=MC1.nb_l;

                }

                else if(tMp==NULL)
                {
                    changeM=false;
                    changeN=true;

                }

                else if(tNp==NULL)
                {
                    changeM=true;
                    changeN=false;

                }

                else
                {                    
                    if(tMp->ilig==tNp->icol)
                    {
                        somme+=((tMp->val)*(tNp->val));
                        changeM=true;
                        changeN=true;
                    }

                    else if(tMp->ilig<tNp->icol)
                    {
                        changeM=true;
                        changeN=false;

                    }

                    else
                    {
                        changeM=false;
                        changeN=true;
                    }
                }
                
                if(changeM) tMp=tMp->sc;
                if(changeN) tNp=tNp->sl;
            }

            M_temp->Insertion(ind_lig,ind_col,somme);
            if(ind_col<M_temp->nb_c-1) ind_col++;
            else 
            {
                ind_col=0;
                ind_lig++;
            }
            tMp=MC2.Col[ind_col];
            tNp=MC1.Lig[ind_lig];
            i++;

        }
    }

    else
    {
        cout<<"Erreur, tailles de matrices différentes"<<endl;
        M_temp->nb_l=0;
        M_temp->nb_c=0;
        M_temp->Lig=NULL;
        M_temp->Col=NULL;
    }

    return *M_temp;


}

//!
//! \brief Transpose une matrice creuse.
//! \details Effetue la transposé d'une matrice creuse.
//! \return Retourne la transposé dans une matrice temporaire.
//!

MatCreuse& MatCreuse::Transpose()
{
    MatCreuse* M_temp=new MatCreuse(nb_c, nb_l);

    for (int i = 0; i < nb_l; ++i)
    {
        for (int j = 0; j < nb_c; ++j)
        {
            M_temp->Insertion(j,i,Valeur(i,j));
        }
    }

    return *M_temp;
}

//!
//! \brief Opérateur + entre une matrice creuse et un entier.
//! \details Effectue la somme d'une matrice creuse et d'un entier.
//! \param MC1 Matrice de la somme.
//! \param x Entier à ajouter à la matrice.
//! \return Retourne le résultat de la somme dans une matrice temporaire.
//!

MatCreuse& operator+(MatCreuse& MC1, double& x)
{

    MatCreuse* M_temp= new MatCreuse(MC1.nb_l,MC1.nb_c);
    
    CaseCreuse* tmp=new CaseCreuse;

    for(int i = 0;i<MC1.nb_l;i++)
    { 
        tmp=MC1.Lig[i];

        for(int j=0;j<MC1.nb_c;j++)
        {
            if(tmp!=NULL && tmp->icol==j) {M_temp->Insertion(i,j,tmp->val+x);tmp=tmp->sl;}
            else M_temp->Insertion(i,j,x);
            
        }
    }

    return *M_temp;
}

//!
//! \brief Opérateur - entre une matrice creuse et un entier.
//! \details Effectue la différence d'une matrice creuse et d'un entier.
//! \param MC1 Matrice de la différence.
//! \param x Entier à soustraire à la matrice.
//! \return Retourne le résultat de la différence dans une matrice temporaire.
//!

MatCreuse& operator-(MatCreuse& MC1, double& x)
{

    MatCreuse* M_temp= new MatCreuse(MC1.nb_l,MC1.nb_c);
    
    CaseCreuse* tmp=new CaseCreuse;

    for(int i = 0;i<MC1.nb_l;i++)
    { 
        tmp=MC1.Lig[i];

        for(int j=0;j<MC1.nb_c;j++)
        {
            if(tmp!=NULL && tmp->icol==j) {M_temp->Insertion(i,j,tmp->val-x);tmp=tmp->sl;}
            else M_temp->Insertion(i,j,-x);
            
        }
    }

    return *M_temp;
}

//!
//! \brief Opérateur * entre une matrice creuse et un entier.
//! \details Effectue le produit d'une matrice creuse et d'un entier.
//! \param MC1 Matrice du produit.
//! \param x Entier à multiplier à la matrice.
//! \return Retourne le résultat du produit dans une matrice temporaire.
//!

MatCreuse& operator*(MatCreuse& MC1, double& x)
{

    MatCreuse* M_temp= new MatCreuse(MC1.nb_l,MC1.nb_c);
    
    CaseCreuse* tmp=new CaseCreuse;

    for(int i = 0;i<MC1.nb_l;i++)
    { 
        tmp=MC1.Lig[i];

        for(int j=0;j<MC1.nb_c;j++)
        {
            if(tmp!=NULL && tmp->icol==j) {M_temp->Insertion(i,j,tmp->val*x);tmp=tmp->sl;}
            else M_temp->Insertion(i,j,0);
            
        }
    }

    return *M_temp;
}

//!
//! \brief Opérateur / entre une matrice creuse et un entier.
//! \details Effectue le quotient d'une matrice creuse et d'un entier.
//! \param MC1 Matrice du quotient.
//! \param x Entier qui divise la matrice.
//! \return Retourne le résultat du quotient dans une matrice temporaire.
//!

MatCreuse& operator/(MatCreuse& MC1, double& x)
{

    MatCreuse* M_temp= new MatCreuse(MC1.nb_l,MC1.nb_c);
    
    CaseCreuse* tmp=new CaseCreuse;

    for(int i = 0;i<MC1.nb_l;i++)
    { 
        tmp=MC1.Lig[i];

        for(int j=0;j<MC1.nb_c;j++)
        {
            if(tmp!=NULL && tmp->icol==j) {M_temp->Insertion(i,j,tmp->val/x);tmp=tmp->sl;}
            else M_temp->Insertion(i,j,0);
            
        }
    }

    return *M_temp;
}

//!
//! \brief Charger une matrice creuse.
//! \details Chargement d'une matrice creuse à partir d'un fichier.
//!

void MatCreuse::Charger(fstream& fichier, int nbl, int nbc)
{
    nb_l=nbl;
    nb_c=nbc;

    NM(nb_l,nb_c);

    for (int i=0; i<nb_l; i++)
    {
        for(int j=0; j<nb_c;j++)
        {
            int a,b;
            double val;
            fichier>>a;
            fichier>>b;
            fichier>>val;

            Insertion(a,b,val);
        }
    }
}

//!
//! \brief Opérateur + entre un entier et une matrice creuse.
//! \details Effectue la somme d'une matrice creuse et d'un entier.
//! \param MC Matrice de la somme.
//! \param x Entier à ajouter à la matrice.
//! \return Retourne le résultat de l'opérateur + entre une matrice creuse et un entier.
//!

MatCreuse& operator+(double& x, MatCreuse& MC)
{
    return MC+x;
}

//!
//! \brief Opérateur - entre un entier et une matrice creuse.
//! \details Effectue la somme d'une matrice creuse dont on oppose les valeurs et d'un entier.
//! \param MC Matrice de la somme.
//! \param x Entier à ajouter à la matrice.
//! \return Retourne le résultat de l'opérateur + entre une matrice creuse multipliée par -1 et un entier.
//!

MatCreuse& operator-(double& x, MatCreuse& MC)
{
    double mul=-1.0;
    return (mul*MC)+x;
}

//!
//! \brief Opérateur * entre un entier et une matrice creuse.
//! \details Effectue le produit d'une matrice creuse et d'un entier.
//! \param MC Matrice du produit.
//! \param x Entier à multiplier à la matrice.
//! \return Retourne le résultat de l'opérateur * entre une matrice creuse et un entier.
//!

MatCreuse& operator*(double& x, MatCreuse& MC)
{
    return MC*x;
}

//!
//! \brief Sauvegarder une matrice creuse.
//! \details Sauvegarde d'une matrice creuse dans un fichier placé dans le dossier "sauvegardes".
//! \param nbvaleurs Le nombre de valeurs de la matrice qui est aussi entré dans le fichier
//!                  pour reconnaître une matrice creuse à la lecture.
//!

void MatCreuse::Sauvegarde(int nbvaleurs)
{
    string chemin;
    string nomfichier;
    cout<<"Donner le nom du fichier:"<<endl;
    cin>>nomfichier;
    chemin="./sauvegardes/"+nomfichier;
    fstream fichier;
    fichier.open(chemin.c_str(),ios::out | ios::trunc);
    
    fichier<<nb_l<<endl<<nb_c<<endl<<nbvaleurs<<endl;

    for (int i=0; i<nb_l; i++)
    {
        for(int j=0;j<nb_c;j++)
        {
            if(Valeur(i,j)!=0)
                fichier<<i<<"\t"<<j<<"\t"<<Valeur(i,j)<<endl;
        }
    }
    fichier.close();
    cout<<"fin"<<endl;
}

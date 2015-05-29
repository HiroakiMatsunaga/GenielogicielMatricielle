//!
//! \file MatCreuse.h
//! \author GELOCRRG
//! \version 1.0
//! \date 28 mai 2015
//! \brief Gestionnaire de matrices creuses.
//!

#ifndef MatCreuse_H
#define MatCreuse_H
#include <string>
#include <fstream>
#include "MatPleine.h"

class MatPleine;

//!
//! \struct CaseCreuse
//! \brief Le contenu d'une case de la matrice creuse.
//!
//! Contient la valeur de la case, ses coordonnées et  deux pointeurs indiquant respectivement 
//! la case creuse suivante de la ligne et celle de la colonne.
//!

struct CaseCreuse
{
double val;
int ilig;
int icol;
CaseCreuse * sl;
CaseCreuse * sc;
friend class MatCreuse;
};

//! \class MatCreuse
//! \brief Classe gèrant les matrices creuses
//!
//! La classe réalisé les opérations possibles sur les matrices creuses.
//!
class MatCreuse
{
    public:
    int nb_l;
    int nb_c;
    CaseCreuse ** Lig;
    CaseCreuse ** Col;
    friend class Matrice;
    friend class MatPleine;

    //!
    //! \brief Construceur
    //!
    //! Constructeur de la classe MatCreuse.
    //!
    MatCreuse();
    
    //!
    //! \brief Constructeur
    //!
    //! Constructeur de la classe MatCreuse avec dimensions en arguments.
    //!
    MatCreuse(int, int);
    
    //!
    //! \brief Constructeur
    //!
    //! Constructeur par recopie d'une matrice creuse préexistante.
    //!
    MatCreuse(const MatCreuse&);
    
    //!
    //! \brief Destructeur
    //!
    //! Destructeur de la classe MatCreuse.
    //!
    ~MatCreuse();
    
    //!
    //! \brief Destruction de matrice creuse
    //!
    //! Fonction appelée par le destructeur pour détruire les matrices creuses.
    //!
    void Destruction();
    
    //!
    //! \brief Création d'une matrice creuse avec dimenseions en arguments.
    //!
    //! Fonction appelée par le constructeur de matrice creuse avec dimansions en arguments.
    //!
    void NM(int, int);
    
    //!
    //! \brief Affichage
    //!
    //! Affiche la matrice creuse.
    //!
    void Afficher();
    
    //!
    //! \brief Générateur de cases creuses
    //!
    //! Fonction appelé pour créer de nouvelles cases creuses à insérer dans la matrice.
    //!
    double Valeur(int,int);
    
    //!
    //! \brief Insertion
    //!
    //! Insère une nouvelle case creuse dans la matrice.
    //!
    void Insertion(int, int, double);
    
    //!
    //! \brief Opérateur = entre deux matrices creuses
    //!
    //! Copie une matrice creuse dans une autre.
    //!
    MatCreuse& operator=(MatCreuse&);
    
    //!
    //! \brief Opérateur = entre une matrice creuse et une matrice pleine.
    //!
    //! Copie une matrice pleine dans une matrice creuse.
    //!
    MatCreuse& operator=(MatPleine&);
    
    //!
    //! \brief Opérateur + entre deux matrices creuses
    //!
    //! Somme deux matrices creuses.
    //!
    friend MatCreuse& operator+(MatCreuse&, MatCreuse&);
    
    //!
    //! \brief Opérateur - entre deux matrices creuses
    //!
    //! Différence entre deux matrices creuses.
    //!
    friend MatCreuse& operator-(MatCreuse&, MatCreuse&);
    
    //!
    //! \brief Opérateur * entre deux matrices creuses
    //!
    //! Produit de deux matrices creuses.
    //!
    friend MatCreuse& operator*(MatCreuse&, MatCreuse&);
    
    //!
    //! \brief Opérateur + entre une matrice creuse et un entier
    //!
    //! Somme une matrice creuse et un entier.
    //!
    friend MatCreuse& operator+(MatCreuse&, double &x);
    
    //!
    //! \brief Opérateur - entre une matrice creuse et un entier
    //!
    //! Différence entre une matrice creuse et un entier.
    //!
    friend MatCreuse& operator-(MatCreuse&, double &x);
    
    //!
    //! \brief Opérateur * entre une matrice creuse et un entier.
    //!
    //! Produit d'une matrice creuse et d'un entier.
    //!
    friend MatCreuse& operator*(MatCreuse&, double &x);
    
    //!
    //! \brief Opérateur / entre une matrice creuse et un entier.
    //!
    //! Division d'une matrice creuse par un entier.
    //!
    friend MatCreuse& operator/(MatCreuse&, double &x);
    
    //!
    //! \brief Opérateur + entre un entier et une matrice creuse.
    //!
    //! Somme une matrice creuse et un entier.
    //!
    friend MatCreuse& operator+(double&, MatCreuse&); 
    
    //!
    //! \brief Opérateur - entre un entier et une matrice creuse.
    //!
    //! Somme une matrice creuse avec des valeurs multipliées par -1 et un entier.
    //!
    friend MatCreuse& operator-(double&, MatCreuse&);
    
    //!
    //! \brief Opérateur * entre un entier et une matrice creuse.
    //!
    //! Produit d'une matrice creuse et d'un entier.
    //!
    friend MatCreuse& operator*(double&, MatCreuse&); 

    //!
    //! \brief Transposé.
    //!
    //! Transposé d'une matrice.
    //!
    MatCreuse& Transpose();
    
    //!
    //! \brief Charger.
    //!
    //! Charge une matrice creuse contenue dans un fichier.
    //!
    void Charger(std::fstream&, int, int);
    
    //!
    //! \brief Sauvegarder.
    //!
    //! Sauvegarde une matrice creuse dans un fichier.
    //!
    void Sauvegarde(int);

};



 
 #endif

/**
* \file MatPleine.h
* \author GELOCRRG
* \version 1.0
* \date 28 mai 2015
* \brief Gestionnaire de matrices pleines.
*/

#ifndef ___MATPLEINE_H___
#define ___MATPLEINE_H___
#include "MatCreuse.h"
#include <string>
#include <fstream>

class MatCreuse;

/** \class MatPleine
   * \brief Classe gèrant les matrices pleines
   *
   *  La classe réalisé les opérations possibles sur les matrices pleines.
   */
class MatPleine
{
public:
    int nb_l;
    int nb_c;
    double ** tableau;
    friend class Matrice;
    friend class MatCreuse;

    /**
    * \brief Constructeur
    *
    *  Constructeur de la classe MatPleine avec dimensions en arguments.
    */
    MatPleine(int,int);
    
    /**
    * \brief Destructeur
    *
    *  Destructeur de la classe MatPleine.
    */
    ~MatPleine();
    
    /**
    * \brief Détruit une matrice pleine
    *
    *  Détruit la matrice pleine.
    */
    void Destruction();
    
    /**
    * \brief Remplit la matrice pleine
    *
    *  Demandes les valeurs à donner aux cases de la matrice pleine.
    */
    int Remplissage();
    
    /**
    * \brief Affichage
    *
    *  Affichage d'une matrice pleine.
    */
    void Afficher();
    
    /**
    * \brief opérateur = entre deux matrices pleines
    *
    *  Copie une matrice pleine dans une autre.
    */
    MatPleine& operator=(MatPleine&);
    /**
    * \brief opérateur = entre une matrice pleine et une matrice creuse
    *
    *  Copie une matrice creuse dans une matrice pleine.
    */
    MatPleine& operator=(MatCreuse&);
    
    /**
    * \brief opérateur + entre deux matrices pleines
    *
    *  Effectue la somme de deux matrices pleines.
    */
    friend MatPleine& operator+(MatPleine&,MatPleine&);
    
    /**
    * \brief opérateur - entre deux matrices pleines
    *
    *  Effectue la différence entre deux matrices pleines.
    */
    friend MatPleine& operator-(MatPleine&,MatPleine&);
    
    /**
    * \brief opérateur * entre deux matrices pleines
    *
    *  Effectue le produit de deux matrices pleines.
    */
    friend MatPleine& operator*(MatPleine&,MatPleine&);

    /**
    * \brief opérateur + entre une matrice pleine et un entier
    *
    *  Effectue la somme d'une matrice pleine et d'un entier.
    */
    friend MatPleine& operator+(MatPleine&, double&);
    
    /**
    * \brief opérateur - entre une matrice pleine et un entier
    *
    *  Effectue la différence entre une matrice pleine et un entier.
    */
    friend MatPleine& operator-(MatPleine&, double&);
    
    /**
    * \brief opérateur * entre une matrice pleine et un entier
    *
    *  Effectue le produit d'une matrice pleine et d'un entier.
    */
    friend MatPleine& operator*(MatPleine&, double&);
    
    /**
    * \brief opérateur / entre une matrice pleine et un entier
    *
    *  Effectue le quotient d'une matrice pleine et d'un entier.
    */
    friend MatPleine& operator/(MatPleine&,  double&);
    
    /**
    * \brief opérateur + entre un entier et une matrice pleine 
    *
    *  Effectue la somme d'une matrice pleine et d'un entier.
    */
    friend MatPleine& operator+( double& x, MatPleine& MC);
    
    /**
    * \brief opérateur - entre un entier et une matrice pleine 
    *
    *  Effectue la différence d'une matrice pleine et d'un entier.
    */
    friend MatPleine& operator-( double& x, MatPleine& MC);
    
    /**
    * \brief opérateur * entre un entier et une matrice pleine 
    *
    *  Effectue le produit d'une matrice pleine et d'un entier.
    */
    friend MatPleine& operator*( double& x, MatPleine& MC);


    /**
    * \brief opérateur + entre une matrice pleine et une matrice creuse 
    *
    *  Effectue la somme d'une matrice pleine et d'une matrice creuse.
    */
    friend MatPleine& operator + (MatPleine&, MatCreuse&);
    
    /**
    * \brief opérateur + entre une matrice creuse et une matrice pleine 
    *
    *  Effectue la somme d'une matrice pleine et d'une matrice creuse.
    */
    friend MatPleine& operator + (MatCreuse&, MatPleine&);
    
    /**
    * \brief opérateur - entre une matrice creuse et une matrice pleine 
    *
    *  Effectue la différence entre une matrice creuse et une matrice pleine.
    */
    friend MatPleine& operator - (MatCreuse&, MatPleine&);
    
    /**
    * \brief opérateur * entre une matrice pleine et une matrice creuse 
    *
    *  Effectue le produit d'une matrice pleine et d'une matrice creuse.
    */
    friend MatPleine& operator * (MatPleine&, MatCreuse&);
    
    /**
    * \brief opérateur * entre une matrice creuse et une matrice pleine 
    *
    *  Effectue le produit d'une matrice creuse et d'une matrice pleine.
    */
    friend MatPleine& operator * (MatCreuse&, MatPleine&);


    /**
    * \brief Sauvegarde 
    *
    *  Effectue la sauvegarde d'une matrice pleine dans un fichier.
    */
    void Sauvegarde();
    /**
    * \brief Charger 
    *
    *  Effectue le chargement d'une matrice pleine depuis un fichier.
    */
    void Charger(std::fstream&,int,int);
    
    /**
    * \brief Compteur de cases 
    *
    *  Compte le nombre total de cases non nulles.
    */
    int Total_Cases();
    
    /**
    * \brief Générateur aléatoire 
    *
    *  Remplit une matrice pleine par des valeurs aléatoires.
    */
    MatPleine& Generateur_Aleat();
    
    /**
    * \brief Transpose une matrice pleine 
    *
    *  Effectue la transposé d'une matrice pleine.
    */
    MatPleine& Transpose();

};






#endif

#ifndef ___MATPLEINE_H___
#define ___MATPLEINE_H___
#include "MatCreuse.h"
#include <string>
#include <fstream>

class MatCreuse;

class MatPleine
{
public:
    int nb_l;
    int nb_c;
    double ** tableau;
    friend class Matrice;
    friend class MatCreuse;

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

    friend MatPleine& operator+(MatPleine&, double&);
    friend MatPleine& operator-(MatPleine&, double&);
    friend MatPleine& operator*(MatPleine&, double&);
    friend MatPleine& operator/(MatPleine&,  double&);
    
    friend MatPleine& operator+( double& x, MatPleine& MC);
    friend MatPleine& operator-( double& x, MatPleine& MC);
    friend MatPleine& operator*( double& x, MatPleine& MC);

    friend MatPleine& operator + (MatPleine&, MatCreuse&);
    friend MatPleine& operator + (MatCreuse&, MatPleine&);
    friend MatPleine& operator - (MatCreuse&, MatPleine&);
    friend MatPleine& operator * (MatPleine&, MatCreuse&);
    friend MatPleine& operator * (MatCreuse&, MatPleine&);



    void Sauvegarde();
    void Charger(std::fstream&,int,int);
    int Total_Cases();
    MatPleine& Generateur_Aleat();
    MatPleine& Transpose();

};






#endif

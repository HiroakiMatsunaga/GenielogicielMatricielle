#ifndef MatCreuse_H
#define MatCreuse_H
#include <string>
#include <fstream>
#include "MatPleine.h"

class MatPleine;

struct CaseCreuse
{
double val;
int ilig;
int icol;
CaseCreuse * sl;
CaseCreuse * sc;
friend class MatCreuse;
};

class MatCreuse
{
    int nb_l;
    int nb_c;
    CaseCreuse ** Lig;
    CaseCreuse ** Col;
    friend class Matrice;
    friend class MatPleine;
	public:

    MatCreuse();
    MatCreuse(int, int);
    MatCreuse(const MatCreuse&);
    ~MatCreuse();
    void Destruction();
    void NM(int, int);
    void Afficher();
    double Valeur(int,int);
    void Insertion(int, int, double);
    MatCreuse& operator=(MatCreuse&);
    MatCreuse& operator=(MatPleine&);
    friend MatCreuse& operator+(MatCreuse&, MatCreuse&);
    friend MatCreuse& operator-(MatCreuse&, MatCreuse&);
    friend MatCreuse& operator*(MatCreuse&, MatCreuse&);
    friend MatCreuse& operator+(MatCreuse&, double &x);
    friend MatCreuse& operator-(MatCreuse&, double &x);
    friend MatCreuse& operator*(MatCreuse&, double &x);
    friend MatCreuse& operator/(MatCreuse&, double &x);
    MatCreuse& Transpose();
    void Charger(std::fstream&, int, int);
    void Sauvegarde(int);

};



 
 #endif

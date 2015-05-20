#include <iostream>
#include <cmath>
#include "Matrice.h"
#include "MatPleine.h"
using namespace std;

int main(int argc, char const *argv[])
{
    Matrice A(2,2);
	Matrice B(2,2);
	Matrice C(2,2);
	double z=6.0;
	A=C;
	A.Afficher();
	B=B+z;
	B.Afficher();
	B=B-z;
	B.Afficher();
	B=B*z;
	B.Afficher();
	B=B/z;
	B.Afficher();
	A=A+B;
	A.Afficher();
	A=A-B;
	A.Afficher();
	A=A*B;
	A.Afficher();
	return 0;
}

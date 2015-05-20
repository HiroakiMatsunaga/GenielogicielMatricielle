// addition

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

MatPleine& operator + (MatCreuse& MC, MatPleine& MP)
{
	return MP+MC;
}



// soustraction

MatPleine& operator - (MatCreuse& MP, MatPleine& MC)
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
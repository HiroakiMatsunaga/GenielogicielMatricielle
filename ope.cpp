friend MatCreuse& operator+(MatCreuse&,const double&); //DONE
friend MatCreuse& operator-(MatCreuse&,const double&); //DONE
friend MatCreuse& operator*(MatCreuse&,const double&); //DONE
friend MatCreuse& operator/(MatCreuse&, const double&); //DONE

friend MatCreuse& operator+(const double&, MatCreuse&); //DONE
friend MatCreuse& operator-(const double&, MatCreuse&); //DONE
friend MatCreuse& operator*(const double&, MatCreuse&); //DONE

friend MatCreuse& operator+(MatCreuse&, MatCreuse&); //DONE
friend MatCreuse& operator-(MatCreuse&, MatCreuse&); //DONE
friend MatCreuse& operator*(MatCreuse&, MatCreuse&); //DONE



MatCreuse& operator+(const double& x, MatCreuse& MC)
{
	return MC+x;
}

MatCreuse& operator-(const double& x, MatCreuse& MC)
{
	double mul=-1.0;
	return (mul*MC)+x;
}

MatCreuse& operator*(const double& x, MatCreuse& MC)
{
	return MC*x;
}



MatPleine& operator+(const double& x, MatPleine& MC)
{
	return MC+x;
}

MatPleine& operator-(const double& x, MatPleine& MC)
{
	return MC-x;
}

MatPleine& operator*(const double& x, MatPleine& MC)
{
	return MC*x;
}

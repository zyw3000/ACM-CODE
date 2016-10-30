#include <iostream> 

int main() 
{
	double a, b, c, d, e, f, A, S; 
	while(~scanf("%lg %lg %lg %lg %lg %lg", &a, &b, &c, &d, &e, &f)) 
	{ 
		A = a*8/(8+b+c+d);
		S = a*f/(e+f);
		printf("%.0f %.0f\n", A, S); 
	}	 
	return 0; 
}

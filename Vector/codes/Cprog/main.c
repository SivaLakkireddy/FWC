#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"lib.h"


int main()
{
	double a = 8, k = 3.5, theta = M_PI * 1/4, **r, b;
	double cosine = cos(theta), sine = sin(theta);
	double **e2, **q1, **q2, **q, **A;

	e2 = loadtxt("e2.dat",2,1);
	q1 = loadtxt("q1.dat",2,2);

       	q2 = createMat(2,1);
	q2[0][0] = -pow(a,2)/k;
	q2[1][0] = -k;

	q = matmul(q1,q2,2,2,1);
        r = matmul(transpose(e2,2,1),q,1,2,1);
	b = 1/(2*(1-(a*cosine)/k))*r[0][0];
	A = np_array(b*cosine,b*sine);
	save_D(A,2,1);
	return 0;
}	

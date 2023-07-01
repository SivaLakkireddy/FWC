#include<stdio.h>   
#include<stdlib.h>  
#include<math.h>
#include"lib.h"

int main()
{  
	 double a = 8, k = 3.5, theta = M_PI * 1/4 ,b, r1;

         double cosine = cos(theta), sine = sin(theta); 
	 double **q1, **q2, **B, **C, **e2, **A;  
         node *q, *matrixq1, *matrixq2, *e2_, *r;
					
	
	 q1 = createMatrix(1, 1, 1, -1);
	 matrixq1 = constructLinkedMatrix(q1,2,2);
	 createDatMat("q1.dat", matrixq1);

         q2 = vectorise(-pow(a,2)/k, -k); 
         matrixq2 = constructLinkedMatrix(q2,2,1);        
         createDatMat("q2.dat", matrixq2);

         e2 = vectorise(0.0, 1.0); 
         node* vertexe2 = constructLinkedMatrix(e2,2,1);
         createDatMat("e2.dat", vertexe2);

         B = vectorise(0.0, 0.0);
         node* vertexB = constructLinkedMatrix(B, 2, 1);
         createDatMat("B.dat", vertexB);
    
         C = vectorise(8, 0);
         node* vertexC = constructLinkedMatrix(C, 2, 1);
         createDatMat("C.dat", vertexC);
         
	 q = matMul(matrixq1,matrixq2);
         
	 e2_ = transpose(vertexe2);
	
         r = matMul(e2_,q);
         r1 = get(r);
        
	 b = 1/(2*(1-(a*cosine)/k))*r1;
          

	 A = vectorise(b*cosine,b*sine); 
	 node* vertexA = constructLinkedMatrix(A,2, 1);  
        createDatMat("A.dat", vertexA);

    return 0;

}   


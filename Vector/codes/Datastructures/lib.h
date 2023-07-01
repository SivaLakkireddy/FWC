#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    double data;
    struct node *right, *down;
    int value;
    int row;
    int col;
    struct node* next;
}node;
 
double** vectorise (double v1, double v2);
double** createMatrix(double v11, double v12, double v21, double v22);

node* matMul(node* mat1, node* mat2);
node* transpose(node* head);
double get(node* head);

node* newNode(double d);
void display(node* head);
void matScalarProduct(node* h1, double scalar);
void matSum(node* h1, node* h2);
void sectionFormula(double ratio, node* m1, node* m2);
node* constructLinkedMatrix(double** mat, int m, int n);

double** vectorise (double v1, double v2) {
    double** vector = (double**)malloc(2 * sizeof(*vector));
    for(int i = 0; i < 2; i++)
        vector[i] = (double*)malloc(2 * sizeof(vector));

    vector[0][0] = v1;
    vector[1][0] = v2;
    return vector;
}


double** createMatrix(double v11, double v12, double v21, double v22) {
    double** matrix = (double**)malloc(2 * sizeof(*matrix));
    for (int i = 0; i < 2; i++) 
        matrix[i] = (double*)malloc(2 * sizeof(matrix));

    matrix[0][0] = v11;
    matrix[0][1] = v12;
    matrix[1][0] = v21;
    matrix[1][1] = v22;

    return matrix;
}

node* newNode(double d) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = d;
    temp->right = temp->down = NULL;
    return temp;
}



node* createNode(int value, int row, int col) 
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->value = value;
    newNode->row = row;
    newNode->col = col;
    newNode->next = NULL;
    return newNode;
}



node* matMul(node* mat1, node* mat2) {    node* result = NULL;
    
    if (mat1 && mat2) {
        double sum;
        node *rp1, *rp2, *dp1 = mat1, *dp2 = mat2;
        
        while (dp1) {
            rp1 = dp1;
            sum = 0;
            rp2 = dp2;
            while (rp1 && rp2) {
                sum += rp1->data * rp2->data;
                rp1 = rp1->right;
                rp2 = rp2->down;
            }
            
            node* newNode = (node*)malloc(sizeof(node));
            newNode->data = sum;
            newNode->right = NULL;
            newNode->down = NULL;
            
            if (!result) {
                result = newNode;
            } else {
                node* temp = result;
                while (temp->down) {
                    temp = temp->down;
                }
                temp->down = newNode;
            }
            
            dp1 = dp1->down;
        }
    }
    
    return result;
}
        


node* transpose(node* head) {    node* current = head;
    node* temp;

    // Swap the right and down pointers for each node
    while (current) {
        temp = current->right;
        current->right = current->down;
        current->down = temp;
        current = current->right;
    }

    return head;
}


    
double get(node* head) {    node* rowPtr = head;
    node* colPtr = NULL;
    double sum = 0.0;

    // Traverse rows
    while (rowPtr != NULL) {
        colPtr = rowPtr;

        // Traverse columns
        while (colPtr != NULL) {
            sum += colPtr->data; // Add the data to the sum

            // Move to the next column
            colPtr = colPtr->right;
        }

        // Move to the next row
        rowPtr = rowPtr->down;
    }

    return sum;
}


void display(node* head) {
    node *rp, *dp = head;

    while (dp) {
        rp = dp;       
        while (rp) {
            printf("%lf ",rp->data);
            rp = rp->right;
        }
        printf("\n");
        dp = dp->down;
    }
}

void matScalarProduct(node* h1, double scalar) {
    node *rp1, *dp1 = h1;
    
    while(dp1) {
        rp1 = dp1;
        while(rp1) {
            rp1->data = rp1->data * scalar;    
            rp1 = rp1->right;            
        }
        dp1 = dp1->down;        
    }
}


void matSum(node* h1, node* h2) {
    node *rp1, *rp2, *dp1 = h1, *dp2 = h2;
    
    while(dp1 && dp2) {
        rp1 = dp1;
        rp2 = dp2;
        while(rp1 && rp2) {
            rp1->data = rp1->data + rp2->data;    
            rp1 = rp1->right;
            rp2 = rp2->right;
        }
        dp1 = dp1->down;
        dp2 = dp2->down;
    }
}

void sectionFormula(double ratio, node* m1, node* m2) {
    matScalarProduct(m1, ratio);
    matSum(m1, m2);
    matScalarProduct(m1, 0.025);
}

node* constructLinkedMatrix(double** mat, int m, int n) {
    node* mainhead = NULL; 
    node* head[m];
    node *righttemp, *newptr;
 
    for (int i = 0; i < m; i++) { 
        head[i] = NULL;
        for (int j = 0; j < n; j++) {
            newptr = newNode(mat[i][j]); 
            if (!mainhead)
                mainhead = newptr; 
            if (!head[i])
                head[i] = newptr;
            else
                righttemp->right = newptr; 
            righttemp = newptr;
        }
    }
 
    for (int i = 0; i < m - 1; i++) { 
        node *temp1 = head[i], *temp2 = head[i + 1];
 
        while (temp1 && temp2) { 
            temp1->down = temp2;
            temp1 = temp1->right;
            temp2 = temp2->right;
        }
    } 
    return mainhead;
}

void createDatMat(char* filename, node* head) {
    FILE *fp = fopen(filename, "w");
    node *rp, *dp = head;
    
    while (dp) {
        rp = dp;       
        while (rp) {
            fprintf(fp, "%lf" ,rp->data);
            rp = rp->right;
        }
        fprintf(fp, "\n");
        dp = dp->down;
    }
}

void createDatsLengths(char *filename, double len) {
    FILE *fp = fopen(filename, "w");

    fprintf(fp, "%lf", len);
    fclose(fp);
}

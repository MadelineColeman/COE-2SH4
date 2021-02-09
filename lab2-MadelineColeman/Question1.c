#include <stdio.h>
#include <stdlib.h>

#include<math.h>
#include "Questions.h"

void add_vectors(double vector1[], double vector2[], double vector3[], int size) {
	int i = 0;
	for (i; i < size; i++) { //use loop to sum vector 1 and vector 2
		vector3[i] = vector1[i] + vector2[i];
	}
}

double scalar_prod(double vector1[], double vector2[], int size) {
	double prod = 0;
	int i = 0;
	for (i; i < size; i++) { //use loop to get the scalar product of vector 1 and 2
		prod = prod + vector1[i] * vector2[i];
	}

	// return the result
	return prod;
}

double norm2(double vector1[], int size) {
	double L2;
	L2 = sqrt(scalar_prod(vector1, vector1, size)); //use scalar_prod() to find scalar product then squareroot return to find normal
	return L2;
}

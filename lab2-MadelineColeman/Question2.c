#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"
#include "math.h"

int is_diag_dom(int mat[][N2]) {

	int isDiag = 0, i = 0, checkRow = 0;

	for (i; i < N2; i++) { //iterates through each row
		int j = 0, sum = 0;
		for (j; j < N2; j++) { //iterates through each column
			if (j != i) { //sums row values that are not diagonal entries
				sum += fabs(mat[i][j]);
			}
		}
		if (sum < fabs(mat[i][i])) { //checks diagonal entry is greater than sum of other values in row
			checkRow += 1;
		}
	}

	if (checkRow == N2) { // checks if all rows meet diagonal matrix criteria, sets isDiag to one if all do
		isDiag = 1;
	}

	return isDiag;
}

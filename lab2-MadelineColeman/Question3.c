#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"

void diag_scan(int mat[][N3], int arr[N3 * N3]) {

	int i = 0, col = 0, k = 1, row, arrPos = 0;
	for (i; i < N3; i++) { //iterates through upper half of matrix
		col = 0;
		for (col; col <= i; col++) {
			arr[arrPos] = mat[i - col][col];
			arrPos++;
		}
	}
	for (i = 1; i < N3; i++) { //iterates through lower half of matrix
		row = N3 - 1;
		col = i;
		for (k = i; k < N3; k++) {
			arr[arrPos] = mat[row][col];
			arrPos++;
			row--;
			col++;
		}
	}
}

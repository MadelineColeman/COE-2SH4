#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"

void efficient(const int source[], int val[], int pos[], int size) {
	int i = 0, arrPos = 0;
	for (i; i < size; i++) { //iterates through vector
		if (source[i] != 0) { //checks for non-zero entry and add them to val and pos arrays
			val[arrPos] = source[i];
			pos[arrPos] = i;
			arrPos++;
		}
	}
}

void reconstruct(int source[], int m, const int val[], const int pos[], int n) {
	int i = 0, j;
	for (i; i < m; i++) { //iterates through empty source list
		source[i] = 0; //initially set each source value to 0
		for (j = 0; j < n; j++) {
			if (i == pos[j]) { //checks if source at i should be non-zero
				source[i] = val[j]; //sets source at designated position to the correct value
			}
		}
	}

}

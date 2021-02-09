#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"

void addEff(int val1[], int val2[], int val3[], int pos1[], int pos2[],
		int pos3[], int k1, int k2) {

	int i = 0, j, arrPos = 0, smallest = 0;
	for (i; i < k1; i++) { //iterates through vector 1
		for (j = 0; j < k2; j++) {
			if ((pos1[i] == pos2[j])) { //checks vec1 and vec2 have values at same position
				smallest = 1;
				pos2[j] = -1;
				if (val1[i] + val2[j] != 0) { //adds vec1 and vec2 to vec 3 if the sum is not 0
					val3[arrPos] = val1[i] + val2[j];
					pos3[arrPos] = pos1[i];
					smallest = 1;
					pos2[j] = -1;
					arrPos++;
				}
			}
		}
		for (j = 0; j < k2; j++) { //checks if there is a smaller position value in vector 2
			if (pos2[j] < pos1[i] && pos2[j] != -1) {
				val3[arrPos] = val2[j];
				pos3[arrPos] = pos2[j];
				pos2[j] = -1;
				arrPos++;
			}
		}
		if (smallest == 0) { //sets vector 3 value to vector 1 value if vector 1 has the smallest position value
			val3[arrPos] = val1[i];
			pos3[arrPos] = pos1[i];
			arrPos++;
		}
		smallest = 0;
	}

	for (j = 0; j < k2; j++) {
		if (pos2[j] != -1) {
			val3[arrPos] = val2[j];
			pos3[arrPos] = pos2[j];
			pos2[j] = -1;
			arrPos++;
		}
	}

}

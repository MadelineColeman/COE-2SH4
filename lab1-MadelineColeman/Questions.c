#include "Questions.h"

int Q1_for() {
	int sum = 0, i;

	for (i = 30; i < 1001; i++) { //sums multiples of 4 between 30 and 1000 using for loop
		if (i % 4 == 0) {
			sum = sum + i;
		}
	}

	return sum;
}

int Q1_while() {

	int sum = 0, i = 30;
	while (i < 1001) { //sums multiples of 4 between 30 and 1000 using while loop
		if (i % 4 == 0) {
			sum = sum + i;
		}
		i++;
	}

	return sum;
}

int Q1_do() {

	int sum = 0, i = 30;
	do { //sums multiples of 4 between 30 and 1000 using do while loop
		if (i % 4 == 0) {
			sum = sum + i;

		}
		i++;
	} while (i < 1001);

	return sum;
}
//===============================================================================================
int Q2(int Q2_input) {

	int IsFiveDigit = 0, len = 0;

	//checks length of inputed number using modulus operation
	while (Q2_input != 0) {
		Q2_input /= 10;
		len++;
	}

	//sets IsFiveDigit to 1 if the length is 5
	if (len == 5) {
		IsFiveDigit = 1;
	}

	return IsFiveDigit;
}
//===============================================================================================
int Q3(float Q3_input) {
	float GPA;

	if (Q3_input <= 100 && Q3_input >= 90) { //checks if average is between 90 and 100 inclusive
		GPA = 4;
	} else if (Q3_input < 90 && Q3_input >= 80) { // checks if average is between 80 and 89 inclusive
		GPA = 3;
	} else if (Q3_input < 80 && Q3_input >= 70) { // checks if average is between 70 and 79 inclusive
		GPA = 2;
	} else if (Q3_input < 70 && Q3_input >= 60) { // checks if average is between 60 and 69 inclusive
		GPA = 1;
	} else if (Q3_input < 60 && Q3_input >= 0) { // checks if average is between 0 and 59 inclusive
		GPA = 0;
	} else { // sets GPA to -1 if average is outside of range 0-100
		GPA = -1;
	}
	return GPA;
}
//===============================================================================================
double Q4(int Q4_input) {

	double pi = 0, denom = 1;
	int i = 1;

	while (i <= Q4_input) {
		if (i % 2 == 1) { //checks if i is odd and adds appropriate term
			pi = pi + 4 / denom;
			denom += 2;
			i++;
		} else { //runs if i is even and subtracts appropriate term
			pi = pi - 4 / denom;
			denom += 2;
			i++;
		}
	}
	return pi;
}
//===============================================================================================
int Q5() {

	int totNumTriples = 0, s1, s2, hyp;

	//nested loops iterate through all combinations of s1, s1, and hyp
	for (s2 = 1; s2 < 401; s2++) {
		for (s1 = 1; s1 < 401; s1++) {
			for (hyp = 1; hyp < 401; hyp++) {
				if (s1 <= s2) { //checks if side 1 <= side 2
					if (s1 * s1 + s2 * s2 == hyp * hyp) { //checks if combination of numbers are triple
						totNumTriples++;
					}
				}
			}
		}
	}
	return totNumTriples;
}
//===============================================================================================
int Q6(int Q6_input, int perfect[]) {

	int counts = 0, i;

	for (i = 1; i <= Q6_input; i++) {
		int arrLen = 0, factors[i], j = 1, k = 0, sum = 0;
		for (j = 1; j < i; j++) { //finds factors of i and puts them in array called factors
			if (i % j == 0) {
				factors[arrLen] = j;
				arrLen++;
			}
		}
		for (k = 0; k < arrLen; k++) { //sums the factors of each i
			sum += factors[k];

		}
		if (sum == i) { //checks if sum of factors is equal to i
			perfect[counts] = i;
			counts++;
		}
	}
	return counts;
}

//===============================================================================================
int Q7a(int Q7_input) {

	int reversedInt = 0, rem;

	while (Q7_input != 0) { // iterates though all digits of input
		rem = Q7_input % 10; //grabs last digit of number
		reversedInt = reversedInt * 10 + rem; //reverses number
		Q7_input /= 10; // strips number of last digit
	}
	return reversedInt;

}
int Q7b(int Q7b_input) {

	int reversedInt = 0, rem;

	while (Q7b_input != 0) { // iterates though all digits of input
		rem = Q7b_input % 10; //grabs last digit of number
		reversedInt = reversedInt * 10 + rem; //reverses number
		Q7b_input /= 10; // strips number of last digit
	}
	return reversedInt;
}

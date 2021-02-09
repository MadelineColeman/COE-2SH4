#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"

void letter_freq(const char word[], int freq[]) {
	int c, low = 97, up = 65;
	for (low, up; low <= 122; low++, up++) { //checks for each letter
		c = 0;
		while (word[c] != '\0') { //iterates through inputed word
			if (word[c] == low) { //counts lower case letters
				freq[low - 97] = freq[low - 97] + 1;
			} else if (word[c] == up) { //counts upper case letters
				freq[low - 97] = freq[low - 97] + 1;
			}
			c++;
		}
	}

}

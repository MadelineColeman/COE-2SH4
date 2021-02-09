#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"

void string_copy(const char source[], char destination[], int n) {
	int i = 0;
	for (i; i < n - 1; i++) { //iterates through source and copies source to destination
		destination[i] = source[i];
	}
	destination[i] = '\0';
}

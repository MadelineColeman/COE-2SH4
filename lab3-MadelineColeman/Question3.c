#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"

char** read_words(const char *input_filename, int *nPtr) {

	FILE *input = fopen(input_filename, "r");
	fscanf(input, "%d", nPtr);

	char **word_list;
	word_list = calloc(*nPtr, sizeof(char*));

	int i = 0;

	for (i; i < *nPtr; i++) {
		fscanf(input, "%ms", word_list[i]);
	}
	fclose(input);
	return word_list;

}

int compare_str(const char *str1, const char *str2) {

	while (*str1 && *str1 == *str2) {
		str1++;
		str2++;
	}

	return *(const unsigned char*) str1 > *(const unsigned char*) str2;

}

void sort_words(char **words, int size) {
/*
	int i, j;
	char *tempChar = malloc(sizeof(char*));
	for (i = 1; i < size; i++) {
		tempChar = words[i];
		for (j = i; j > 0 && compare_str(words[j - 1], tempChar); j--){
			words[j] = words[j - 1];
		}
		words[j] = tempChar;
	}*/
}

void swap(char **str1, char **str2) {

}

void sort2_words(char **words, int size) {

}


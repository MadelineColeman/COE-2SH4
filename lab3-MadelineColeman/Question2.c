#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int ID;
	char firstName[15];
	char lastName[15];
	int grade1;
	int grade2;
	float finalGrade;
} student;

student** create_class_list(char *filename, int *sizePtr) {

	FILE *studentClass = fopen(filename, "r"); //open input file
	fscanf(studentClass, "%d", sizePtr);

	student **class_list;
	class_list = malloc(*sizePtr * sizeof(student));
	int i;

	for (i = 0; i < *sizePtr; i++) { //scan all rows of input file for id, first names, and last names
		student *t = calloc(1, sizeof(student));
		fscanf(studentClass, "%d", &t->ID);
		fscanf(studentClass, "%s", &t->firstName);
		fscanf(studentClass, "%s", &t->lastName);
		class_list[i] = t;
	}

	fclose(studentClass);

	return class_list;
}

int find(int idNo, student **list, int size) {
	int i;

	for (i = 0; i < size; i++) { //iterate through list
		if (list[i]->ID == idNo) { //check if current list value equals inputed id number
			return i;
		}
	}
	return -1;
}

void input_grades(char *filename, student **list, int size) {
	FILE *grades = fopen(filename, "r");
	int i, j = 0, id;

	for (i = 0; i < size; i++) { //iterate through list
		fscanf(grades, "%d", &id); //grabs id number
		j = find(id, list, size);
		fscanf(grades, "%d%d", &(list[j]->grade1), &(list[j]->grade2)); //scans grades and adds them to list
	}
	fclose(grades);
}

void compute_final_course_grades(student **list, int size) {
	int i;
	for (i = 0; i < size; i++) {
		list[i]->finalGrade = (list[i]->grade1 + list[i]->grade2) / 2.0; //calculates average of two project grades
	}

}

void output_final_course_grades(char *filename, student **list, int size) {
	FILE *output = fopen(filename, "w");
	fprintf(output, "%d\n", size);

	int i;

	for (i = 0; i < size; i++) { //iterates through list of inputed students
		fprintf(output, "%d %f\n", list[i]->ID, list[i]->finalGrade); //outputs id and final grade for each student to file
	}
	fclose(output);

}

void withdraw(int idNo, student **list, int *sizePtr) {
	int i, j;
	i = find(idNo, list, *sizePtr);//uses find to get location of withdraw student
	if (i != *sizePtr - 1 && i != -1) {//checks if student in list and checks if student is last in list
		for (j = i + 1; j < *sizePtr; j++) {//puts student at back of list
			list[j - 1] = list[j];
		}
		*sizePtr = *sizePtr - 1;
		free(&list[*sizePtr]);//removes student from list
	}

}

void destroy_list(student **list, int *sizePtr) {
	/*	int i = 0;
	 * for (i; i < *sizePtr; i++) {
	 * free(list[i]); //deallocates memory for each element in list}*/
	free(list);//free list memory
	*sizePtr = 0;
}


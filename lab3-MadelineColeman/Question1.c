#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"

char* my_strcat(const char *const str1, const char *const str2) {
    int len, i;
    len = strlen(str1) + strlen(str2) + 1; //get length of inputed stings combined
    char *z;
    z = (char *) malloc(i=len*sizeof(char));
    z[len-1] = '\0';
    for(i = 0;i<strlen(str1);i++){//add string 1 to string z
        z[i] = str1[i];
    }
    for(i;i<(strlen(str2)+strlen(str1));i++){//add string 2 to string z
        z[i] = str2[i-strlen(str1)];
    }

	return z;

}

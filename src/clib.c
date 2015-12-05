/*
 * clib.c
 *
 *  Created on: 23-Nov-2015
 *  Author    : Rugved Dhuri
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/clib.h"

char *passGen(int length) {
	int character, i = 0;
	time_t t;
	char *newPass = NULL;

	if (length <= MAX && length >= MIN) {
		newPass = (char *) malloc(sizeof(char) * length);

		/* Initializes random number generator */
		srand((unsigned) time(&t));

		while (i < length) {
			character = rand() % 125;

			/* Character 0-9 */
			if (character >= 48 && character <= 57) {
				newPass[i++] = (char) character;
			}
			/* Character A-Z */
			if (character >= 65 && character <= 90) {
				newPass[i++] = (char) character;
			}
			/* Character a-z */
			if (character >= 97 && character <= 122) {
				newPass[i++] = (char) character;
			}
		}
		newPass[i] = '\0';
	}
	else {
		/* Print Errors */

		if(length > MAX) {
			fprintf(stderr, "Invalid Input! Maximum length is %d\n", MAX);
		}

		if(length < MAX) {
			fprintf(stderr, "Invalid Input! Minimum length is %d\n", MIN);
		}
	}

	return newPass;
}

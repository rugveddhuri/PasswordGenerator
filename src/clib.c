/*
 * clib.c
 *
 *  Created on: 23-Nov-2015
 *  Author    : Rugved Dhuri
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/clib.h"

char *passGen(int length, bool specialCharacters) {
	int character,
	    counter = 0;
	static time_t tm = NULL;
	char *newPass = NULL;

	if (length <= MAX && length >= MIN) {
		newPass = (char *) malloc(sizeof(char) * (length + 1));

		/* Initializes random number generator */
		if(tm == NULL)
			time(&tm);
		srand((unsigned) tm++);

		while (counter < length) {
			character = rand() % 125;

			/* Special Characters */
			if(specialCharacters == true) {
				/* Character !-. */
				if (character >= 33 && character <= 46) {
					newPass[counter++] = (char) character;
				}
				/* Character :-@ */
				if (character >= 58 && character <= 64) {
					newPass[counter++] = (char) character;
				}
			}

			/* Character 0-9 */
			if (character >= 48 && character <= 57) {
				newPass[counter++] = (char) character;
			}
			/* Character A-Z */
			if (character >= 65 && character <= 90) {
				newPass[counter++] = (char) character;
			}
			/* Character a-z */
			if (character >= 97 && character <= 122) {
				newPass[counter++] = (char) character;
			}
		}
		newPass[counter] = '\0';
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

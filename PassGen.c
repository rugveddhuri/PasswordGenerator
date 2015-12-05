/**
 * Title : Password Generator
 * Author: Rugved Dhuri
 * Date  : 23 Oct 2015
 * Description: Password Generator Program Command Line
 */

#include <stdio.h>
#include <string.h>
#include "include/clib.h"

int main(int argc, char *argv[]) {
    int length;
    char spCharacter;
    char *pass = NULL;

    int counter = 1;
    int requiredParameter = 0;

    /* Switches */
    bool specialCharacters = false;

    if(argc > 1) {
    	requiredParameter = 1;
        while (counter < argc) {

        	if(strcmp("-s", argv[counter]) == 0) {
        		specialCharacters = true;
        	} else {
        		if(requiredParameter == 0) {
        			fprintf(stderr, "Multiple Lengths Entered\n");
        		}
        		else {
        			length = atoi(argv[counter]);
        			requiredParameter = 0;
        		}
        	}
        	counter++;
        }
    }else {
    	// Ask Password Length
        printf("Enter Password Length: ");
        scanf("%d",&length);

        // Ask for Special Characters in Password
        printf("Do you want Special Characters to be included? Y/N:");
        scanf("%c",&spCharacter);
        scanf("%c",&spCharacter);

        if(spCharacter == 'Y' || spCharacter == 'y') {
        	specialCharacters = true;
        }
    }

    if(requiredParameter == 1) {
    	fprintf(stderr, "Length Required!\n");
    }
    else {
    	pass = passGen(length, specialCharacters);
    }

    // Generate Random Password
    // Debug Information
    /*printf("--------------------------\n");
    printf("> Length : %d\n",length);
    printf("> SP Char: %d\n",specialCharacters);*/

//    printf("--------------------------\n");

    if(pass == NULL) {
    	fprintf(stderr, "Failed to Generate Password!");
    } else {
    	printf("Password is: %s", pass);
    }

    return EXIT_SUCCESS;
}

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
    int length = 0, pass_count = 0;
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
        	}
        	else if(strcmp("-n", argv[counter]) == 0) {
        		pass_count = atoi(argv[++counter]);
        	}
        	else {
        		if(requiredParameter == 0) {
        			fprintf(stderr, "Invalid Options Entered \"%s\"\n", argv[counter]);
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

        // Ask number of Passwords to generate
        printf("Enter No. of Passwords to generate: ");
		scanf("%d", &pass_count);

        // Ask for Special Characters in Password
        printf("Do you want Special Characters to be included? Y/N:");
        scanf("%c",&spCharacter);
        scanf("%c",&spCharacter);

        if(spCharacter == 'Y' || spCharacter == 'y') {
        	specialCharacters = true;
        }

    }
    //return 0;
    if(requiredParameter == 1 || length <= 0) {
    	fprintf(stderr, "Length Required!\n");
    }
    else {
    	requiredParameter = 0;
    	if(pass_count <= 0) {
    		printf("Password is\n");
    		pass = passGen(length, specialCharacters);
    		if(pass == NULL)
    			requiredParameter++;
    		else
    			printf("%s\n",pass);
    	}
    	else {
    		printf("Passwords are\n");
    		for(counter = 0; counter < pass_count; counter++) {
				pass = passGen(length, specialCharacters);
				if(pass == NULL)
					requiredParameter++;
				else
					printf("%s\n",pass);
			}
    	}
    }

    if(length <= 0) {
    	fprintf(stderr, "Failed to Generate %d Password!", pass_count<=0?1:pass_count);
    }
    if(requiredParameter > 0) {
    	fprintf(stderr, "Failed to Generate %d Password!", requiredParameter);
    }

    return EXIT_SUCCESS;
}

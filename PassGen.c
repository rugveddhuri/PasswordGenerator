/**
 * Title : Password Generator
 * Author: Rugved Dhuri
 * Date  : 23 Oct 2015
 * Description: Password Generator Program Command Line
 */

#include <stdio.h>
#include "include/clib.h"

int main(int argc, char *argv[]) {
    int length;
    char *pass;

    if(argc > 1) {
        length = atoi(argv[1]);
    }else {
        printf("Enter Password Length: ");
        scanf("%d",&length);
    }

    pass = passGen(length);

    if(pass == NULL) {
    	fprintf(stderr, "Invalid Input!");
    } else {
    	printf("Password is: %s", pass);
    }

    return EXIT_SUCCESS;
}

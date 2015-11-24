#ifndef PROTOTYPES_H_INCLUDED
#define PROTOTYPES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    // Arguments Functions

unsigned int ArgumentsControl (int, char**);
int CheckOption(char*);

    // File Functions

void FreeFiles (FILE*, FILE*);
FILE* ChargeFile (char*);

	// Difference Functions
	
int	find_difference(FILE* fd_src, FILE* fd_dest);


#endif // PROTOTYPES_H_INCLUDED

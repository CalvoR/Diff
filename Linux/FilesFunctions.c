#include <stdio.h>
#include <stdlib.h>


// Charge the file whose the path is sent in parametres

FILE* ChargeFile (char* filePath)
{
    FILE* newFile = fopen(filePath, "r");

    if (newFile == NULL)
        printf("Error in the file loading\n");

    return newFile;
}



//  Free the two pointers on files

void FreeFiles (FILE* file1, FILE* file2)
{
    free(file1);
    free(file2);
}

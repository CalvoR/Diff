/*
    SCARPELLINI Xavier
    CALVO Robert
    MEZELLE Clément

    Projet de langage C
*/

#include <stdio.h>
#include <stdlib.h>

#include "Prototypes.h"



int main(int argc, char** argv)
{
    if (!ArgumentsControl (argc, argv))
        return 0;

    FILE* fileSrc = ChargeFile(argv[1]);           // pointeur sur le premier fichier, source de la comparaison
    FILE* fileCmp = ChargeFile(argv[2]);           // pointeur sur le second fichier, comparatif du fichier source

    if (fileSrc == NULL  ||  fileCmp == NULL )
        return 0;

    char* lineSrc, *lineDest;


    ////
    ////


    FreeFiles(fileSrc, fileCmp);

    return 0;
}

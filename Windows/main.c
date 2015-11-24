/*
    SCARPELLINI Xavier
    CALVO Robert
    MEZELLE Clément

    Projet de langage C
*/



#include "Prototypes.h"



int main(int argc, char** argv)
{
    int cursor = 1; // index of the current argument

    if (!ArgumentsControl (argc, argv)) /** /!\ la deuxieme partie de la fonction démarre à partir du 3eme arguments au lieu de s'arreter 2 argument avant la fin **/
        return 0;
/*
    FILE* fileSrc = ChargeFile(argv[1]);           // pointeur sur le premier fichier, source de la comparaison
    FILE* fileCmp = ChargeFile(argv[2]);           // pointeur sur le second fichier, comparatif du fichier source

    if (fileSrc == NULL  ||  fileCmp == NULL )
        return 0;
*/
    void *fonctionList[] = {}; /** ajouter le nom de la fonction à l'index correspondant dans le tableau des options **/

    while(cursor < argc-2){
        if(argv[cursor][0] == '-'){
            fonctionList[CheckOption(argv[cursor])](argv[1], argv[2], argv[cursor], argv[cursor+1], argv[cursor+2]); /** le nombre d'argument de cette fonction peut changer **/

            /** creer un appel direct à la focntion via le tableau de pointeur de fonction + verifie le nombre d'argument à envoyer**/
        }
        cursor++;
    }


    ////
    ////


//    FreeFiles(fileSrc, fileCmp);

    return 0;
}

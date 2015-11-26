#include "Prototypes.h"

// control on the number and the "-" of each argument



int CheckOption(char* option){
    int i;
    char* listStringOptions[] = {"--normal","--brief","--report-identical-files","--context","--unified","--ed","--rcs","--side-by-side","--width-","--left-colunm","--suppress-common-lines","--show-c-function","--show-function-line-RE","--label","--expand-tabs","--initial-tab","--tabsize-","--suppress-blank-empty","--paginate","--recusive","--nex-file","--unidurectional-new-file","--ignore-file-name-case","--no-ignore-file-name-case","--exclude-PAT","--exclude-from-FILE","--starting-file-FILE","--from-file-FILE1","--to-file-FILE2","--ignore-case","--ignore-tab-expansion","--ignore-trailing-space","--ignore-space-change","--ignore-all--space","--ignore-blank-lines","--ignore-matching-lines-RE","--text","--strip-trailing-cr","--ifdef-NAME","--GTYPE-group-format-GFMT","--line-format-LFMT","--LTYPE-line-format-LFMT","--minimal","--horizon-lines-NUM","--speed-large-files","--help","--version"};

    char* listCharOptions[] = {"","-q","-s","-c","-u","-e","-n","-y","-W","","","-p","-F","","-t","-T","","","-l","-r","-N","","","","-x","-X","-S","","","-i","-E","-Z","-b","-w","-B","-I","-a","","-D","","","","-d","","","","-v"};

    //listFunction[]// creer un tableau de pointeurs de fonctions

    if(option[1] == '-'){
        for(i = 0; i<sizeof(listStringOptions)/4; i++){
            if(strcmp(option, listStringOptions[i]) == 0){
                strcpy(option, "-string"); /** supprimer cette ligne **/
                return i;
            }
        }
    }else{
        for(i = 0; i<sizeof(listCharOptions)/4; i++){
            if(strcmp(option, listCharOptions[i]) == 0){
                strcpy(option, "-c"); /** supprimer cette ligne **/
                return i;
            }
        }
    }
    return -1;
}

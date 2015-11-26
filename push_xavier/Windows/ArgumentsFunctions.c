#include "Prototypes.h"

// control on the number the nature of an argument and return the index of the function that is corresponding into the pointer function table

int check_option(char* option)
{
    int i;
    char* list_string_options[] = {"--normal","--brief","--report-identical-files","--context","--unified","--ed","--rcs","--side-by-side","--width-","--left-colunm","--suppress-common-lines","--show-c-function","--show-function-line-RE","--label","--expand-tabs","--initial-tab","--tabsize-","--suppress-blank-empty","--paginate","--recusive","--nex-file","--unidurectional-new-file","--ignore-file-name-case","--no-ignore-file-name-case","--exclude-PAT","--exclude-from-FILE","--starting-file-FILE","--from-file-FILE1","--to-file-FILE2","--ignore-case","--ignore-tab-expansion","--ignore-trailing-space","--ignore-space-change","--ignore-all--space","--ignore-blank-lines","--ignore-matching-lines-RE","--text","--strip-trailing-cr","--ifdef-NAME","--GTYPE-group-format-GFMT","--line-format-LFMT","--LTYPE-line-format-LFMT","--minimal","--horizon-lines-NUM","--speed-large-files","--help","--version"};

    char* list_char_options[] = {"","-q","-s","-c","-u","-e","-n","-y","-W","","","-p","-F","","-t","-T","","","-l","-r","-N","","","","-x","-X","-S","","","-i","-E","-Z","-b","-w","-B","-I","-a","","-D","","","","-d","","","","-v"};

    if(option[1] == '-'){
        for(i = 0; i<sizeof(list_string_options)/4; i++){
            if(strcmp(option, list_string_options[i]) == 0){ //check if the argument is got an associated option
                return i;
            }
        }
    }else{
        for(i = 0; i<sizeof(list_char_options)/4; i++){
            if(strcmp(option, list_char_options[i]) == 0){ //check if the argument is got an associated option
                return i;
            }
        }
    }
    return -1;
}

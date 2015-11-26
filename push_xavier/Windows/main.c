#include "Prototypes.h"



void help()
{
    printf("Help");
}


int main (int argc, char** argv)
{
	t_env  env;        // structure of specifics about the current environment of execution (including file details)
	t_difference  diff;   // linked-list that contains details about each difference that was found

    int cursor = 1;         // index of the current argument

	if (argc < 3) {
		printf("Il n'y a pas assez d'argument.\n");
		return 0;
	}

	if (init_struct_env(&env, argc, argv) == -1)    {
		printf("Erreur d'initialisation de la structure.\n");
		return -1;
	}
	init_struct_diff(&diff);

    void (* fonctionList[NB_OPTIONS])(t_difference, t_env); // this contains a list of the function's names corresponding with table of the options

	if (env.nbr_option == 0) // case of classic
	{
		if (find_difference(&diff, &env) == -2)
			printf("Pas de difference\n");
	}
	else
    {
        while(cursor < argc-2){
            if(argv[cursor][0] == '-'){
                fonctionList[check_option(argv[cursor])](diff, env);
            }   // this creates a direct call to the function through the table of function pointers + checks the number of argument to send
            cursor++;
        }
    }

	result(&diff);
	close_file(&env);
	return 0;
}

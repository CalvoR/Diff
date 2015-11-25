#include "Prototypes.h"



void help()
{
    printf("Help");
}


int main (int argc, char** argv)
{
	t_env		env;
	t_difference	diff;

    int cursor = 1; // index of the current argument

	if (argc < 3) {
		printf("pas assez d'argument\n");
		return 0;
	}

	if (init_struct_env(&env, argc, argv) == -1)    {
		printf("erreur initialisation structure\n");
		return -1;
	}
	init_struct_diff(&diff);

    void *fonctionList[NB_OPTIONS] = {help}; /** ajouter le nom de la fonction à l'index correspondant dans le tableau des options **/

    while(cursor < argc-2){
        if(argv[cursor][0] == '-'){
            fonctionList[CheckOption(argv[cursor])](diff, env); /** le nombre d'argument de cette fonction peut changer **/

            /** creer un appel direct à la focntion via le tableau de pointeur de fonction + verifie le nombre d'argument à envoyer**/
        }
        cursor++;
    }

	if (env.nbr_option == 0)
	{
		if (find_difference(&diff, &env) == -2)
			printf("Pas de difference\n");
	}
	result(&diff);
	close_file(&env);
	return 0;
}

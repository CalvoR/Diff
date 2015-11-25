#include "Prototypes.h"


// Charge the file whose the path is sent in parametres

int	open_file(t_env* env)
{

	env->fd_file1 = fopen(env->name_file1, "r");
	env->fd_file2 = fopen(env->name_file2, "r");
	if (env->fd_file1 == NULL || env->fd_file2 == NULL)
	{

		printf("erreur lecture de fichier\n");
		return -1;
	}
	return 0;
}

void close_file(t_env* env)
{
	fclose(env->fd_file1);
	fclose(env->fd_file2);
}

#include "Structure.h"
#include "find_difference.h"



int	cmpt_line(FILE* file)
{
	int	c = 0;
	int	nb_line = 0;

	while ((c = fgetc(file)) != EOF)
	{
		if (c == '\n')
			nb_line++;
	}
	return nb_line;
}

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

void	close_file(t_env* env)
{
	fclose(env->fd_file1);
	fclose(env->fd_file2);
}

int	init_struct_env(t_env* env, int argc, char** argv)
{

	env->name_file2 = argv[argc-1];
	env->name_file1 = argv[argc-2]; 
	if (open_file(env) == -1)
		return -1;

	env->nbr_line_file1 = cmpt_line(env->fd_file1);
	env->nbr_line_file2 = cmpt_line(env->fd_file2);
	close_file(env);
	env->nbr_option = argc - 3;
	return 0;
}

int main (int argc, char** argv)
{
	int	err = 0;
	t_env	env;


	if (argc < 3)
	{
		printf("pas assez d'argument\n");
		return 0;
	}
	err = init_struct_env(&env, argc, argv);
	return err;
}

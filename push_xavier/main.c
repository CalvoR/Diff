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

void	init_struct_diff(t_difference* diff)
{
	diff->line_file1 = NULL;
	diff->line_file2 = NULL;
	diff->num_line = 0;
	diff->state = '\0';
	diff->next = NULL;
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
	if (open_file(env) == -1)
		return -1;

	env->nbr_option = argc - 3;
	return 0;
}

void result(t_difference* diff)
{
	while (diff->next != NULL)
	{
		if (diff->state != '\0')
		{
			printf("%d%c%d\n", diff->num_line+1, diff->state, diff->num_line+1);
			if (diff->line_file1 != NULL)
				printf("< %s", diff->line_file1);
			printf("---\n");
			if (diff->line_file2 != NULL)
				printf("> %s", diff->line_file2);
		}
		diff = diff->next;
	}
	Delete_all_list(diff);
}

int main (int argc, char** argv)
{
	t_env		env;
	t_difference	diff;


	if (argc < 3)
	{
		printf("pas assez d'argument\n");
		return 0;
	}
	if (init_struct_env(&env, argc, argv) == -1)
	{
		printf("erreur initialisation structure\n");
		return -1;
	}
	init_struct_diff(&diff);
	if (env.nbr_option != 0)
	{
		if (find_difference(&diff, &env) == -2)
			printf("Pas de difference\n");
	}
	result(&diff);
	close_file(&env);
	return 0;
}

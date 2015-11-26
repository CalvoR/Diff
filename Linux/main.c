#include "find_difference.h"


int	my_strcmp(char* str1, char* str2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	
	while (str1[i] != '\0')
		i++;
	while (str2[j] != '\0')
		j++;
	if (i > j)
		return 1;
	else if (i < j)
		return -1;
	else
		return 0;
}

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
	env->count_diff_file1 = 1;
	env->count_diff_file2 = 1;
	env->count_diff_begin = 1;
	env->i = false;
	env->w = false;
	env->E = false;
	return 0;
}

void result_line(t_difference* diff, t_env* env)
{

	if (env->count_diff_begin == env->count_diff_file1 && env->count_diff_begin == env->count_diff_file2)
		printf("%d%c%d\n", diff->num_line+1, diff->state, diff->num_line+1);
	else if (env->count_diff_begin != env->count_diff_file1 && env->count_diff_begin == env->count_diff_file2)
		printf("%d, %d%c%d\n", env->count_diff_begin, env->count_diff_file1, diff->state, env->count_diff_file2);
	else if (env->count_diff_begin == env->count_diff_file1 && env->count_diff_begin != env->count_diff_file2)
		printf("%d%c%d, %d\n", env->count_diff_file1, diff->state, env->count_diff_begin, env->count_diff_file2);
	else
		printf("%d, %d%c%d, %d\n", env->count_diff_begin, env->count_diff_file1, diff->state, env->count_diff_begin, env->count_diff_file2);
}

void result_line_file1(t_difference* diff)
{

	while (diff->next != NULL)
	{
		if (diff->state != '\0')
		{
			if (diff->line_file1 != NULL)
				printf("< %s", diff->line_file1);
		}
		diff = diff->next;
	}
}

void result_line_file2(t_difference* diff)
{
	while (diff->next != NULL)
	{
		if (diff->state != '\0')
		{
			if (diff->line_file2 != NULL)
				printf("> %s", diff->line_file2);
		}
		diff = diff->next;
	}

}

void result(t_difference* diff, t_env* env )
{
	result_line(diff, env);
	result_line_file1(diff);
	printf("---\n");
	result_line_file2(diff);
	Delete_list(diff);
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
	
	if (env.nbr_option == 0)
	{
		if (find_difference(&diff, &env) == -2)
		{
			printf("Pas de difference\n");
			return -2;
		}
	}
	else
	{
		if (my_strcmp(argv[1],"-w") == 0)
			env.w = true;
		if (my_strcmp(argv[1],"-i") == 0)
			env.i = true;
		if (my_strcmp(argv[1],"-E") == 0)
			env.E = true;
		if (find_difference(&diff, &env) == -2)
		{
			printf("Pas de difference\n");
			return -2;
		}
	}
	result(&diff, &env);
	close_file(&env);
	return 0;
}

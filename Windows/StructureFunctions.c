#include "Prototypes.h"


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
	delete_list(diff);
}


#include "Prototypes.h"


void init_struct_diff(t_difference* diff)
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
		diff = (t_difference*) diff->next;
	}
	Delete_all_list(diff);
}


#include "Prototypes.h"


t_difference* add_list(t_difference* diff)
{
	t_difference* tmp;
	while (diff->next != NULL)  {
		diff = diff->next;
	}
	/*diff->next*/tmp = (t_difference*)malloc(sizeof(t_difference));

	tmp->line_file1 = NULL;
	tmp->line_file2 = NULL;
	tmp->num_line = 0;
	tmp->state = '\0';
	tmp->next = NULL;
	diff->next = tmp;
	return diff;
}

void  delete_list(t_difference* diff)
{
	if (!diff)
	{
		t_difference*	diff_tmp;
		t_difference*	diff_save;
		diff_save = diff->next;
		while (diff->next != NULL)
		{
			diff_tmp = diff;
			free(diff_tmp);
			diff = diff_save;
			diff_save = diff->next;
		}
	}
}

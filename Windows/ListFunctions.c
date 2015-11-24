#include "Prototypes.h"

t_difference* Add_list(t_difference* diff)
{
	while (diff->next != NULL)
	{
		diff = diff->next;
	}
	diff->next = malloc(sizeof(t_difference));
	diff = diff->next;
	diff->line_file1 = NULL;
	diff->line_file2 = NULL;
	diff->num_line = 0;
	diff->state = '\0';
	diff->next = NULL;
	return diff;
}

void Delete_all_list(t_difference* diff)
{
	t_difference*	diff_tmp;
	while (diff->next != NULL)
	{
		diff_tmp = diff->next;
		free(diff);
		diff = diff_tmp;
	}
}

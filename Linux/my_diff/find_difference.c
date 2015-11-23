#include "find_difference.h"

int  compare(char* str1, char* str2)
{
	int i = 0;

	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return i;
		}
		i++;
	}
	return -2;
}

int find_difference(t_difference* diff, t_env* env)
{
	ssize_t read;
	ssize_t read2;
	size_t len = 0;
	size_t len2 = 0;
	int i = 0;
	int count = 0;

	while (count < env->nbr_line_file1 || count < env->nbr_line_file2)
	{
		diff->num_line = count;
		if (count < env->nbr_line_file1)
			read = getline(&diff->line_file1, &len, env->fd_file1);
		else
			diff->line_file1 = "\0";
		if (count < env->nbr_line_file2)
			read2 = getline(&diff->line_file2, &len2, env->fd_file2); 
		else
			diff->line_file2 = "\0";
		i = compare(diff->line_file1, diff->line_file2);
		if (i >= 0)
		{
			diff->state = 'c';
			diff = Add_list(diff);
			while (diff->next != NULL)
			{
				diff = diff->next;
			}
		}
		count++;
		len = 0;
		len2 = 0;
	}
	return i;
}


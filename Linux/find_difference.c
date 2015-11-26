#include "find_difference.h"

char* ignore_tab(char* str)
{

	int	i;
	int	j;
	int	count_tab;
	char*	new_str;

	i = 0;
	j = 0;
	count_tab = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '\t')
			count_tab++;
		i++;
	}
	i = i - count_tab;
	new_str = (char*) malloc(i * sizeof(char*));
	i = 0;
	while(str[i] != '\0')
	{
		while(str[i] == '\t')
			i++;
		new_str[j] = str[i];
		j++;
		i++;
	}
	free(str);
	return new_str;
}

char* ignore_space(char* str)
{
	int	i;
	int	j;
	char*	new_str;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			j++;
		i++;
	}
	i = i - j;
	new_str = (char*) malloc(i * sizeof(char*));
	i = 0;
	j = 0;
	while(str[i] != '\0')
	{
		while(str[i] == ' ')
			i++;
		new_str[j] = str[i];
		j++;
		i++;
	}
	free(str);
	return new_str;
}

int  compare(char* str1, char* str2, t_env* env)
{
	int i = 0;
	if (str1 == NULL || str2 == NULL)
		return 0;
	if (env->w)
	{
		str1 = ignore_space(str1);
		str2 = ignore_space(str2);
	}
	if (env->E)
	{
		str1 = ignore_tab(str1);
		str2 = ignore_tab(str2);
		
	}
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (env->i && str1[i] >= 65 && str1[i] <= 90)
			str1[i] = str1[i] + 32;
		if (env->i && str2[i] >= 65 && str2[i] <= 90)
			str2[i] = str2[i] + 32;
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
	bool same = false;
	bool first = true;

	while (count < env->nbr_line_file1 || count < env->nbr_line_file2)
	{
		diff->num_line = count;
		if (count < env->nbr_line_file1)
			read = getline(&diff->line_file1, &len, env->fd_file1);
		else
			diff->line_file1 = NULL;
		if (count < env->nbr_line_file2)
			read2 = getline(&diff->line_file2, &len2, env->fd_file2); 
		else
			diff->line_file2 = NULL;
		i = compare(diff->line_file1, diff->line_file2, env);
		if (i >= 0)
		{
			if (first)
			{
				first = false;
				env->count_diff_begin = count + 1;
			}
			if (diff->line_file1 != NULL)
				env->count_diff_file1++;
			if (diff->line_file2 != NULL)
				env->count_diff_file2++;
			diff->state = 'c';
			diff = Add_list(diff);
			while (diff->next != NULL)
			{
				diff = diff->next;
			}
			same = true;
		}
		count++;
		len = 0;
		len2 = 0;
	}
	if (same)
	{
		if (i == -2)
			i = 0;
	}
	if (env->count_diff_file1 < env->count_diff_begin)
		env->count_diff_file1 = env->count_diff_begin;
	if (env->count_diff_file2 < env->count_diff_begin)
		env->count_diff_file2 = env->count_diff_begin;
	return i;
}


#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef enum e_bool {false = 0, true = 1} bool;

typedef struct s_env
{
	char*	name_file1;
	char*	name_file2;
	FILE*	fd_file1;
	FILE*	fd_file2;
	int	nbr_line_file1;
	int	nbr_line_file2;
	int	count_diff_file1;
	int	count_diff_file2;
	int	count_diff_begin;
	int	nbr_option;
	bool	w;
	bool	i;
	bool	E;
}	t_env;

typedef struct s_difference   
{

	char*			line_file1;
	char*			line_file2;
	int			num_line;
	char			state;
	struct s_difference*	next;

} t_difference;


#endif // STRUCTURE_H_INCLUDED

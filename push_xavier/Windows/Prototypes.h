#ifndef PROTOTYPES_H_INCLUDED
#define PROTOTYPES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Structure.h"

#define NB_OPTIONS 46

    // Arguments Functions

int check_option(char* option);

    // File Functions

int	open_file(t_env*);
void close_file(t_env*);

	// Difference Functions

ssize_t getline (char**, size_t*, FILE*);
int compare(char*, char*);
int	cmpt_line(FILE*);
int	find_difference(t_difference*, t_env*);

	// List functions

t_difference* add_list(t_difference*);
void delete_list(t_difference*);

    // Structure Functions

int	init_struct_env(t_env*, int, char**);
void init_struct_diff(t_difference*);
void result(t_difference*);


#endif // PROTOTYPES_H_INCLUDED

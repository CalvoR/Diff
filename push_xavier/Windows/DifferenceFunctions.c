#include "Prototypes.h"

int compare(char* str1, char* str2)
{
	int i = 0;

	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] != str2[i])
            return i;
		i++;
	}
	return -2;
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


ssize_t getline (char**line, size_t* line_length, FILE*file)
{
    ssize_t count_char = 0;
    int i=0;
    char current_char = ' ';
    *(line_length) = 0;

    if (file == NULL)
        return -1;

    do {                // read the file until the next '\n' to set the new string size
        if (current_char= fgetc(file), feof(file))
            return -1;
        count_char++;
    } while (current_char != '\n');

    fseek(file, (-1)*count_char-1, SEEK_CUR);

    printf("%d\n", count_char);

    free(*line);
    *line = (char*) malloc(sizeof(char)*count_char);

    printf("start\n");

     for (i=0; i<count_char; i++)
        (*line)[i] = fgetc(file);

     (*line)[count_char] = '\0';

    *(line_length) = count_char;

    return count_char;
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
        {
            read = getline(&diff->line_file1, &len, env->fd_file1);

            printf("result: %s\n ", diff->line_file1);
        }
		else
			diff->line_file1 = "\0";

		if (count < env->nbr_line_file2)
        {
			read2 = getline(&diff->line_file2, &len2, env->fd_file2);

			printf("result: %s\n ", diff->line_file2);
        }
		else
			diff->line_file2 = "\0";



		i = compare(diff->line_file1, diff->line_file2);

		if (i >= 0) {
			diff->state = 'c';
			diff = add_list(diff);
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


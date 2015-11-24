#include "Prototypes.h"

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

int find_difference(FILE* fd_src, FILE* fd_dest)
{
	char* read_src;
	char* read_dest;
	ssize_t read;
	ssize_t read2;
	size_t len = 0;
	size_t len2 = 0;
	int i = 0;

	read = getline(&read_src, &len, fd_src);


	if (read_src == NULL)
	{
		printf("erreur source");
		return -1;
	}

	read2 = getline(&read_dest, &len2, fd_dest);
	if (read_dest == NULL)
	{
		printf("erreur dest");
		return -1;
	}

	i = compare(read_src, read_dest);
	free(read_src);
	free(read_dest);
	return i;
}

int  cmpt_line(FILE* file)
{
	int c = 0;
	int nb_ligne_file = 0;

	while ((c = fgetc(file)) != EOF)
	{
		if (c == '\n')
			nb_ligne_file++;
	}
	return nb_ligne_file;
}

int main(int argc, char** argv)
{
	int i = 0;
	FILE* src;
	FILE* dest;
	int nb_ligne_src = 0;
	int nb_ligne_dest = 0;

	if (argc == 0)
		return 0;

	src = fopen(argv[1], "r");
	dest = fopen(argv[2], "r");

	if (src == NULL || dest == NULL)
		printf("erreur lecture de fichier\n");

	nb_ligne_src = cmpt_line(src);
	nb_ligne_dest = cmpt_line(dest);

	fclose(src);
	fclose(dest);

	src = fopen(argv[1], "r");
	dest = fopen(argv[2], "r");

	if (src == NULL || dest == NULL)
		printf("erreur lecture de fichier\n");

	if (nb_ligne_src > nb_ligne_dest)
	{
		while(nb_ligne_src > 0)
		{
			i = find_difference(src, dest);
			printf("%d\n", i);
			nb_ligne_src--;
		}
	}
	else
	{
		while(nb_ligne_dest > 0)
		{
			i = find_difference(src, dest);
			printf("%d\n", i);
			nb_ligne_dest--;
		}
	}
	fclose(src);
	fclose(dest);
	return 0;
}

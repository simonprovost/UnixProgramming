/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** get_alias.c
*/

#include "my.h"
#include "42sh.h"

char 		*get_file(char *path)
{
	int ret = 0;
	char *file = NULL;
	struct stat sb;
	int fd = open(path, O_RDONLY);

	if (fd == -1)
		return (NULL);
	stat(path, &sb);
	file = malloc(sizeof(char) * (long long int)sb.st_size + 1);
	ret = read(fd, file, sb.st_size);
	if (ret == -1 || ret == 0)
		return (NULL);
	file[ret] = 0;
	close(fd);
	return (file);
}

char **get_alias(char *line)
{
	char **alias = malloc(sizeof(char *) * 2);
	int i = 0;
	int a = 0;

	alias[0] = malloc(sizeof(char) * strlen(line) + 1);
	alias[1] = malloc(sizeof(char) * strlen(line) + 1);

	while (line[i] != ' ' && line[i] != '\t' && line[i]) {
		alias[0][i] = line[i];
		i++;
	}
	i++;
	while (line[i] != 0) {
		alias[1][a] = line[i];
		a++;
		i++;
	}
	printf("salut\n");
	return (alias);
}

char		**my_strtab_cat(char **cmd, char **str)
{
	char **nstr = malloc(sizeof(char *) * my_tablen(str)
	+ my_tablen(cmd) + 100);
	int i = 0;
	int b = 1;

	if (my_tablen(str) == 1)
		return (cmd);
	while (i < my_tablen(cmd)) {
		nstr[i] = cmd[i];
		i++;
	}
	while (b < my_tablen(str)) {
		nstr[i] = str[b];
		i++;
		b++;
	}
	nstr[i] = NULL;
	return (nstr);
}

char 		*get_str_alias(char **str)
{
	int i = 2;
	char *str_alias = NULL;

	while (str[i]) {
		str_alias = my_strcat(str_alias, str[i]);
		if (str[i + 1])
			str_alias = my_strcat(str_alias, " ");
		i++;
	}
	return (str_alias);
}
/*
** EPITECH PROJECT, 2017
** my_gnl
** File description:
** .h
*/

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int my_get_char(char *value_received, int fd)
{
	static int bytes = READ_SIZE;
	static int count_loop = 0;
	static char buffer[READ_SIZE];

	if (count_loop == 0 || count_loop >= bytes) {
		count_loop = 0;
		if ((bytes = read(fd, buffer, READ_SIZE)) == -1)
			return (0);
	}
	if (buffer[count_loop] == '\n' || bytes == 0) {
		*value_received = '\0';
		bytes == 0 ? count_loop = -1 : count_loop++;
	} else
		*value_received = buffer[count_loop++];
	return (bytes);
}

char *my_calloc_opti(int total, char user_choose)
{
	char *newt_str = NULL;

	if ((newt_str = malloc(sizeof(char) * total)) != NULL) {
		for (int i = 0 ; i < total ; i++)
			newt_str[i] = user_choose;
		return (newt_str);
	}
	return (NULL);
}

char *rlloc(char *src, int total)
{
	char *dest = NULL;

	if (src != NULL && total != 0) {
		dest = my_calloc_opti(total, '\0');
		for (int i = 0; src[i] != '\0' && dest != NULL ; i++)
			dest[i] = src[i];
		free(src);
	}
	return (dest);
}

char  *get_next_line(int fd)
{
	int i = 0;
	int bytes = 1;
	char *lin = NULL;
	int len = READ_SIZE;
	int lent = READ_SIZE + 2;

	lin = my_calloc_opti((READ_SIZE + 1), '\0');
	if (lin != NULL) {
		if ((bytes = my_get_char(&lin[i], fd)) == 0)
			return (NULL);
		while (lin[i] != '\0') {
			i % len == 0 ? (lin = rlloc(lin, i + lent), i++) : i++;
			bytes = my_get_char(&lin[i], fd);
		}
	}
	return (lin);
}
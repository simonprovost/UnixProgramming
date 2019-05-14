/*
** EPITECH PROJECT, 2018
** CPE_getnextline_2017
** File description:
** CPE_getnextline_2017 made by Sanchez Lucas
*/

#include "../../include/my.h"

char *get_next_line(FILE *stream)
{
	__ssize_t left = 0;
	size_t buff_size = 1;
	char *input = NULL;

	left = getline(&input, &buff_size, stream);
	if (left == -1) {
		input ? free(input) : 0;
		return (NULL);
	}
	if (input[left - 1] == 10)
		input[left - 1] = 0;
	return (input);
}

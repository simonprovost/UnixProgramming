/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"


int count_op(char *line)
{
	int op = 0;

	for (int i = 0 ; line[i] ; i++) {
		if (line[i] == SEMICOLON
		|| line[i] == SRL || line[i] == SRR
		|| line[i] == DRL || line[i] == DRR
		|| line [i] == PIPE)
			op++;
	}
	return (op);
}

char *load_op(char *line)
{
	int j = 0;
	int op_counter = count_op(line);

	if (op_counter == 0)
		return (NULL);
	char *op = malloc(sizeof(char) * op_counter + 1);
	for (int i = 0 ; line[i] ; i++) {
		line[i] == SEMICOLON ? op[j++] = SEMICOLON : 0;
		line[i] == SRL ? op[j++] = SRL : 0;
		line[i] == SRR ? op[j++] = SRR : 0;
		line[i] == PIPE ? op[j++] = PIPE : 0;
		if ((line[i] == SRL && line[i + 1] == SRL)
		|| (line[i] == SRR && line[i + 1] == SRR)) {
			(line[i++] == SRL) ? (op[j++] = 'L') : (op[j++] = 'R');
			continue;
		}
	}
	return ((op[j] = 0) ? op : op);
}
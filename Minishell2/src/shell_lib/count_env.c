/*
** EPITECH PROJECT, 2018
** null
** File description:
** nul*
*/

#include "minishell.h"

int count_env(char **env)
{
	int i = 0;

	for (; env[i] != NULL; i++);
	return (i);
}
/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** parser_and
*/

#include "42sh.h"

int check_double_and(btree_t *node, char *cmd, int i)
{
	if (cmd[i] == '&' && cmd[i - 1] == '&') {
		node->op = my_strdup("&&");
		cmd[i] = 0;
		cmd[i - 1] = 0;
		node->right = create_btree_node( \
				my_clean_str(node->cmd + i + 1), NULL);
		node->left = create_btree_node(my_clean_str(cmd), NULL);
		node->cmd = NULL;
		parse_cmd_for_and(node->left);
		parse_cmd_for_and(node->right);
		return (1);
	}
	return (0);
}

void recursivity_on_parsing_and(btree_t *node)
{
	if (!node->cmd) {
		parse_cmd_for_and(node->left);
		parse_cmd_for_and(node->right);
	}
}

int parse_cmd_for_and(btree_t *node)
{
	char *cmd = node->cmd;
	int len = my_strlen(node->cmd);

	recursivity_on_parsing_and(node);
	for (int i = len - 1; i >= 0; i--) {
		i = check_quotes(cmd, i);
		if (i == -1)
			return (1);
		if (check_double_and(node, cmd, i))
			break;
	}
	return (0);
}
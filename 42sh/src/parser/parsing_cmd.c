/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** parsing_cmd
*/

#include "42sh.h"

int check_semicolon(btree_t *node, char *cmd, int i)
{
	if (cmd[i] == ';') {
		cmd[i] = 0;
		node->right = create_btree_node( \
				my_clean_str(node->cmd + i + 1), NULL);
		node->left = create_btree_node(my_clean_str(cmd), NULL);
		node->cmd = NULL;
		node->op = my_strdup(";");
		parse_cmd_for_semicolon(node->left);
		parse_cmd_for_semicolon(node->right);
		return (1);
	}
	return (0);
}

int parse_cmd_for_semicolon(btree_t *node)
{
	char *cmd = node->cmd;
	int len = my_strlen(node->cmd);

	for (int i = len - 1; i >= 0; i--) {
		i = check_quotes(cmd, i);
		if (i == -1)
			return (1);
		if (check_semicolon(node, cmd, i))
			break;
	}
	return (0);
}

void free_tree(btree_t *tree)
{
	if (tree->left)
		free_tree(tree->left);
	if (tree->right)
		free_tree(tree->right);
	free_btree_node(tree);
	free(tree);
}

void parse_cmd(shell_t shell, char *cmd, int *ret_value)
{
	btree_t *node = NULL;

	parse_inhibitors(&cmd);
	node = create_btree_node(my_clean_str(cmd), NULL);
	free(cmd);
	if (check_bad_quotes(node->cmd)
	|| parse_env_variables(&(node->cmd), shell)
	|| parse_cmd_for_semicolon(node)
	|| parse_cmd_for_or(node)
	|| parse_cmd_for_and(node)
	|| parse_cmd_for_pipes_and_redirections(node)
	|| btree_error_handling(node, 0)
	|| replace_alias(node, shell.aliases)) {
		*ret_value = 1;
		free_tree(node);
		return;
	}
	exec_tree(node, shell, ret_value);
	free_tree(node);
}
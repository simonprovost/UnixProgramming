/*
** EPITECH PROJECT, 2017
** my strncmp
** File description:
** strncmp function
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
	int i = 0;
	int x = 0;

	if (n < 1)
		return (0);
	while (s1[i] == s2[i] && s1[i] != 0 && s2[i] != 0) {
		if (i == n - 1)
			break;
		i++;
	}
	x = s1[i] - s2[i];
	return (x);
}

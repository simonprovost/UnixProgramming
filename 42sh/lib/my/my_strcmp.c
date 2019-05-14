/*
** EPITECH PROJECT, 2017
** my strcmp
** File description:
** strcmp function
*/

int my_strcmp(char const *s1, char const *s2)
{
	int i = 0;
	int x = 0;

	if (!s1 || !s2)
		return (1);
	while (s1[i] == s2[i] && (s1[i] != 0 || s2[i] != 0))
		i++;
	x = s1[i] - s2[i];
	return (x);
}

# Minishell2
Minishell2, First year.

	Short resume of the mission
You have to program a UNIX command interpreter.
The interpreter is expected to display a prompt ( $> , for example) and then wait for you to write a command
line, which must be validated by a newline.
The prompt must be displayed again only after the command execution.
Only basic command lines are expected to executed; no pipes, redirections or any other advanced features.
The executables should be those found in the path, as indicated in the PATH variable.
If the executable cannot be found, you must display an error message and display the prompt again.
Errors must be dealt with and must display the appropriate message on the error output.
You must correctly handle the PATH and the environment (by copying and restoring the initial env).
You must implement the following builtins: cd, setenv, unsetenv, env, exit.
Your env builtin hasn’t to take any argument. In bonuses you can made unsetenv builtin to support the “*” wildcard.

Minishell2 -->
The goal of the project is to enrich your minishell1 project by adding semicolons (‘;’), pipes (‘|’), and the four
redirections (‘>’, ‘<’, ‘>>’, ‘<<’) management. The error handling must be perfect.

										BONUS
- Prompt + User ID
- Ctrl + C + Ré affichage du PATH
- Suppression de l'environnement managed.
- SH en couleur(prompt)
- Unsetenv *

										TESTS(Pourcentage
 - 91 % du projet est fonctionnel.
 - 90 % de la syntaxe d'Epitech est respecté.
 - 50 % de la mémoire est gerer.
 - 60/65 % de test fonctionnelles réalisé

 										BASH TESTS
 - 42 tests de differente commandes :
 	--> cd (cd ../ cd - cd [...])
	--> setenv/unsetenv
	--> env -i
	--> exit (exit -test / exit -77test / exit test / exit 42 / exit -42 [...])
	--> env
	--> error handling SH1 / SH2
  --> Simple PIPE
  --> Many PIPE
  --> BONUSES UNSETENV *

 

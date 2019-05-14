
# Epitech Computer Science School
<br/>
<p align="center">
<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/2/2d/Epitech.png/1598px-Epitech.png" width="250">
</p>
<br/>

# Grade Obtained
- Grade A

# National Ranking
- Third best project in the whole country.

# UnixProgramming
Unix project from computer science School

<a name="top"></a>

## Table of Contents 
- [UnixProgramming](#UnixProgramming): **C and Unix Basics**
    - Minishell1: First Shell.
    - MinishelL2: Second Shell.
    - 42sh: Third advanced Shell.

<a name="UnixProgramming"></a>

## [UnixProgramming](./): **C and Unix Basis**
<p align="right"><a href="#top">Back to top</a></p>

- [Minishell1](./Minishell1): **Reproduce a simple shell**
    - Description:
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
      Your env builtin hasn’t to take any argument. Your unsetenv builtin hasn’t to support the “*” wildcard.
      
 
- [Minishell2](./Minishell2): **Reproduce a shell**
    - Description:
      You have to program a UNIX command interpreter same as the first project but with extra. The goal of the project is to enrich your minishell1 project by adding semicolons (‘;’), pipes (‘|’), and the four
      redirections (‘>’, ‘<’, ‘>>’, ‘<<’) management. Here is a simple example of a command you must hanlde: `mkdir test ; cd test ; ls -a ; ls | cat | wc -c > tutu ; cat tutu`

- [42sh](./42sh): **Reproduce an advanced shell**
    - Description:
      You must write a Unix SHELL.
      The project consists of two sections:
      • a mandatory section, which MUST be completed: display a prompt, parse and execute some commands (see below),
      • an optional section, which will only be evaluated if the mandatory section is fully functionnal.
      Authorized functions: all functions included in the libC or the ncurses library.
      
    - Mandatory: 
      • spaces and tabs,
      • $PATH and environment,
      • errors and return value,
      • redirections (‘<’, ‘>’, ‘<<’ and ‘>>’),
      • pipes (‘|’),
      • builtins: cd, echo, exit, setenv, unsetenv,
      • separators: ‘;’, ‘&&’, ‘||’
      
    - Optional:
      • inhibitors (‘\’),
      • globbings (‘*’, ‘?’, ‘[’, ’]’),
      • job control (‘&’, fg),
      • backticks (“’),
      • parentheses (‘(’ and ‘)’),
      • variables (local and env),
      • special variables (term, precmd, cwdcmd, cwd, ignoreof for instance),
      • history (‘!’),
      • aliases,
      • line edition (multiline, dynamic rebinding, auto-completion dynamic,
      • scripting (a bit harsh though).
      

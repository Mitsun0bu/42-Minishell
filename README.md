# minishell

~~~ INTRO ~~~

This program has been made for the "minishell" 42 School project (2021).  
The goal of this project was to write a shell, taking bash as a reference.

~~~ TO RUN THE PROGRAM ~~~

1. Clone this repository in the folder of your choice using `git clone` command
2. Compile the program using `make` command
3. Launch the executable with `./minishell`

~~~ FEATURES ~~~

Minishelled has the following features :

- a command **history**   
- handling of **single and double quotes**, which prevent the shell from interpreting the meta-characters in the quoted sequence (except for $ in double quote)  
- handling of **redirections** (<, >, <<, >>)   
- handling of **pipes** (|)   
- handling of **envrionment variables** ($ followed by a sequence of characters)   
- handling of $?, which expands to the exit status of the most recently executed foreground pipeline   
- handling of CTRL+C, CTRL+D, CTRL+\, which behave like in bash   
- the following **built-ins** commands : **echo** (with option -n), **cd** (with only a relative or absolute path), **pwd** (with no options), **export** (with no options), **unset** (with no options), **env** (with no options), **exit** (with no options)

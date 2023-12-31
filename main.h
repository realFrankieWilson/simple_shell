#ifndef MAIN_H
#define MAIN_H


/************* STANDARD LIBRARY FUNCTIONS *************/
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>



/************* USER DEFINED MACROS ********************/
#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"
#define EOL '\0'
#define MINS '-'
#define PROMPT "$ "




/* Points to an array of pointers to strings called the "environment" */
extern char **environ;
/**
 * struct data - struct that contains all relevant data on runtime
 * @av: argument vector
 * @input: command line written by the user
 * @args: tokens of the command line
 * @status: last status of the shell
 * @counter: lines counter
 * @_environ: environment variable
 * @pid: process ID of the shell
 */

typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} shell_input;



/**
 * struct sep_list_s - single linked list
 * @separator: ; | &
 * @next: next node
 * Description: single linked list to store separators
 */

typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *next;
} sep_list;



/**
 * struct line_list_s - single linked list
 * @line: command line
 * @next: next node
 * Description: single linked list to store command lines
 */

typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;



/**
 * struct r_var_list - single linked list
 * @len_var: length of the variable
 * @val: value of the variable
 * @len_val: length of the value
 * @next: next node
 * Description: single linked list to store variables
 */

typedef struct r_var_list
{
	int len_var;
	char *val;
	int len_val;
	struct r_var_list *next;
} r_var;



/**
 * struct builtin_s - Builtin struct for command args.
 * @name: The name of the command builtin i.e cd, exit, env
 * @f: data type pointer function.
 */

typedef struct builtin_s
{
	char *name;
	int (*f)(shell_input *lineptr);
} builtin_t;



/* lists.c */
sep_list *add_sep_node_end(sep_list **, char);
void free_sep_list(sep_list **);
line_list *add_line_node_end(line_list **, char *);
void free_line_list(line_list **head);

/*lists2.c */
r_var *add_rvar_node(r_var **, int, char *, int);
void free_rvar_list(r_var **head);


/***************STRING FUNCIONS AND MEMCPY**************/
/* str1 */
char *str_cat(char *, const char *);
char *str_cpy(char *, char *);
int str_cmp(char *, char *);
/* str2.c */
char *str_dup(const char *);
int str_len(const char *);
int is_digit(const char *);
void rev_string(char *);

/* mem.c */
void mem_cpy(void *, const void *, unsigned int);
void *rea_lloc(void *, unsigned int, unsigned int);
char **rea_llocdp(char **, unsigned int, unsigned int);


/***************SYNTAX ChECK**************************/
/* check_syntax_error.c */
int repeated_char(char *, int);
int error_sep_op(char *, int, char);
int first_char(char *, int *);
void print_syntax_error(shell_input *, char *, int, int);
int check_syntax_error(shell_input *, char *);


/****************** LOOP AND OTHER REALATED FUNCTIONS *****************/
/* shell_loop.c */
void shell_loop(shell_input *);

/* read_line.c */
char *read_line(int *i_eof);

/* split.c */
char *swap_ch(char *, int);
void add_nodes(sep_list **, line_list **, char *);
void go_net(sep_list **, line_list **, shell_input *);
int split_cmd(shell_input *, char *);
char **split_line(char *input);

/* rep_var.c */
void check_env(r_var **, char *, shell_input *);
int check_vars(r_var **, char *, char *, shell_input *);
char *replaced_input(r_var **head, char *input, char *new_input, int nlen);
char *rep_var(char *, shell_input *);

/* get_line.c */
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);

/* exec_line */
int exec_line(shell_input *);

/* cmd_exec.c */
int is_cdir(char *path, int *i);
char *_which(char *cmd, char **_environ);
int is_executable(shell_input *);
int check_error_cmd(char *, shell_input *);
int cmd_exec(shell_input *);

/* env1.c */
char *_getenv(const char *name, char **_environ);
int _env(shell_input *);

/* env2.c */
char *copy_info(char *, char *);
void set_env(char *, char *, shell_input *);
int _setenv(shell_input *);
int _unsetenv(shell_input *);

/* cd.c */
void cd_dot(shell_input *);
void cd_to(shell_input *);
void cd_previous(shell_input *);
void cd_to_home(shell_input *);

/* cd_shell.c */
int cd_shell(shell_input *);

/* get_builtin */
int (*get_builtin(char *cmd))(shell_input *);

/* _exit.c */
int exit_shell(shell_input *);

/* stdlib.c */
int get_len(int);
char *ito_a(int);
int ato_i(char *);

/* error1.c */
char *strcat_cd(shell_input *, char *, char *, char *);
char *error_get_cd(shell_input *);
char *error_not_found(shell_input *);
char *error_exit_shell(shell_input *);

/*error2.c */
char *error_get_alias(char **);
char *error_env(shell_input *);
char *error_syntax(char **);
char *error_permission(char **);
char *error_path_126(shell_input *);
void set_data(shell_input *, char **);
void free_data(shell_input *);

/* get_error.c */
int get_error(shell_input *, int);

/* get_sigint.c */
void get_sigint(int sig);

/* help1.c */
void help_env(void);
void help_setenv(void);
void help_unsetenv(void);
void help_general(void);
void help_exit(void);

/* help2.c */
void help(void);
void help_alias(void);
void help_cd(void);

/* get_help.c */
int get_help(shell_input *);

#endif

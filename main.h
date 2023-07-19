#ifndef MAIN_H
#define MAIN_H

/********** c libraries ****************/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <wchar.h>
#include <signal.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>


/********** Defined macros *************/
#define TRM '\0'
#define PRMT "$ "


/*********** USER DEFINED PROTOTYPES FOR BASIC FUNCTIONS************/
int str_cmp(char *str1, char *str2);
int putchar_(char c);
char *str_dup(char *org);
void print_str(char *str, int new_l);
int print_num(int n);

/********** COMMANDS AND ARGUMENTS FUCNTIONS (cmds_and_arguments) **********/
void cmd_line(char *lineptr, size_t size, int cmd_ctr, char **av);
void create_ppid(char **buff_array, char *lineptr, int cmd_ctr, char **av);
char **token_access(char *lineptr, const char *delim, int token_count);
char **token_separator(int token_count, char *lineptr, const char *delim);
int count_token(char *lineptr, const char *delim);

/********** THE STD BUILTIN FUNCTIONS **********/
int std_built_ins(char **av, char *usr_in);
void exit_shell(char *usr_in);
void (*check_buitin(char *name_fun))(char *name_fun);
void env_shell(char *lineptr);
void cd_shell(char *lineptr);
void (*create)(char *);


/********** HELPER FUNCTIONS (general function)**********/
int str_len(char *str);
void twice_free(char **ptr);
void print_error(char *av, int cmd_count, char *cmd);
void error_executor(char *av, int cmd_count, char *tmp_cmd);

/********** PATH FUNCTION FINDER**********/
char *find_path_int(char *cmd);
int find_path_index(char *env);
char **str_separator(int i, char *str);
char *create_path(char *d_path, char *f_path);
char *search_diect(char **str_ptr, char *cmd);

/**
 * struct built_in -> the built in functions.
 * @built: The name of the build in command.
 * @f: A pointer to the right builtin function.
 */

typedef struct build_in
{
	char *execute;
	void (*f)(char *);
}build_in_t;

extern char **environ;

#endif /* MAIN_H */

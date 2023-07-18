#ifndef MAIN_H
#define MAIN_H

/********** c libraries ****************/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>



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
int std_built(char **av, char *usr_in);
void exit_shell(char *usr_in);
void (*check_buitin(char *name_fun))(char *name_fun);
void env_shell(char *lineptr);
void cd_shell(char *lineptr);

/********** HELPER FUNCTIONS **********/
int str_len(char *str);
void double_free(char **ptr);
void print_error(char *av, int cmd_count, char *cmd);
void error_executor(char *av, int cmd_count, *tmp_cmd);

#endif /* MAIN_H */

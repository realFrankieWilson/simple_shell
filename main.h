#ifndef MAIN_H
#define MAIN_H

/********** c libraries ****************/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/********** Defined macros *************/
#define TRM '\0'
#define PRMT "$ "


/*********** THE U_DEFINE PROTOTYPES ************/
int str_cmp(char *str1, char *str2);
int putchar_(char c);
char *str_dup(char *org);
void print_str(char *str, int new_l);

/******* COMMANDS AND ARGUMENTS FUCNTIONS (cmds_and_arguments) ********/
void cmd_line(char *lineptr, size_t size, int cmd_ctr, char **av);
void create_ppid(char **buff_array, char *lineptr, int cmd_ctr, char **av);
char **token_access(char *lineptr, const char *delim, int token_count);

#endif /* MAIN_H */